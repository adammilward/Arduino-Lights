/*
 * StatusCtr.cpp
 *
 *  Created on: 14 Nov 2017
 *      Author: Adam Milward
 */

#include "StatusCtr.h"
StatusCtr::StatusCtr(){
    VoltMeter voltMeter;
}

StatusCtr::StatusCtr(SerialCom& inCom) {
    com = inCom;
}

void StatusCtr::processData(String data) {

    if (data.indexOf("report") == -1) {
        report();
    } else if (data.indexOf("report") == -1) {

    }
}

bool StatusCtr::actionSerial(String data) {
    com.debug("StatusCtr::actionSerial");
    if (data.indexOf("report") != -1) {
        report();
        return true;
    //} else if (data.indexOf("todo") != -1) {
        // todo add more options
        //return true;
    } else {
        return false;
    }
}

void StatusCtr::report() {
    com.debug("StatusCtr::report()");
    com.outLn(voltMeter.getName(0) + ": " + voltMeter.getVoltage(0) + "V");
    com.outLn(voltMeter.getName(1) + ": " + voltMeter.getVoltage(1) + "V");
    com.outLn(voltMeter.getName(2) + ": " + voltMeter.getVoltage(2) + "V");
    com.outLn(voltMeter.getName(3) + ": " + voltMeter.getVoltage(3) + "V");
    com.outLn(voltMeter.getName(4) + ": " + voltMeter.getVoltage(4) + "V");
}
