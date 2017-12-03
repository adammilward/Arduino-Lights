/*
 * StatusCtr.cpp
 *
 *  Created on: 14 Nov 2017
 *      Author: Adam Milward
 */

#include "StatusCtr.h"
StatusCtr::StatusCtr(){
    comPtr = 0;
}

void StatusCtr::setCom(SerialCom* inComRef) {
    comPtr = inComRef;
}

bool StatusCtr::actionSerial(String* firstWordPtr , int arrayLength) {
    if (*(firstWordPtr) == "report") {
        if (arrayLength == 2 && comPtr->isNum(firstWordPtr+1)) {
            float value = (firstWordPtr+1)->toFloat();
            setReportDelay(value);
        } else {
            report();
        }
    } else {
        comPtr->out("Status Controller commands are:");
        comPtr->out("report [nn]");
        comPtr->out("where repeat delay in s");
        return false;
    }
    return true;
}

void StatusCtr::setReportDelay(float delaySeconds) {
    reportDelay = (unsigned int)(delaySeconds * 1000);
    waitMillisReport = millis() + reportDelay;
    report();
}

void StatusCtr::report() {
    comPtr->out("");
    comPtr->out("    ****    ");
    comPtr->out("SolarPanels: " + voltMeter.getVoltage(0) + "V");
    comPtr->out("ConsumerUnit: " + voltMeter.getVoltage(1) + "V");
    comPtr->out("LeisueBattery: " + voltMeter.getVoltage(2) + "V");
    comPtr->out("BanBattery: " + voltMeter.getVoltage(3) + "V");
    comPtr->out("spare: " + voltMeter.getVoltage(4) + "V");
    comPtr->out("delay= "+String(reportDelay/1000));
}
