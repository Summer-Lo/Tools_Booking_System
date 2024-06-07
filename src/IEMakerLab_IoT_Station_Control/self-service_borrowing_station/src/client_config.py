import psycopg2

# <------ MQTT Config ------>
# MQTT server
MQTTserver = "broker.hivemq.com"
#MQTTserver = "test.mosquitto.org"
port = 1883
recordTopic = "ICW503/record"
lockerTopic = "ICW503/IoT"
nodeRedTopic = "ICW503/info"

# PostgreSQL
database="booking"
user="postgres"
password="Sum2023mer!"
host="158.132.154.219"
port="5432"

# Locker config
lockerSize = 64
lockerData = ""

conn = psycopg2.connect(database=database, user=user, 
                        password=password, host=host, 
                        port=port)

locker_ID2Row = [1,1,1,1,1,1,1,1,\
                2,2,2,2,2,2,2,2,\
                3,3,3,3,3,3,3,3,\
                4,4,4,4,4,4,4,4,\
                5,5,5,5,5,5,5,5,\
                6,6,6,6,6,6,6,6,\
                7,7,7,7,\
                8,8,8,8,\
                9,9,9,9,\
                10,10,10,10]

locker_ID2Col = [1,2,3,4,5,6,7,8,\
                1,2,3,4,5,6,7,8,\
                1,2,3,4,5,6,7,8,\
                1,2,3,4,5,6,7,8,\
                1,2,3,4,5,6,7,8,\
                1,2,3,4,5,6,7,8,\
                5,6,7,8,
                5,6,7,8,
                5,6,7,8,
                5,6,7,8,]