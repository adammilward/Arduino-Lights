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

void SerialCom::sayName() {
    outWd("Name Is: ");
    outLn(name);
}

void SerialCom::setName(String newName) {
    name = newName;
}

void SerialCom::out(String word1) {
    outLn(word1);
}
void SerialCom::out(String word1, int in2) {
    outWd(word1);
    outLn(in2);
}
void SerialCom::out(String word1, String word2) {
    outWd(word1);
    outLn(word2);
}
void SerialCom::out(String word1, String word2, String word3) {
    outWd(word1);
    outWd(word2);
    outLn(word3);
}

bool SerialCom::actionSerial(String data) {
    debug("SerialCom::actionSerial");
    if (data.indexOf("debug") != -1) {
        if(data.indexOf("off") != -1) {
            mode = NORMAL;
            out("debug output disabled");
            return true;
        } else {
            mode = VERBOSE;
            out("debug mode enabled");
            return true;
        }
    } else if (data.indexOf("normal") != -1) {
        mode = NORMAL;
        out("debug output disabled");
        return true;
    } else {
        return false;
    }
}

void SerialCom::debug(String word1) {
    if (mode == VERBOSE) outLn(word1);
}

void SerialCom::outLn(char output) {
    Serial.println(output);
    BT.println(output);
}
void SerialCom::outLn(String output) {
    Serial.println(output);
    BT.println(output);
}

void SerialCom::outWd(String output) {
    Serial.print(output);
    Serial.print("   ");
    BT.print(output);
    BT.print("   ");
}
