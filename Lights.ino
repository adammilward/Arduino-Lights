#include "Arduino.h"
#include "Light.h"
#include "IRremote.h"


void (Light::*fadeModePtr)(float); // declare the pointer with apropriate return and input types
//fadeModePtr = &Light::LinearFade;  // assign address of light memeber function to pointer
//fadeModePtr = &Light::SinFade;
//fadeModePtr = &Light::ExpFade;
//fadeModePtr = &Light::SinExpFade;

IRrecv irrecv(8);
decode_results Results;

const int DELAY = 50;
unsigned long waitMillisLights;	// for timeing the next event.
int delayCount;			// counter for every time we passs delayt

Light Red(8, 0);
Light Green(9, 0.5);
Light Blue(10, 0.7);



void setup() {
	irrecv.enableIRIn(); // Start the receiver
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
	Serial.println("Lights2");

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
		delayCount += 1;      // increment the counter for this interupt

		switch (delayCount) {
		case 1:
			// slide should not be more than 0.002 for smootheness
			Red.slide(0.0010);
			break;
		case 2:
			Green.slide(0.002);
			break;
		case 3:
			Blue.slide(0.0011);
			delayCount = 0;
			break;
		default:
			Serial.print(Red.power);
			Serial.print("    ");
			Serial.print(Red.base * 100);
			Serial.print("    ");
			Serial.print(Green.power);
			Serial.print("    ");
			Serial.print(Green.base * 100);
			Serial.print("     ");
			Serial.print(Blue.power);
			Serial.print("     ");
			Serial.print(Blue.base * 100);
			Serial.println(" ");
			delayCount = 0;
			break;
			//}
		}
	}
}

// The loop function is called in an endless loop
void loop() {

//	if (irrecv.decode(&Results)) {
//		LightRemote::receive(Results.value, LightSt);
//		Serial.println(Results.value, HEX);
//		delay(200);
//		irrecv.resume(); // Receive the next value
//	}


}
