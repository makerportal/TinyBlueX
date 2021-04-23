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

int pin_states[5] = {0,0,0,0}; // pin states variable
String tot_val = ""; // storage variable for serial data
int start_offset = 2; // starting pin (#2 for ATtiny85 to avoid BLE conflict on 0/1)

void setup() {
  ble_device.begin(9600); // start BLE device
  delay(500); // wait until BLE device starts

  // Once the code is uploaded once, the below can be commented out
  // (the name change only needs to occur once)
  ble_device.println("AT+NAMETinyBlue"); // change device name
  delay(100); // wait for change
  ble_device.println("AT+RESET"); // reset module to enact name change
  delay(250); // wait for reset

  // Setting pins as outputs
  for (int ii = start_offset;ii<sizeof(pin_states)/sizeof(bool)+start_offset;ii++){
    pinMode(ii,OUTPUT); // set pins as outputs
  }
}

void loop() {
  char ser_byte = ble_device.read();
  if (int(ser_byte)!=-1){ // make sure it's a valid integer pin
    tot_val+=String(ser_byte); // if the input is over 1 character, this handles that
    tot_val.trim(); // trim any white space
    tot_val.replace(".",""); // the . and @ must be stripped from reading
    tot_val.replace("@",""); // to prevent errors (. and @ should not be used in comm.)
    if (ser_byte=='\n'){ // wait for newline
      int indx = String(tot_val).toInt()-start_offset; // index of pin to control
      pin_states[indx] = !bool(pin_states[indx]); // array pin state
      delay(50); // required delay before TX (after RX) - for stability
      digitalWrite(String(tot_val).toInt(),pin_states[indx]); // turn pin on/off
      ble_device.println(tot_val); // uncomment to print reading
      tot_val = ""; // clear serial input variable
    }
  }
}
