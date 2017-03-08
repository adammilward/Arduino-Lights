
#include "light.h"
#include "Arduino.h"
#include "IRremote.h"
#include "Controller.h"


IRrecv irrecv(12);      // from the ir decode library
decode_results Results; // from the ir decode library
Controller RemoteCtr;      // handles the remotes

const int DELAY = 100;  // delay in miliseconds
unsigned long waitMillisLights; // for timeing the next event.

void setup() {
	irrecv.enableIRIn(); // Start the receiver
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
	Serial.println("Lights2");
	Serial.println(Light::fMode);

	//Timer0 is already used for millis() - we'll just interrupt somewhere
	//in the middle and call the "Compare A" function below
	OCR0A = 0x80;
	TIMSK0 |= _BV(OCIE0A);
	waitMillisLights = millis() + DELAY;
}

// Interrupt is called once a millisecond,
SIGNAL(TIMER0_COMPA_vect) {
    if (RemoteCtr.LightRemote.Red.fMode != Light::STATIC) {
        if ((long) (millis() - waitMillisLights) >= 0) {
            waitMillisLights += DELAY;  // set the time for next interupt
            RemoteCtr.LightRemote.interrupt();
        }
    }
}

// The loop function is called in an endless loop
void loop() {

	if (irrecv.decode(&Results)) {
	    RemoteCtr.receive(Results.value);
		delay(200);
		irrecv.resume(); // Receive the next value
	}


}
