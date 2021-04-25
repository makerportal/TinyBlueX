/** Control Code for TinyBlueX and BLExAR iOS app
 * -- This code allows the BLExAR iOS app to control the pins on
 * -- the TinyBlueX combined ATtiny85 microcontroller and Bluetooth
 * -- Low Energy module (CC254x chip also known as:
 * -- HM-10, AT-09, MLT-BT05, JDY-08, etc.)
 *  
 *  by Joshua Hrisko, Maker Portal LLC (c) 2021
 *  
 */
#include <SoftwareSerial.h>

SoftwareSerial ble_device(0,1); // BLE TX-> ATtiny85 PB0, BLE RX-> ATtiny85 PB1

String strglob= "";
String pin_num_char = "";
int pin_num = 255;
bool analog_bool = false;
bool digital_bool = false;

void setup() {
  ble_device.begin(9600); // start BLE device
  delay(500); // wait until BLE device starts

  // Once the code is uploaded once, the below can be commented out
  // (the name change only needs to occur once)
  ble_device.println("AT+NAMETinyBlue"); // change device name
  delay(250); // wait for change
  ble_device.println("AT+RESET"); // reset module to enact name change
  delay(500); // wait for reset
}

void loop() {
  char ble_char = ble_device.read();
  if (int(ble_char)!=-1){ // make sure it's a valid character  
    if (ble_char == '\n'){
      if (analog_bool){
        pinMode(pin_num,OUTPUT);
        delay(50);
        analogWrite(pin_num,strglob.toInt());
        analog_bool = false;
        pin_num = 255;
      } else if (digital_bool){
        pinMode(pin_num,OUTPUT);
        delay(50);
        if (strglob == "1"){
          digitalWrite(pin_num,HIGH);
        } else if (strglob == "0"){
          digitalWrite(pin_num,LOW);
          pinMode(pin_num,INPUT);
          delay(50);
        }
        digital_bool = false;
        pin_num = 255;
      }
      pin_num = 255;
      strglob = "";
    } else {
      if (analog_bool == false and digital_bool == false) {
        if (ble_char == 'D'){
          digital_bool = true;
        } else if (ble_char == 'A'){
          analog_bool = true;
        } else {
        }
      } else{
        if (pin_num == 255){
          if (ble_char != 'e'){
            pin_num_char += ble_char;
          } else if (ble_char == 'e'){
            pin_num = (String(pin_num_char).toInt());
            pin_num_char = "";
          }
        } else {
          if (int(ble_char)!=-1 && ble_char!='.' && ble_char!='@' && ble_char!=' ' && ble_char!='\r' && ble_char!='\n' && ble_char!='\0'){
            strglob += String(ble_char);    
          }
        }
      }
    }
  }
  if ((ble_char)!=-1 && ble_char!=' ' && ble_char!='\n' && ble_char!='\r' && ble_char!='@' && ble_char!='.' && ble_char!='\0'){
    delay(50);
//    ble_device.println(ble_char); // uncomment to send back to BLExAR
  }
}
