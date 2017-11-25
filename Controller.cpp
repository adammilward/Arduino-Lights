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
    int firstWordIndex = 0; // where in the array we start
    String newCommand[CONFIG::COMMAND_MAX_LENGTH]; // the array of commands
    int commandLength = 0; // where in the array we stop

    data.toLowerCase();
    data.trim();
    comPtr->debug("****************");
    comPtr->debug("serialRecieve: " + data);

    if (checkForRepeat(data)) {
        return;
    }

    int charIndex = data.indexOf(' ');
    while (charIndex > -1 && commandLength < CONFIG::COMMAND_MAX_LENGTH) {
        newCommand[commandLength] = data.substring(0, charIndex);
        data.remove(0, charIndex);
        data.trim();
        commandLength++;
        charIndex = data.indexOf(' ');
    }
    // collect the last word after the last space
    if (commandLength < CONFIG::COMMAND_MAX_LENGTH) {
        newCommand[commandLength] = data;
        commandLength++; // record number of words found
    }
    comPtr->debug(String(commandLength) + " words found");
    comPtr->debug("newCommand array: ");
    for ( int i = 0 ; i < commandLength ; i++ ) comPtr->debug(newCommand[i]);


    if (checkForMode(&newCommand[0], 1)) {
        firstWordIndex++; //set ignore first word
        commandLength--;
    }

    // if there are more commands to run
    if (commandLength > 0) {
        if (processSerial(&newCommand[firstWordIndex], commandLength)) {
            comPtr->debug("seccusesfull processSerial");
        }
    } else {
        comPtr->debug("no more commands");
    }

    comPtr->debug("newCommand array after mode: ");
    for (int i = firstWordIndex; i <= commandLength; i++ ) comPtr->debug(newCommand[i]);

    comPtr->debug("lastCommand array  afte mode: ");
    for (int i = 0 ; i < lastCommandLength; i++ ) comPtr->debug(lastCommand[i]);


}

bool Controller::checkForRepeat(String data)  {
    if (0 == data.length()) {
        return processSerial(&lastCommand[0], lastCommandLength);
    }
    return false;
}

bool Controller::checkForMode(String* wordPtr, int length)  {
    comPtr->debug("checkForMode: input = " + *wordPtr);

    if (*wordPtr == "lights") {
        mode = LIGHTS;
        comPtr->out("Lights Mode engaged");
        return true;
    } else if (*wordPtr == "status") {
        mode = STATUS;
        comPtr->out("Status Mode engaged");
        return true;
    } else if (*wordPtr == "com") {
        mode = COM;
        comPtr->out("Com Mode engaged");
        return true;
    }
    comPtr->debug("checkForMode: no mode set");
    return false;
}

bool Controller::processSerial(String* firstWordPtr, int commandLength) {
    bool actioned = false;
    switch (mode) {
    case LIGHTS:
        actioned = lightCtr.actionSerial(firstWordPtr, commandLength);
        break;
    case STATUS:
        actioned = statusCtr.actionSerial(firstWordPtr, commandLength);
        break;
    case COM:
        actioned = comPtr->actionSerial(firstWordPtr, commandLength);
        break;
    }
    if (actioned) {
        copy(firstWordPtr, &lastCommand[0], commandLength);
    } else {
        comPtr->out("I'm sorry Dave, I'm affraid I can't do that.");
    }
    return actioned;
}

void Controller::copy(String* firstWordPtr, String* oldCommandPtr, int commandLength){
    lastCommandLength = commandLength;
    while(commandLength--) *oldCommandPtr++ = *firstWordPtr++;
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
        comPtr->debug("value not recognised");
        comPtr->debug(String(inValue, HEX));
    }
}

