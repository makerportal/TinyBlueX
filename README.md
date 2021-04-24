# TinyBlueX
Arduino codes for TinyBlueX module that combines the ATtiny85 microcontroller and a CC2540/CC2541 Bluetooth Low Energy board

Get your TinyBlueX module: [XGMP3v3 Differential Pressure Sensor for Arduino and Raspberry Pi](https://makersportal.com/shop/xgmp3v3-differential-pressure-sensor-for-arduino-and-raspberry-pi) <br>
XGMP3v3 Sensor Datasheet: https://makersportal.com/s/XGMP3v3_Datasheet.pdf

### JUMP TO:
<a href="#wiring">- Wiring Diagram</a><br>
<a href="#examples">- XGMP3v3 Example with an Arduino Uno Board</a><br>
<a href="#calib">- Calibration with Arduino and Python3</a><br>
<a href="#pitot">- Arduino Pitot Tube Airspeed Sensor</a><br>

The XGMP3v3 library can be downloaded using git:

    git clone https://github.com/makerportal/xgmp3v3

<a id="wiring"></a>
# - Wiring Diagram -

The wiring between the XGMP3v3 and an Arduino Uno board is given below:
![TinyBlueX Arduino Wiring](/images/TinyBlueX_arduino_uno_wiring.jpg)
| Arduino Uno | TinyBlueX |
| --- | --- |
| 5V | VCC |
| GND | GND | 
| D10 | 1 |
| D11 | 5 |
| D12 | 6 |
| D13 | 7 |
