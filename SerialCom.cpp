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


bool SerialCom::actionSerial(String* firstWordPtr, int commandLength) {
    if (*(firstWordPtr) == "normal") {
        mode = NORMAL;
        out(F("com mode set to 'normal'"));
    } else if (*(firstWordPtr) == "debug") {
        mode = VERBOSE;
        out(F("com mode set to 'debug'"));
    } else if (*(firstWordPtr) == "report") {
        out(F("not a lot to say really"));
    } else {
        out(F("Command not recognised, options are:"));
        out(F("'normal' and 'debug'"));
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
            word->charAt(i) == '-'
        );
        if(!isNum) return false;
    }
    return isNum;
}


void SerialCom::out(byte output) {
    Serial.println(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.println(output);
}
void SerialCom::outWd(byte output) {
    Serial.print(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.print(output);
}
void SerialCom::out(unsigned int output) {
    Serial.println(output);
#ifdef UNO
    Serial3.println(output);
#endif
    //BT.println(output);
}
void SerialCom::outWd(unsigned int output) {
    Serial.print(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.print(output);
}
void SerialCom::out(int output) {
    Serial.println(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.println(output);
}
void SerialCom::outWd(int output) {
    Serial.print(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.print(output);
}
void SerialCom::out(float output) {
    Serial.println(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.println(output);
}
void SerialCom::outWd(float output) {
    Serial.print(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.print(output);
}
void SerialCom::out(String output) {
    Serial.println(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.println(output);
}
void SerialCom::outWd(String output) {
    Serial.print(output);
#ifdef MEGA
    Serial3.println(output);
#endif
    //BT.print(output);
}
