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


bool SerialCom::actionSerial(String* firstWordPtr , int commandLength) {
    debug("SerialCom::actionSerial");
    debug("firstWordPtr = " + *firstWordPtr);

    if (*(firstWordPtr) == "normal") {
        mode = NORMAL;
        out("com mode set to 'normal'");
    } else if (*(firstWordPtr) == "debug") {
        mode = VERBOSE;
        out("com mode set to 'debug'");
    } else if (*(firstWordPtr) == "report") {
        out("not a lot to say really");
    } else {
        out("Command not recognised, options are:");
        out("'normal' and 'debug'");
        return false;
    }
    return true;
}

void SerialCom::debug(String word1) {
    if (mode == VERBOSE) out(word1);
}
void SerialCom::debugWd(String word1) {
    if (mode == VERBOSE) outWd(word1);
}

void SerialCom::out(String output) {
    Serial.println(output);
    BT.println(output);
}

void SerialCom::outWd(String output) {
    Serial.print(output);
    BT.print(output);
}
