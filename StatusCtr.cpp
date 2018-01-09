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
            setReportDelay((firstWordPtr+1)->toFloat());
            reportType = REPORT;
        }
        report();
    } else if (*(firstWordPtr) == "csv") {
        if (arrayLength == 2 && comPtr->isNum(firstWordPtr+1)) {
            setReportDelay((firstWordPtr+1)->toFloat());
            reportType = CSV;
        }
        csv();
    } else if (*(firstWordPtr) == "calibrate") {
        voltMeter.toggleConfigMode();
    } else {
        comPtr->out(F("Status Controller commands are:"));
        comPtr->out(F("report [nn]"));
        comPtr->out(F("report [nn]"));
        comPtr->out(F("calibrate"));
        comPtr->out(F("where nn is repeat delay in s"));
        return false;
    }
    return true;
}

void StatusCtr::setReportDelay(float delaySeconds) {
    reportDelay = (unsigned long)(delaySeconds * 1000);
    waitMillisReport = millis() + reportDelay;
}

void StatusCtr::report() {
    comPtr->out(F(""));
    comPtr->out(F("    ****    "));
    comPtr->outWd(F("Solar "
            ""
            "Panels: "));
    comPtr->outWd(voltMeter.getVoltage(0));
    comPtr->out(F("V"));
    comPtr->outWd(F("Consumer Unit: "));
    comPtr->outWd(voltMeter.getVoltage(1));
    comPtr->out(F("V"));
    comPtr->outWd(F("Leisue Battery: "));
    comPtr->outWd(voltMeter.getVoltage(2));
    comPtr->out(F("V"));
    comPtr->outWd(F("Van Battery: "));
    comPtr->outWd(voltMeter.getVoltage(3));
    comPtr->out(F("V"));
    comPtr->outWd("spare: ");
    comPtr->outWd(voltMeter.getVoltage(4));
    comPtr->out(F("V"));
    comPtr->outWd(F("delay= "));
    comPtr->out((float)reportDelay/1000);
}

void StatusCtr::csv() {
    comPtr->outWd(F(", "));
    comPtr->outWd(voltMeter.getVoltage(0));
    comPtr->outWd(F(", "));
    comPtr->outWd(voltMeter.getVoltage(1));
    comPtr->outWd(F(", "));
    comPtr->outWd(voltMeter.getVoltage(2));
    comPtr->outWd(F(", "));
    comPtr->outWd(voltMeter.getVoltage(3));
    comPtr->outWd(F(", "));
    comPtr->out(voltMeter.getVoltage(4));
}
