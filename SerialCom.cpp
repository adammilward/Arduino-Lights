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
