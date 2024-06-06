
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <HardwareSerial.h>
#include "ArduinoJson.h"
#include <stdio.h>

#define TX1 17
#define RX1 16

#define LED_PIN 8

// Replace the next variables with your SSID/Password combination
const char* ssid = "IE_Maker_User";
const char* password = "summer2023";

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = "broker.hivemq.com";
const char* client_id = "SummerClientkey12122";
const char* subTopic = "ICW503/key";

// UART message define


// Wifi config
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
bool readStatus = 0;

HardwareSerial SerialPort(1);

void setup() {
  Serial.begin(115200);
  SerialPort.begin(9600,SERIAL_8N1,RX1,TX1);
  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  //status = bme.begin();  
  //pinMode(LED_PIN,OUTPUT);
  //digitalWrite(LED_PIN,LOW);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);  
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  //SerialPort.println();
  //SerialPort.print("Connecting to ");
  //SerialPort.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //SerialPort.print(".");
  }
  //digitalWrite(LED_PIN,HIGH);

  //SerialPort.println("");
  //SerialPort.println("WiFi connected");
  //SerialPort.println("IP address: ");
  //SerialPort.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  //SerialPort.print("Message arrived on topic: ");
  //SerialPort.print(topic);
  //SerialPort.print(". Message: ");
  String messageTemp = "";
  
  for (int i = 0; i < length; i++) {
    //SerialPort.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  //SerialPort.println();

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == String(subTopic)) {
    //SerialPort.println("Same Topic");
    StaticJsonDocument<200> jsonBuffer;
    // parse the JSON message
    DeserializationError error = deserializeJson(jsonBuffer, messageTemp);
    // Test if parsing succeeds.
    if (error) {
      //SerialPort.print(F("deserializeJson() failed: "));
      //SerialPort.println(error.f_str());
      return;
    }
    String type = jsonBuffer["Type"];         //Get msg type value
    int key = jsonBuffer["ID"];                  //Get msg value of row
    String status = jsonBuffer["Status"];     //Get msg status

    if(type == "Key" and status == "test")
    {
      uint8_t bytes3_hex[18] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12};
      uint8_t bytes5_hex[18] = {0x9B, 0x98, 0x99, 0x9E, 0x9F, 0x9C, 0x9D, 0x92, 0x93, 0x90, 0x91, 0x96, 0x97, 0x94, 0x95, 0x8A, 0x8B, 0x88};
      uint8_t bytes1st = 0x8A;                  // Starting Byte
      uint8_t bytes2nd = 0x01;                  // Starting Byte
      uint8_t bytes3rd = bytes3_hex[key-1];
      uint8_t bytes4th = 0x11;                  // Data Byte 2nd
      uint8_t bytes5th = bytes5_hex[key-1];
    
      SerialPort.write(bytes1st);
      SerialPort.write(bytes2nd);
      SerialPort.write(bytes3rd);
      SerialPort.write(bytes4th);
      SerialPort.write(bytes5th);
      //SerialPort.println();

    }

    if(type == "Key" and status == "open")
    {
      uint8_t bytes3_hex[18] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12};
      uint8_t bytes5_hex[18] = {0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xB8, 0xB9, 0xBA};
      uint8_t bytes1st = 0x9A;                  // Starting Byte
      uint8_t bytes2nd = 0x01;                  // Starting Byte
      uint8_t bytes3rd = bytes3_hex[key-1];
      uint8_t bytes4th = 0x33;                  // Data Byte 2nd
      uint8_t bytes5th = bytes5_hex[key-1];
    
      SerialPort.write(bytes1st);
      SerialPort.write(bytes2nd);
      SerialPort.write(bytes3rd);
      SerialPort.write(bytes4th);
      SerialPort.write(bytes5th);
      //SerialPort.println();

    }

    if(type == "Key" and status == "close")
    {
      uint8_t bytes3_hex[18] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12};
      uint8_t bytes5_hex[18] = {0xA8, 0xAB, 0xAA, 0xAD, 0xAC, 0xAF, 0xAE, 0xA1, 0xA0, 0xA3, 0xA2, 0xA5, 0xA4, 0xA7, 0xA6, 0xB9, 0xB8, 0xBB};
      uint8_t bytes1st = 0x9B;                  // Starting Byte
      uint8_t bytes2nd = 0x01;                  // Starting Byte
      uint8_t bytes3rd = bytes3_hex[key-1];
      uint8_t bytes4th = 0x33;                  // Data Byte 2nd
      uint8_t bytes5th = bytes5_hex[key-1];
    
      SerialPort.write(bytes1st);
      SerialPort.write(bytes2nd);
      SerialPort.write(bytes3rd);
      SerialPort.write(bytes4th);
      SerialPort.write(bytes5th);
      //SerialPort.println();

    }

    if(type == "Key" and status == "read")
    {
      uint8_t bytes3_hex[18] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12};
      uint8_t bytes5_hex[18] = {0xB3, 0xB0, 0xB1, 0xB6, 0xB7, 0xB4, 0xB5, 0xBA, 0xBB, 0xB8, 0xB9, 0xBE, 0xBF, 0xBC, 0xBD, 0xA2, 0xA3, 0xA0};
      uint8_t bytes1st = 0x80;                  // Starting Byte
      uint8_t bytes2nd = 0x01;                  // Starting Byte
      uint8_t bytes3rd = bytes3_hex[key-1];
      uint8_t bytes4th = 0x33;                  // Data Byte 2nd
      uint8_t bytes5th = bytes5_hex[key-1];
    
      SerialPort.write(bytes1st);
      SerialPort.write(bytes2nd);
      SerialPort.write(bytes3rd);
      SerialPort.write(bytes4th);
      SerialPort.write(bytes5th);
      //SerialPort.println();
      readStatus = 1;
      
      //Clear the buffer
      jsonBuffer.clear();  
      delay(100);
    }
  }
}

