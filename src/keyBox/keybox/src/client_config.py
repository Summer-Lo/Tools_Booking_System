import psycopg2

# <------ MQTT Config ------>
# MQTT server
MQTTserver = "broker.hivemq.com"
#MQTTserver = "test.mosquitto.org"
port = 1883
recordTopic = "ICW503/record"
lockerTopic = "ICW503/key"
nodeRedTopic = "ICW503/info"

# PostgreSQL
database="booking"
user="postgres"
password="Sum2023mer!"
host="158.132.154.219"
port="5432"

# Locker config
lockerSize = 18
lockerData = ""

conn = psycopg2.connect(database=database, user=user, 
                        password=password, host=host, 
                        port=port)

locker_ID2Row = [1,1,1,1,1,1,\
                2,2,2,2,2,2,\
                3,3,3,3,3,3]

locker_ID2Col = [1,2,3,4,5,6,\
                1,2,3,4,5,6,\
                1,2,3,4,5,6]