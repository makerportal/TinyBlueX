# TinyBlueX
Arduino codes for TinyBlueX module that combines the ATtiny85 microcontroller and a CC2540/CC2541 Bluetooth Low Energy board

Get your TinyBlueX module: [TinyBlueX Bluetooth Board](https://makersportal.com/shop/tinybluex-module-attiny85-ble) <br>

# 
### JUMP TO:
<a href="#wiring">- Wiring Diagram</a><br>
<a href="#examples">- TinyBlueX Example with an Arduino Uno Board</a><br>
<a href="#calib">- Calibration with Arduino and Python3</a><br>
<a href="#pitot">- Arduino Pitot Tube Airspeed Sensor</a><br>

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
