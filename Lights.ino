#include "Arduino.h"
#include "LightRemote.h"
#include "Light.h"
#include "IRremote.h"


void (Light::*fadeModePtr)(float); // declare the pointer with apropriate return and input types
//fadeModePtr = &Light::LinearFade;  // assign address of light memeber function to pointer
//fadeModePtr = &Light::SinFade;
//fadeModePtr = &Light::ExpFade;
//fadeModePtr = &Light::SinExpFade;

IRrecv irrecv(8);
decode_results Results;

const int DELAY = 10;
unsigned long waitMillisLights;	// for timeing the next event.
int delayCount;			// counter for every time we passs delayt

Light Red(9);
Light Green(10);
Light Blue(11);
struct LightStruct {
Light Red = Red;
Light Green =  Green;
Light Blue = Blue;
};
LightStruct LightSt;

void setup() {
	irrecv.enableIRIn(); // Start the receiver
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
	Serial.println("Lights");

	// Timer0 is already used for millis() - we'll just interrupt somewhere
	// in the middle and call the "Compare A" function below
	OCR0A = 0x80;
	TIMSK0 |= _BV(OCIE0A);
	waitMillisLights = millis() + DELAY;
}

// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
SIGNAL(TIMER0_COMPA_vect) {
	if ((long) (millis() - waitMillisLights) >= 0) {
	waitMillisLights += DELAY; // set the time for next interupt
	LightRemote::timer();
	}
}

// The loop function is called in an endless loop
void loop() {

	if (irrecv.decode(&Results)) {
		LightRemote::receive(Results.value, LightSt);
		Serial.println(Results.value, HEX);
		delay(200);
		irrecv.resume(); // Receive the next value
	}


}