int uart_Tx(int byteRow, int byteCol){
  int num_key[10] = {0,1,2,3,4,5,6,7,8,9}; // Num_key = num of row/col - 1
  uint8_t num_hex[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};
  unsigned char bytesSent = 0xFFFF3138;  //send the string "hello" and return the length of the string.
  uint8_t bytes1st = 0xFF;                  // Starting Byte
  uint8_t bytes2nd = 0xFF;                  // Starting Byte
  uint8_t bytes3rd = num_hex[byteRow-1];    // Data Byte 1st
  uint8_t bytes4th = num_hex[byteCol-1];    // Data Byte 2nd
  uint8_t bytes5th = 0xAA;                  // Ending Byte

  SerialPort.write(bytes1st);
  SerialPort.write(bytes2nd);
  SerialPort.write(bytes3rd);
  SerialPort.write(bytes4th);
  SerialPort.write(bytes5th);
  SerialPort.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    //SerialPort.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(client_id)) {
      //SerialPort.println("connected");
      // Subscribe
      client.subscribe(subTopic);
    } else {
      //SerialPort.print("failed, rc=");
      //SerialPort.print(client.state());
      //SerialPort.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  /*
  if(readStatus == 1){
    uint8_t msg_hex[10];
    int index = 0;
    if (SerialPort.available()) {
    // Read the incoming byte
    int incomingByte = SerialPort.read();
      if(readStatus == 1){
        msg_hex[index++] = incomingByte;
      }
      // Print the byte in hexadecimal format
      Serial.print("Received byte: 0x");
      if (incomingByte < 0x10) {
        // Add a leading zero for single digit hex values
        Serial.print("0");
      }
      Serial.println(msg_hex[index-1], HEX);
      if(index == 10){    // Exit the looping
        index = 0;
        readStatus = 0;
      }
    }
  }*/
}
