//#define MYBUG 0
//#define DEBUG 0
//#define LIGHTS 0
//#define MEGA 0

#include "Arduino.h"

#include "Controller.h"
#include "SerialCom.h"
#include "Config.h"

#ifdef LIGHTS
//#include "IRremote.h"
    IRrecv irrecv(CONFIG::IREC_PIN);      // from the ir decode library
    decode_results Results; // from the ir decode library
    Light LightCtr::Red(CONFIG::RED_PIN, 0);
    Light LightCtr::Green(CONFIG::GREEN_PIN, 1);
    Light LightCtr::Blue(CONFIG::BLUE_PIN, 2);
#endif

SerialCom com;
Controller masterCtr(&com);      // handles the remotes
// Connect the HC-05 TX to the Arduino RX on pin 12.
// Connect the HC-05 RX to the Arduino TX on pin 3 through a voltage divider.

void setup() {
    randomSeed(analogRead(0)); // initialise for random numbers


    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
#ifdef MEGA
    Serial3.begin(9600);
#endif
    //SerialCom::BT.begin(9600);
#ifdef MYBUG
    Serial.print(F("serial ready to recieve"));
    Serial.print(F("serial3 ready to recieve"));
    //SerialCom::BT.println("software serial ready to recieve");
    com.out(F("** MYBUG mode enabled **"));
#endif

    //Timer0 is already used for millis() - we'll just interrupt somewhere
    //in the middle and call the "Compare A" function below
    //OCR0A = 0x80;
    //TIMSK0 |= _BV(OCIE0A);

    com.out(F("we are progammed to recieve"));
    Serial.print (F("Free memory = "));
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
#ifdef LIGHTS
    if (irrecv.decode(&Results)) {
        masterCtr.irReceive(Results.value);
        irrecv.resume(); // Receive the next value
    }
#endif
    // run Serial commands
    while (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        Serial.print(command);
        masterCtr.serialReceive(command);
    }
#ifdef MEGA
    while (Serial3.available()) {
        String command = Serial3.readStringUntil('\n');
        Serial.print(command);
        masterCtr.serialReceive(command);
    }
#endif
    /*while (com.BT.available()) {
        String command = com.BT.readStringUntil('\n');
        masterCtr.serialReceive(command);
    }*/
}

