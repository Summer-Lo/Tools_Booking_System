import paho.mqtt.client as mqtt
import time
import json
import client_config as hc


def on_connect(client, userdata, flags, rc):
    global connection
    if(rc == 0):
        print("Connected with result code "+str(rc))
        conenction = 1
        client.subscribe(hc.recordTopic)
    else:
        print(f"Failed to connect, return code {rc}\n",rc)
        connection = 0
        
def on_disconnect(client,userdata,rc):
    global connection
    print("MQTT client disconnected!")
    connection = 0

def mqtt_client_setup(client):
    client.on_connect = on_connect
    client.on_disconnect = on_disconnect
    client.connect(hc.MQTTserver,1883,60)
    return client

def mqtt_publish_msg(client,topic,mqtt_message):
    result = client.publish(topic, mqtt_message)
    status = result[0]
    if status == 0:
        print(f"Send `{mqtt_message}` to topic `{topic}`")
    else:
        print(f"Failed to send message to topic {topic}")

def mqtt_genMsg_open(row,col):
    
    mqtt_message = {"Type" : "IoT_station"\
                    , "Row" : int(row)\
                    , "Col" : int(col)\
                    , "Status" : "Open" }
    mqtt_message = json.dumps(mqtt_message)  
    #print(type(mqtt_message))
    return mqtt_message 

def mqtt_genMsg_nodered_locker(locker_id,row,col):
    
    mqtt_message = {"Type" : "Info"\
                    , "ID" : int(locker_id)\
                    , "Row" : int(row)\
                    , "Col" : int(col)}
    mqtt_message = json.dumps(mqtt_message)  
    #print(type(mqtt_message))
    return mqtt_message 