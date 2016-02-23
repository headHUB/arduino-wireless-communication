# Wireless Communication
This small script will show you how to use the NRF24L01+ module to send data wireless from one Arduino to another.

### Description

Here you will find 2 sketches. The first one, the transmitter sketch, will constantly send the values from the analog pins A0, A1 and A2 via the module to the other one.
Therefor the receiver sketch will catch the data and print it to the small display.
If you don't have such a display, don't worry, just delete the // from the **#define USE_SERIAL** line.
After this, you can use the serial monitor from the Arduino IDE to see incomming data.

###Hardware

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



For further instructions, please visit my blog:
https://deloarts.wordpress.com/2015/12/29/wireless-communication/