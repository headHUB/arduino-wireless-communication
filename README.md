# Arduino: Wireless Communication

## 1 Description

This small script will show you how to use the NRF24L01+ module to send data wireless from one Arduino to another.

Here you will find 2 sketches. The first one, the transmitter sketch, will constantly send the values from the analog pins A0, A1 and A2 via the module to the other one.
Therefor the receiver sketch will catch the data and print it to the small display.
If you don't have such a display, don't worry, just delete the // from the **#define USE_SERIAL** line.
After this, you can use the serial monitor from the Arduino IDE to see incomming data.

### 1.1 Hardware

**Required components:**
- Arduino UNO or Nano (2 pcs)
- NRF24L01+ module (2 pcs)
- 0.96" I2C Display module (1 pcs)
- Jumper wires

**Connection for the NRF24L01+:**

Arduino Pin | NRF24L01+ Pin
------------|--------------
9			| CE
10			| CSN
11			| MOSI
12			| MISO
13			| SCK
3V3			| VCC
GND			| GND

**Connection for the display:**

Arduino Pin | Display Pin
------------|------------
A4			| SDA
A5			| SCL
5V			| VCC
GND			| GND

For a more detailed information visit my website:

- [English](http://deloarts.com/en/scripts/arduino/wireless-communication)
- [German](http://deloarts.com/de/scripts/arduino/wireless-communication)

## 2 License

This project is licensed under the GNU GPLv3 open source license. Thus anybody is allowed to copy and modify the source code, provided all changes are open source too and the author is in knowledge of all done changes. This can happen either via eMail or directly on GitHub, in other words at this repository.

## 3 Disclaimer

I am not responsible for anything in conjunction with this project, including bugs, failure, fire, harm of equipment and harm of persons. Reasonably foreseeable misapplication:

- Bug in the code
- Failure of used parts due to a bug in the code or a wrong wiring diagram, including a wrong design.
- Fire due to a wrong wiring diagram, including a wrong design.
- Harm of equipment, meaning third party parts (cameras, flashes, etc.) due to a bug in the code or a wrong wiring diagram, including a wrong design.
- Harm of persons due to any failure of the system, a wrong wiring diagram or a wrong behaviour.

**It is your own responsibility to use these contents**. Be careful, this project includes lethal electrical voltage. Put yourself in knowledge about the risks before you start with this project.

