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
    //FadeLightCtr Fader;
}
void Controller::receive(unsigned long inValue){
    //Serial.println();
    static int hCount;
    if (inValue == IR_HOLD) {
        hCount++;
        decode(storedValue, hCount);
    } else {
        hCount = 0;
        decode(inValue, hCount);
    }
    delay(200);
}
void Controller::decode(unsigned long inValue, int inHCount){
    bool actioned = false;
    switch (mode){
        case LIGHTS:
            LightRemote.holdCount = inHCount;
            actioned = LightRemote.action(inValue);
            break;
        case MP3:
            //MP3Remote.holdCount = inHCount;
            actioned = LightRemote.action(inValue);
            break;
    }
    if (true == actioned) {
        storedValue = inValue;
    } else {
        storedValue = 0;
        //Serial.print("value not recognised");
        //Serial.println(inValue, HEX);
    }
}

