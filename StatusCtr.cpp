/*
 * StatusCtr.cpp
 *
 *  Created on: 14 Nov 2017
 *      Author: Adam Milward
 */

#include "StatusCtr.h"
StatusCtr::StatusCtr(){
    comPtr = NULL;
}

void StatusCtr::setCom(SerialCom* inComRef) {
    comPtr = inComRef;
}

void StatusCtr::processData(String data) {

    if (data.indexOf("report") == -1) {
        report();
    } else if (data.indexOf("report") == -1) {

    }
}

bool StatusCtr::actionSerial(String* firstWordPtr , int commandLength) {
    comPtr->debug("StatusCtr::actionSerial");
    comPtr->debug("firstWordPtr = " + *firstWordPtr);
    comPtr->debug("command length = " + String(commandLength));
    if (*(firstWordPtr) == "report") {
        comPtr->out(" - Status Report - ");
        report();
    } else {
        comPtr->out("Status Controller commands are:");
        comPtr->out("report");
        return false;
    }
    return true;
}

void StatusCtr::report() {
    comPtr->debug("StatusCtr::report()");
    comPtr->out(voltMeter.getName(0) + ": " + voltMeter.getVoltage(0) + "V");
    comPtr->out(voltMeter.getName(1) + ": " + voltMeter.getVoltage(1) + "V");
    comPtr->out(voltMeter.getName(2) + ": " + voltMeter.getVoltage(2) + "V");
    comPtr->out(voltMeter.getName(3) + ": " + voltMeter.getVoltage(3) + "V");
    comPtr->out(voltMeter.getName(4) + ": " + voltMeter.getVoltage(4) + "V");
}
