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
void Controller::irReceive(unsigned long inValue){
    //Serial.println(inValue, HEX);
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

void Controller::serialReceive(String data) {
    int wordIndex = 0;
        String command[5] ;
        data.trim();

        int charIndex = data.indexOf(' ');
        while (charIndex > -1) {
            command[wordIndex] = data.substring(0, charIndex);
            data.remove(0, charIndex + 1);
            data.trim();
            wordIndex++;
            charIndex = data.indexOf(' ');
        }
        command[wordIndex] = data;

            Serial.println(command[0]);
            Serial.println(command[1]);
            Serial.println(command[2]);
            Serial.println(command[3]);
            Serial.println(command[4]);
            //BTs.println(command[0]);
            /*BTserial.println(command[1]);
            BTserial.println(command[2]);
            BTserial.println(command[3]);
            BTserial.println(command[4]);*/
            //BTs.println("hello World");
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

