#include <HardwareSerial.h>
HardwareSerial SerialPort(1);
#define TX1 17
#define RX1 16

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialPort.begin(9600,SERIAL_8N1,RX1,TX1);
  //Serial.begin(9600);
  //Serial.println("Start UART communication!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Data definition: Manufacturer data ; Three bytes data ; Version number
  // |MD|MD|1st|2nd|3rd|ver|sub-ver|
  // |FF|FF|ROW|CLOUMN|CHECKSUM|VERSION|SUBVERSION
  // 0xFFFF3138003031
  /*
  unsigned char bytesSent = 0xFFFF3138;  //send the string "hello" and return the length of the string.
  unsigned char bytes1st = 0xFF;
  unsigned char bytes2nd = 0xFF;
  unsigned char bytes3rd = 0x31;
  unsigned char bytes4th = 0x38;

  unsigned char checksum = 0x31;
  checksum+=bytes1st;
  checksum+=bytes2nd;
  checksum+=bytes3rd;
  checksum+=bytes4th;
  SerialPort.write(bytes1st);
  SerialPort.write(bytes2nd);
  SerialPort.write(bytes3rd);
  SerialPort.write(bytes4th);

  delay(1000);  
  */
  //bytesSent = SerialPort.print("BYE");  //send the string "hello" and return the length of the string.
  //delay(200);  
  if (SerialPort.available()) {
    // Read the incoming byte
    int incomingByte = SerialPort.read();

    // Print the byte in hexadecimal format
    Serial.print("Received byte: 0x");
    if (incomingByte < 0x10) {
      // Add a leading zero for single digit hex values
      Serial.print("0");
    }
    Serial.println(incomingByte, HEX);
  }
  
}
