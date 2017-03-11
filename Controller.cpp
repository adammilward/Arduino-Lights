/*
 * RemoteReceive.cpp
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */

#include "Controller.h"

Controller::Controller() {
    mode = LIGHTS;
    LightCtr LightRemote;
    storedValue = 0;
}
void Controller::receive(unsigned long inValue){
    if (inValue == IR_HOLD) {
      decode(storedValue);
    } else {
      decode(inValue);
    }
    delay(200);
}
void Controller::decode(unsigned long inValue){
    bool actioned = false;
    switch (mode){
        case LIGHTS:
            actioned = LightRemote.action(inValue);
            break;
        case MP3:
            actioned = LightRemote.action(inValue);
            break;
    }
    if (true == actioned) {
        storedValue = inValue;
    } else {
        storedValue = 0;
        Serial.print("value not recognised");
        Serial.println(inValue, HEX);
    }
}

