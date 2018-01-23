/*
 * StatusCtr.cpp
 *
 *  Created on: 14 Nov 2017
 *      Author: Adam Milward
 */

#include "StatusCtr.h"
#include "stdlib.h"

StatusCtr::StatusCtr(){
    comPtr = 0;
}

void StatusCtr::setCom(SerialCom* inComRef) {
    comPtr = inComRef;
}

bool StatusCtr::actionSerial(String* firstWordPtr , int commandLength) {
    if (*(firstWordPtr) == "report") {
        if (commandLength == 2 && comPtr->isNum(firstWordPtr+1)) {
            setReportDelay((firstWordPtr+1)->toFloat());
            reportType = REPORT;
        }
        report();
    } else if (*(firstWordPtr) == "csv") {
        if (commandLength == 2 && comPtr->isNum(firstWordPtr+1)) {
            setReportDelay((firstWordPtr+1)->toFloat());
            reportType = CSV;
        }
        csv();
    } else if (*(firstWordPtr) == "raw") {
        voltMeter.toggleConfigMode();
    } else if (*(firstWordPtr) == "set") {
        set((firstWordPtr+1), --commandLength);
    } else if (*(firstWordPtr) == "save") {
        voltMeter.saveCalibration();
        comPtr->out(F("Calibration Saved"));
    } else if (*(firstWordPtr) == "calibration") {
        showCalibration();
    } else {
        comPtr->out(F("Status Controller commands are:"));
        comPtr->out(F("report [nn]"));
        comPtr->out(F("csv [nn]"));
        comPtr->out(F("(where nn is repeat delay in s)"));
        comPtr->out(F("raw"));
        comPtr->out(F("save"));
        comPtr->out(F("calibration"));
        return false;
    }
    return true;
}

void StatusCtr::showCalibration() {
    char buff[14];
    for (int pin = 0; pin < voltMeter.numberOfPins; pin++) {
        dtostrf(voltMeter.getCalibration(pin), 4, 12, buff);
        comPtr->out(buff);
    }
}

bool StatusCtr::set(String* firstWordPtr, int commandLength) {
    if (commandLength == 2) {
        if (*(firstWordPtr) == "all" && comPtr->isNum(firstWordPtr+1)) {
            setAll((firstWordPtr+1)->toFloat());
            comPtr->out(F("value set"));
            return true;
        } else if (comPtr->isNum(firstWordPtr)
                && comPtr->isNum(firstWordPtr+1))
        {
            voltMeter.setPin(
                firstWordPtr->toInt(),
                (firstWordPtr+1)->toFloat()
            );
            comPtr->out(F("value set"));
            return true;
        }
    }
    comPtr->out(F("Set Failed, command format is: "));
    comPtr->out(F("Set All (nn.nn)"));
    comPtr->out(F("Set (pinNumber) (nn.nn)"));
    return false;
}

void StatusCtr::setAll(float newValue) {
    for (int pin = 0; pin < 5; pin++) {
        voltMeter.setPin(pin, newValue);
    }
}

void StatusCtr::setReportDelay(float delaySeconds) {
    reportDelay = (unsigned long)(delaySeconds * 1000);
    waitMillisReport = millis() + reportDelay;
}

void StatusCtr::timer(unsigned long millis) {
    if (reportDelay > 0
                &&
                (signed long)(millis - waitMillisReport) >= 0
        )
        {
            switch (reportType) {
            case 0 :
                report();
                break;
            case 1 :
                csv();
                break;
            }
            waitMillisReport = millis + reportDelay;
        }
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
