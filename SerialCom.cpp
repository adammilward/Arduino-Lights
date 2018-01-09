/*
 * SerialCom.cpp
 *
 *  Created on: 4 Nov 2017
 *      Author: Adam Milward
 */

#include "SerialCom.h"

//SoftwareSerial SerialCom::BT(CONFIG::BT_RX, CONFIG::BT_TX); // RX | TX

SerialCom::SerialCom() {
    // TODO Auto-generated constructor stub

}


bool SerialCom::actionSerial(String* firstWordPtr , int commandLength) {
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

bool SerialCom::isNum(String* word) {
    boolean isNum=false;
    for(byte i = 0 ; i < word->length() ; i++)
    {
        isNum = (
                isDigit(word->charAt(i)) ||
                word->charAt(i) == '+' ||
                word->charAt(i) == '.' ||
                word->charAt(i) == '-');
        if(!isNum) return false;
    }
    return isNum;
}


void SerialCom::out(byte output) {
    Serial.println(output);
    Serial3.println(output);
    //BT.println(output);
}
void SerialCom::outWd(byte output) {
    Serial.print(output);
    Serial3.print(output);
    //BT.print(output);
}
void SerialCom::out(unsigned int output) {
    Serial.println(output);
    Serial3.println(output);
    //BT.println(output);
}
void SerialCom::outWd(unsigned int output) {
    Serial.print(output);
    Serial3.print(output);
    //BT.print(output);
}
void SerialCom::out(int output) {
    Serial.println(output);
    Serial3.println(output);
    //BT.println(output);
}
void SerialCom::outWd(int output) {
    Serial.print(output);
    Serial3.print(output);
    //BT.print(output);
}
void SerialCom::out(float output) {
    Serial.println(output);
    Serial3.println(output);
    //BT.println(output);
}
void SerialCom::outWd(float output) {
    Serial.print(output);
    Serial3.print(output);
    //BT.print(output);
}
void SerialCom::out(String output) {
    Serial.println(output);
    Serial3.println(output);
    //BT.println(output);
}
void SerialCom::outWd(String output) {
    Serial.print(output);
    Serial3.print(output);
    //BT.print(output);
}
