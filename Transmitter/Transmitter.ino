// #####################################################################################################################
// ######################################### WIRELESS COM TRANSMITTER ##################################################
// ##################################################################################################################### 
/*
	This is the transmitter.
	It sends analog values to the receiver every half second.
*/
// Get neccessary header files
#include <SPI.h>
#include "RF24.h"

// Define the radio addresses (must be the same on both devices!)
byte addresses[][6] = {"DevRX", "DevTX"};

// Setup NRF24 to SPI BUS and the pins 9 and 10 (Check wiring on my blog!)
RF24 radio(9, 10);

// Using a struct to store the analog values
struct dataStruct
{
	word Sensor1, Sensor2, Sensor3;
} Sensor;
void setup()
{
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
	radio.openWritingPipe(addresses[0]);
	radio.openReadingPipe(1, addresses[1]);
}
void loop()
{
	Sensor.Sensor1 = analogRead(A0);
	Sensor.Sensor2 = analogRead(A1);
	Sensor.Sensor3 = analogRead(A2);

	radio.write(&Sensor, sizeof(Sensor));

	delay(500);
}