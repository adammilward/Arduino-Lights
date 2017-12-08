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
        comPtr->out(F("Status Controller commands are:"));
        comPtr->out(F("report [nn]"));
        comPtr->out(F("where repeat delay in s"));
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
    comPtr->out(F(""));
    comPtr->out(F("    ****    "));
    comPtr->outWd(F("SolarPanels: "));
    comPtr->outWd(voltMeter.getVoltage(0));
    comPtr->out(F("V"));
    comPtr->outWd(F("ConsumerUnit: "));
    comPtr->outWd(voltMeter.getVoltage(1));
    comPtr->out(F("V"));
    comPtr->outWd(F("LeisueBattery: "));
    comPtr->outWd(voltMeter.getVoltage(2));
    comPtr->out(F("V"));
    comPtr->outWd(F("BanBattery: "));
    comPtr->outWd(voltMeter.getVoltage(3));
    comPtr->out(F("V"));
    comPtr->outWd("spare: ");
    comPtr->outWd(voltMeter.getVoltage(4));
    comPtr->out(F("V"));
    comPtr->outWd(F("delay= "));
    comPtr->out((float)reportDelay/1000);
}
