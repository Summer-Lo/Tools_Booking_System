import paho.mqtt.client as mqtt
import MQTTsetup
import client_config as hc
import json
import time
import numpy
import py2pg as pg

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
        if(str(type) == "Locker" and str(status) == "borrow"):
            ## Get the index of locker which contain the reqested product
            hc.lockerData = pg.get_data()          # Update data in database
            if(equ_id in hc.lockerData["equipment_id"].values):
                equRes = hc.lockerData["equipment_id"] == equ_id
                #print(equRes)
                equResInx = []
                for i in range(len(equRes)):
                    if(equRes[i] == True and hc.lockerData["status"][i] == True):   # Check whether equ_index existing in locker and status is True
                        #print(hc.lockerData["id"])
                        print(i)
                        equResInx.append(i) # Store locker no (Starting from 0 - 63)
                if(equResInx):
                    print("The following locker is available for this idem: ",equResInx) 
                    borrowLockerNum = equResInx[0] + 1
                    status = False
                    pg.update_status_data(borrowLockerNum, maker_id, status)
                    mqtt_msg = MQTTsetup.mqtt_genMsg_open(hc.locker_ID2Row[borrowLockerNum-1],hc.locker_ID2Col[borrowLockerNum-1])
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.lockerTopic,mqtt_msg)
                    mqttNodeRed_msg = MQTTsetup.mqtt_genMsg_nodered_locker(borrowLockerNum,hc.locker_ID2Row[borrowLockerNum-1],hc.locker_ID2Col[borrowLockerNum-1])
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.nodeRedTopic,mqttNodeRed_msg)
                else:
                    print("This item is unavailable now!")
            else:
                print("This item not abailable in the locker")
        ## <--------------- START Returning --------------->
        elif(str(type) == "Locker" and str(status) == "return"):
            hc.lockerData = pg.get_data()          # Update data in database
            if(equ_id in hc.lockerData["equipment_id"].values and maker_id in hc.lockerData["borrower_id"].values):
                equRes = hc.lockerData["equipment_id"] == equ_id
                makerRes = hc.lockerData["borrower_id"] == maker_id
                retResInx = []
                for i in range(len(equRes)):
                    if(equRes[i] == True and makerRes[i] == True and hc.lockerData["status"][i] == False):
                        print(i)
                        retResInx.append(i)
                if(retResInx):
                    print(f"The following locker is borrowed by the maker {maker_id}: ",retResInx) 
                    returnLockerNum = retResInx[0] + 1
                    status = True
                    print(f"The Locker {returnLockerNum} is returned by {maker_id}")
                    mqtt_msg = MQTTsetup.mqtt_genMsg_open(hc.locker_ID2Row[returnLockerNum-1],hc.locker_ID2Col[returnLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.lockerTopic,mqtt_msg)
                    mqttNodeRed_msg = MQTTsetup.mqtt_genMsg_nodered_locker(returnLockerNum,hc.locker_ID2Row[returnLockerNum-1],hc.locker_ID2Col[returnLockerNum-1])
                    #print(hc.locker_ID2Col[borrowLockerNum-1])
                    MQTTsetup.mqtt_publish_msg(client,hc.nodeRedTopic,mqttNodeRed_msg)
                else:
                    print(f"Maker {maker_id} has no borrowing record in IoT Station")
            else:
                print("This item not abailable in the locker")
        elif(str(type) == "Locker" and str(status) == "complete"):
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

    
