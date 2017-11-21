
#include "Arduino.h"
#include "IRremote.h"
#include "Controller.h"
#include "SoftwareSerial.h"
#include "SerialCom.h"

IRrecv irrecv(CONFIG::IREC_PIN);      // from the ir decode library
decode_results Results; // from the ir decode library
SerialCom com;
Controller masterCtr(&com);      // handles the remotes


// Connect the HC-05 TX to the Arduino RX on pin 12.
// Connect the HC-05 RX to the Arduino TX on pin 3 through a voltage divider.

//int DELAY = CONFIG::DELAY;  // delay in miliseconds
unsigned long waitMillisLights; // for timeing the next event.

void setup() {
    randomSeed(analogRead(0)); // initialise for random numbers
	irrecv.enableIRIn(); // Start the receiver
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
    Serial.println("ready to recieve");
	SerialCom::BT.begin(9600);
    SerialCom::BT.println("ready to recieve");

	//Timer0 is already used for millis() - we'll just interrupt somewhere
	//in the middle and call the "Compare A" function below
	//OCR0A = 0x80;
	//TIMSK0 |= _BV(OCIE0A);
	waitMillisLights = millis() + masterCtr.lightRemote.delay;

    delay(100);
    masterCtr.lightRemote.Red.set(1);
    masterCtr.lightRemote.Green.set(0.5);
    masterCtr.lightRemote.Blue.set(0);


    com.sayName();
    masterCtr.comPtr->sayName();
    masterCtr.lightRemote.comPtr->sayName();
    com.out("initilisation finished");

    com.setName("name set in setup");
    com.sayName();
    masterCtr.comPtr->sayName();
    masterCtr.lightRemote.comPtr->sayName();

    com.out("set comPtr for lightRemote");
    masterCtr.lightRemote.setCom(&com);
    masterCtr.lightRemote.comPtr->sayName();

}

// Interrupt is called once a millisecond,
SIGNAL(TIMER0_COMPA_vect) {
/*    if (RemoteCtr.LightRemote.ctrMode != LightCtr::STATIC) {
        if ((long) (millis() - waitMillisLights) >= 0) {
            // set the time for next interupt
            waitMillisLights += RemoteCtr.LightRemote.delay;
            RemoteCtr.LightRemote.interrupt();
        }
    }*/

}

// The loop function is called in an endless loop
void loop() {

    // run fading
    if (masterCtr.lightRemote.ctrMode != LightCtr::STATIC) {
        if ((long) (millis() - waitMillisLights) >= 0) {
            // set the time for next interupt
            waitMillisLights = millis() + masterCtr.lightRemote.delay;
            masterCtr.lightRemote.interrupt();
        }
    }

    // run IR Commandes
	if (irrecv.decode(&Results)) {
	    masterCtr.irReceive(Results.value);
		irrecv.resume(); // Receive the next value
	}

	// run Serial commands
	while (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        masterCtr.serialReceive(command);
    }
    while (com.BT.available()) {
        String command = Serial.readStringUntil('\n');
        masterCtr.serialReceive(command);
    }
}

