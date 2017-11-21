/*
 * RemoteReceive.cpp
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */

#include "Controller.h"

Controller::Controller(SerialCom *inComRef) {
    comPtr = inComRef;
    lightCtr.setCom(inComRef);
    statusCtr.setCom(inComRef);
    //FadeLightCtr Fader;
}


void Controller::serialReceive(String data) {
    data.toLowerCase();
    data.trim();
    comPtr->debug("serialRecieve: " + data);

    if (! checkForRepeat(data)) {
        data = checkForMode(data);
        comPtr->debug("data after chek for mode: " + data);
        if (0 < data.length()){
            processSerial(data);
        }
    }


    /*data.trim();

    int wordIndex = 0;


    int charIndex = data.indexOf(' ');
    while (charIndex > -1 && wordIndex < CONFIG::COMMAND_MAX_LENGTH) {
        newCommand[wordIndex] = data.substring(0, charIndex);
        data.remove(0, charIndex);
        data.trim();
        wordIndex++;
        charIndex = data.indexOf(' ');
    }
    if (wordIndex < CONFIG::COMMAND_MAX_LENGTH) {
        newCommand[wordIndex] = data;
    }

    
    for ( int i = 0 ; i <= wordIndex ; i++ ) com.outLn(newCommand[i]);*/
    
    /*if (lightRemote.actionSerial(newCommand, wordIndex+1)) {
        //record if true
        byte i = CONFIG::COMMAND_MAX_LENGTH;
        while ( i-- ) oldCommand[i] = newCommand[i];
    }*/
}

bool Controller::checkForRepeat(String data)  {
    if (0 == data.length()) {
        processSerial(oldData);
    }
    return false;
}

String Controller::checkForMode(String data)  {
    if (data.indexOf("lights") != -1) {
        mode = LIGHT;
        data.remove(0, 6);
        comPtr->out("Lights mode set");
    } else if (data.indexOf("status") != -1) {
        mode = STATUS;
        data.remove(0, 6);
        comPtr->out("Status mode set");
    } else if (data.indexOf("com") != -1) {
        mode = COM;
        data.remove(0, 3);
        comPtr->out("Com mode set");
    } else {
        return data;
        comPtr->debug("no mode set");
    }
    data.trim();
    comPtr->debug("data: " + data);
    return data;
}

void Controller::processSerial(String data) {
    bool actioned = false;
    switch (mode) {
    case LIGHT:
        actioned = lightCtr.actionSerial(data);
        break;
    case STATUS:
        actioned = statusCtr.actionSerial(data);
        break;
    case COM:
        actioned = comPtr->actionSerial(data);
        break;
    }
    if (actioned) {
        // todo need to check fo more data hee?
        oldData = data;
    } else {
        comPtr->out("I'm sorry Dave, I'm affraid I can't do that.");
    }
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
    switch (iRMode){
        case IR_LIGHTS:
            lightCtr.holdCount = inHCount;
            actioned = lightCtr.actionRemote(inValue);
            break;
        case IR_MP3:
            //MP3Remote.holdCount = inHCount;
            actioned = lightCtr.actionRemote(inValue);
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

