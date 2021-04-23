/** BLE Chat between TinyBlueX and BLExAR iOS app
 * -- This code allows the BLExAR iOS app to send text to 
 * -- the TinyBlueX combined with the ATtiny85 microcontroller  
 * -- and Bluetooth Low Energy module (CC254x chip, also known as: 
 * -- HM-10, AT-09, MLT-BT05, JDY-08, etc.)
 *  
 *  by Joshua Hrisko, Maker Portal LLC (c) 2021
 *  
 */
#include <SoftwareSerial.h>

SoftwareSerial ble_device(0,1); // BLE TX-> ATtiny85 PB0, BLE RX-> ATtiny85 PB1

String tot_val = ""; // storage variable for serial data

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
  char ser_byte = ble_device.read();
  if (int(ser_byte)!=-1){ // make sure it's a valid character
      tot_val+=String(ser_byte); // if the input is over 1 character, this handles that
      tot_val.trim(); // trim any white space
      tot_val.replace(".",""); // the . and @ must be stripped from reading
      tot_val.replace("@",""); // to prevent errors (. and @ should not be used in comm.)
      if (ser_byte=='\n'){ // wait for newline
        delay(50);
        ble_device.println("Received: "+tot_val); // print RX reading
        tot_val = ""; // clear serial input variable
      }
    }
}
