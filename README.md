# TinyBlueX
Arduino codes for TinyBlueX module that combines the ATtiny85 microcontroller and a CC2540/CC2541 Bluetooth Low Energy board

Get your TinyBlueX module: [TinyBlueX Bluetooth Board](https://makersportal.com/shop/tinybluex-module-attiny85-ble) <br>

# 
### JUMP TO:
<a href="#wiring">- Wiring Diagram</a><br>
<a href="#example">- TinyBlueX BLE Chat with the BLExAR iOS App</a><br>
<a href="#control">- Control Code for TinyBlueX</a><br>
<a href="#data">- Sending Temperature Data From TinyBlueX to iOS Device</a><br>

The TinyBlueX library can be downloaded using git:

    git clone https://github.com/makerportal/TinyBlueX

<a id="wiring"></a>
# - Wiring Diagram for Uploading Code to the TinyBlueX-

The wiring between the TinyBlueX and Arduino Uno board required for uploading code to the TinyBlueX is given below:
![TinyBlueX Arduino Wiring](/images/TinyBlueX_arduino_uno_wiring.jpg)
| Arduino Uno | TinyBlueX |
| --- | --- |
| 5V | VCC |
| GND | GND | 
| D10 | 1 |
| D11 | 5 |
| D12 | 6 |
| D13 | 7 |

<a id="example"></a>
# - TinyBlueX BLE Chat with the BLExAR iOS App -
The TinyBlueX can be connected to the BLExAR iOS app. The code titled:
- 'BLE_chat.ino'

receives text sent from the iOS device and sends it back to the iOS device. It is the simplest example that demonstrates the functionality of the TinyBlueX board.

![TinyBlueX BLE Chat](/images/tinybluex_BLE_chat.jpeg)

<a id="control"></a>
# - Control Code for TinyBlueX -
Use code: 
- BLExAR_control.ino

to turn an RGB LED wired to pins 2,3,7 on and off using the BLExAR app. The pins can be controlled using BLExAR pins 2,3,4.

![TinyBlueX BLE Control](/images/TinyBlueX_w_BLExAR_app.JPG)

<a id="data"></a>
# - Sending Temperature Data From TinyBlueX to iOS Device -
Reading DHT22 temperature and humidity and sending the values to the iOS device via BLExAR.

- To be updated
