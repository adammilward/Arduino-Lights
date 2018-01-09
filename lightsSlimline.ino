//#define MYBUG 0

#include "Arduino.h"
#include "IRremote.h"
#include "Controller.h"
#include "SerialCom.h"


#include "Config.h"

IRrecv irrecv(CONFIG::IREC_PIN);      // from the ir decode library
decode_results Results; // from the ir decode library
SerialCom com;
Controller masterCtr(&com);      // handles the remotes


// Connect the HC-05 TX to the Arduino RX on pin 12.
// Connect the HC-05 RX to the Arduino TX on pin 3 through a voltage divider.

void setup() {
    randomSeed(analogRead(0)); // initialise for random numbers
    irrecv.enableIRIn(); // Start the receiver
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    Serial3.begin(9600);
    //SerialCom::BT.begin(9600);
    Serial.print(F("serial ready to recieve"));
    Serial.print(F("serial3 ready to recieve"));
    //SerialCom::BT.println("software serial ready to recieve");

    //Timer0 is already used for millis() - we'll just interrupt somewhere
    //in the middle and call the "Compare A" function below
    //OCR0A = 0x80;
    //TIMSK0 |= _BV(OCIE0A);

    delay(100);
    masterCtr.lightCtr.Red.set(-1);
    masterCtr.lightCtr.Green.set(-1);
    masterCtr.lightCtr.Blue.set(-1);
#ifdef MYBUG
    com.out(F("** MYBUG mode enabled **"));
#endif
    com.out(F("we are progammed to recieve"));
}

// Interrupt is called once a millisecond,
/*    if (RemoteCtr.LightRemote.ctrMode != LightCtr::STATIC) {
SIGNAL(TIMER0_COMPA_vect) {
        if ((long) (millis() - waitMillisLights) >= 0) {
            // set the time for next interupt
            waitMillisLights += RemoteCtr.LightRemote.delay;
            RemoteCtr.LightRemote.interrupt();
        }
    }*/

//}

// The loop function is called in an endless loop
void loop() {


    masterCtr.timer(millis());

    // run IR Commandes
    if (irrecv.decode(&Results)) {
        masterCtr.irReceive(Results.value);
        irrecv.resume(); // Receive the next value
    }

    // run Serial commands
    while (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        Serial.print(command);
        masterCtr.serialReceive(command);
    }
    while (Serial3.available()) {
        String command = Serial3.readStringUntil('\n');
        Serial.print(command);
        masterCtr.serialReceive(command);
    }
    /*while (com.BT.available()) {
        String command = com.BT.readStringUntil('\n');
        masterCtr.serialReceive(command);
    }*/
}

