/*
 * SerialCom.cpp
 *
 *  Created on: 4 Nov 2017
 *      Author: Adam Milward
 */

#include "SerialCom.h"

SoftwareSerial SerialCom::BT(CONFIG::BT_RX, CONFIG::BT_TX); // RX | TX

SerialCom::SerialCom() {
    // TODO Auto-generated constructor stub

}

void SerialCom::setName(String newName) {
    name = newName;
}

void SerialCom::out(String p1) {
    outLn(p1);
}
void SerialCom::out(String p1, int p2) {
    outWd(p1);
    outLn(p2);
}
void SerialCom::out(String p1, float p2) {
    outWd(p1);
    outLn(p2);
}
void SerialCom::out(String p1, int p2, String p3, float p4) {
    outWd(p1);
    outWd(p2);
    outWd(p3);
    outLn(p4);
}

bool SerialCom::actionSerial(String* firstWordPtr , int commandLength) {
    debug("SerialCom::actionSerial");
    debug("firstWordPtr = " + *firstWordPtr);

    if (*(firstWordPtr) == "normal") {
        mode = NORMAL;
        outLn("com mode set to 'normal'");
    } else if (*(firstWordPtr) == "debug") {
        mode = VERBOSE;
        outLn("com mode set to 'debug'");
    } else {
        outLn("Command not recognised, options are:");
        outLn("'normal' and 'debug'");
        return false;
    }
    return true;
}

void SerialCom::debug(String word1) {
    if (mode == VERBOSE) outLn(word1);
}


void SerialCom::outLn(String output) {
    Serial.println(output);
    BT.println(output);
}
void SerialCom::outLn(float output) {
    Serial.println(output);
    BT.println(output);
}
void SerialCom::outLn(int output) {
    Serial.println(output);
    BT.println(output);
}

void SerialCom::outWd(String output) {
    Serial.print(output);
    BT.print(output);
}
void SerialCom::outWd(float output) {
    Serial.print(output);
    BT.print(output);
}
void SerialCom::outWd(int output) {
    Serial.print(output);
    BT.print(output);
}
