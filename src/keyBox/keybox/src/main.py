import paho.mqtt.client as mqtt
import MQTTsetup
import client_config as hc
import json
import time
import numpy
import py2pg as pg
import threading

def closeLocker(ID):
    mqtt_msg = MQTTsetup.mqtt_genMsg_close(int(ID))
    MQTTsetup.mqtt_publish_msg(client,hc.lockerTopic,mqtt_msg)
    print(f"Key#{ID}  closed!")

num_packet = 0
returnLockerNum = 0

def on_message(client, userdata, msg):
    global num_packet, returnLockerNum
    print(f"Message received from topic {msg.topic} num={num_packet}", msg.payload.decode())
    num_packet += 1
    if(str(msg.topic) == hc.recordTopic):
        data = json.loads(msg.payload.decode())
        type = data["Type"]
        equ_id = data["Equ_id"]
        #qty = data["Qty"]
        maker_id = data["Maker_id"]
        status = data["Status"]
        #print(hc.lockerData["equipment_id"] == equ_id)
        ## <--------------- START Borrowing --------------->
        if(str(type) == "Key" and str(status) == "borrow"):
            ## Get the index of locker which contain the reqested product
            hc.lockerData = pg.get_data()          # Update data in database
            print(f"Equipment ID: {equ_id}")
            if(equ_id in hc.lockerData["equipment_id"].values):
                equRes = hc.lockerData.index[hc.lockerData["equipment_id"] == int(equ_id)].tolist()
                #print(hc.lockerData)
                #print(hc.lockerData["equipment_id"])
                print(f"equRes: {equRes}")
                print(hc.lockerData["status"][equRes])
                if(hc.lockerData["status"][equRes].values == True):   # Check whether equ_index existing in locker and status is True
                    print("The following Key is available for this idem: ",equRes) 
                    borrowLockerNum = equRes[0]
                    status = False
                    pg.update_status_data(int(borrowLockerNum)+1, maker_id, status)
                    mqtt_msg = MQTTsetup.mqtt_genMsg_open(int(borrowLockerNum)+1)
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.lockerTopic,mqtt_msg)
                    mqttNodeRed_msg = MQTTsetup.mqtt_genMsg_nodered_locker(int(borrowLockerNum)+1,hc.locker_ID2Row[borrowLockerNum],hc.locker_ID2Col[borrowLockerNum])
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.nodeRedTopic,mqttNodeRed_msg)
                    timer = threading.Timer(10,closeLocker,(int(borrowLockerNum)+1,))
                    timer.start()
                else:
                    print("This item is unavailable now!")
            else:
                print("This item not abailable in the locker")
        ## <--------------- START Returning --------------->
        elif(str(type) == "Key" and str(status) == "info"):
            hc.lockerData = pg.get_data()          # Update data in database
            if(equ_id in hc.lockerData["equipment_id"].values):
                equRes = hc.lockerData.index[hc.lockerData["equipment_id"] == int(equ_id)].tolist()
                if(hc.lockerData["status"][equRes].values == False):   # Check whether equ_index existing in locker and status is True
                    print("The following Key is available for this idem: ",equRes)
                    returnLockerNum = equRes[0]
                    mqttNodeRed_msg = MQTTsetup.mqtt_genMsg_nodered_locker(int(returnLockerNum)+1,hc.locker_ID2Row[returnLockerNum],hc.locker_ID2Col[returnLockerNum])
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.nodeRedTopic,mqttNodeRed_msg)
        elif(str(type) == "Key" and str(status) == "return"):
            hc.lockerData = pg.get_data()          # Update data in database
            print(f"Equipment ID: {equ_id}")
            if(equ_id in hc.lockerData["equipment_id"].values):
                equRes = hc.lockerData.index[hc.lockerData["equipment_id"] == int(equ_id)].tolist()
                #print(hc.lockerData)
                #print(hc.lockerData["equipment_id"])
                print(f"equRes: {equRes}")
                print(hc.lockerData["status"][equRes])
                if(hc.lockerData["status"][equRes].values == False):   # Check whether equ_index existing in locker and status is True
                    print("The following Key is available for return this idem: ",equRes) 
                    returnLockerNum = equRes[0]
                    status = True
                    pg.update_status_data(int(returnLockerNum)+1, "", status)
                    print(f"The Key#{returnLockerNum} is returned by {maker_id}")
                    mqtt_msg = MQTTsetup.mqtt_genMsg_open(int(returnLockerNum)+1)
                    MQTTsetup.mqtt_publish_msg(client,hc.lockerTopic,mqtt_msg)
                    mqttNodeRed_msg = MQTTsetup.mqtt_genMsg_nodered_locker(int(returnLockerNum)+1,hc.locker_ID2Row[returnLockerNum],hc.locker_ID2Col[returnLockerNum])
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.nodeRedTopic,mqttNodeRed_msg)
                    timer = threading.Timer(10,closeLocker,(int(returnLockerNum)+1,))
                    timer.start()
                else:
                    print(f"Maker {maker_id} has no borrowing record in IoT Station")
            else:
                print("This item not abailable in the locker")
        elif(str(type) == "Key" and str(status) == "complete"):
            status = True
            pg.update_status_data(returnLockerNum, "", status)



#testing
if __name__== '__main__':
    try:
        hc.lockerData = pg.get_data()
        #MQTT server Setup
        client = mqtt.Client()
        client.on_message = on_message
        client = MQTTsetup.mqtt_client_setup(client)
        client.loop_start()
        while True:
            pass
    except EOFError:
        print('Hello user it is EOF exception, please modify program and run me again')
    except KeyboardInterrupt:
        hc.conn.close()

    
