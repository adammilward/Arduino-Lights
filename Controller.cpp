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


void Controller::serialReceive(String data) {
    String newCommand[CONFIG::COMMAND_LENGTH];
    int wordIndex = 0;
    data.trim();

    int charIndex = data.indexOf(' ');
    while (charIndex > -1) {
        newCommand[wordIndex] = data.substring(0, charIndex);
        data.remove(0, charIndex + 1);
        data.trim();
        wordIndex++;
        charIndex = data.indexOf(' ');
    }
    // take the last word and add it to the array
    newCommand[wordIndex] = data;

    if (LightRemote.actionSerial(&newCommand[0], CONFIG::COMMAND_LENGTH)) {
        //record if true
        byte i = CONFIG::COMMAND_LENGTH;
        while ( i-- ) *( command + i ) = *( newCommand + i );
    }
/*    for (int i = 0; i<5; i++) {
        Serial.println(command[i]);
        if (LightRemote.actionSerial(command[i])) {
            continue;
        }
    }*/
}

void Controller::irReceive(unsigned long inValue){
    //Serial.println(inValue, HEX);
    static int hCount;
    if (inValue == IR_HOLD) {
        hCount++;
        irDecode(storedCode, hCount);
    } else {
        hCount = 0;
        irDecode(inValue, hCount);
    }
    delay(200);
}

void Controller::irDecode(unsigned long inValue, int inHCount){
    bool actioned = false;
    switch (mode){
        case LIGHTS:
            LightRemote.holdCount = inHCount;
            actioned = LightRemote.actionRemote(inValue);
            break;
        case MP3:
            //MP3Remote.holdCount = inHCount;
            actioned = LightRemote.actionRemote(inValue);
            break;
    }
    if (true == actioned) {
        storedCode = inValue;
    } else {
        storedCode = 0;
        //Serial.print("value not recognised");
        //Serial.println(inValue, HEX);
    }
}

