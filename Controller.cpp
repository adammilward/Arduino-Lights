/*
 * RemoteReceive.cpp
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */

#include "Controller.h"

Controller::Controller(SerialCom* inComPtr) {
    comPtr = *inComPtr;
    mode = LIGHTS;
    LightCtr LightRemote;
    //FadeLightCtr Fader;
}


void Controller::serialReceive(String data) {
    String newCommand[CONFIG::COMMAND_MAX_LENGTH];
    int wordIndex = 0;
    data.trim();

    int charIndex = data.indexOf(' ');
    while (charIndex > -1 && wordIndex <= CONFIG::COMMAND_MAX_LENGTH-1) {
        Serial.println(data);
        newCommand[wordIndex] = data.substring(0, charIndex);
        data.remove(0, charIndex + 1);
        data.trim();
        wordIndex++;
        charIndex = data.indexOf(' ');
        Serial.println(charIndex);
    }
    // take the last word and add it to the array
    newCommand[wordIndex] = data;
    
    for ( int i = 0 ; i <= wordIndex ; i++ ) Serial.println(newCommand[i]);
    
    /*if (LightRemote.actionSerial(&newCommand[0], wordIndex+1)) {
        //record if true
        byte i = CONFIG::COMMAND_MAX_LENGTH;
        while ( i-- ) *( command + i ) = *( newCommand + i );
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

