// #####################################################################################################################
// ######################################### WIRELESS COM RECEIVER #####################################################
// ##################################################################################################################### 
/*
	This is the receiver.
	It constantly waits for a message from the transmitter.
*/
//#define USE_SERIAL
// Get neccessary header files for NRF24
#include <SPI.h>
#include "RF24.h"
// and for the little display
#ifndef USE_SERIAL
#include <OLED_I2C_128x64_Monochrome.h>
#include <Wire.h>
#endif

// Define the radio addresses (must be the same on both devices!)
byte addresses[][6] = {"DevRX", "DevTX"};

// Setup NRF24 to SPI BUS and the pins 9 and 10 (Check wiring on my blog!)
RF24 radio(9, 10);

// Using a struct to "store" the incomming data
struct dataStruct
{
	word Sensor1, Sensor2, Sensor3;
} Sensor;

void setup()
{
	#ifndef USE_SERIAL
	// Initialize the display
	lcd.initialize();
	lcd.rotateDisplay180(); // I need to rotate the screen, maybe you don't need this line ...
	#endif

	#ifdef USE_SERIAL
	Serial.begin(9600);
	#endif

	// Initialize the NRF24
	radio.begin();
	// Set the PA level to high, so the message can be sent over long distances.
	radio.setPALevel(RF24_PA_HIGH);
	/* 
		Other levels:
			- RF24_PA_MIN
			- RF24_PA_LOW
			- RF24_PA_HIGH
			- RF24_PA_MAX
	*/
	// Open RX & TX (you have to switch the values 0,1 on the devices!)
	radio.openWritingPipe(addresses[1]);
	radio.openReadingPipe(1, addresses[0]);

	#ifndef USE_SERIAL
	// Print a message on the display ...
	lcd.clearDisplay();
	lcd.printString("Sensor 1: ", 0, 2);
	lcd.printString("Sensor 2: ", 0, 4);
	lcd.printString("Sensor 3: ", 0, 6);
	#endif

	#ifdef USE_SERIAL
	// ... or to the serial port
	Serial.print("Ready for receiving data.");
	#endif

	radio.startListening();
}

void loop()
{
	while(radio.available())
	{
		// Get the data from the NRF24
		radio.read(&Sensor, sizeof(Sensor));
		
		#ifndef USE_SERIAL
		// and print it to the display ...
		lcd.printString("    ", 11, 2);
		lcd.printNumber(long(Sensor.Sensor1), 11, 2);
		lcd.printString("    ", 11, 4);
		lcd.printNumber(long(Sensor.Sensor2), 11, 4);
		lcd.printString("    ", 11, 6);
		lcd.printNumber(long(Sensor.Sensor3), 11, 6);
		#endif

		#ifdef USE_SERIAL
		// ... or to the serial port
		Serial.print("Sensor 1: "); Serial.println(Sensor.Sensor1);
		Serial.print("Sensor 2: "); Serial.println(Sensor.Sensor2);
		Serial.print("Sensor 3: "); Serial.println(Sensor.Sensor3);
		Serial.print("\n");
		#endif
	}
}