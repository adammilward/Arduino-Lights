/*
 * StatusCtr.h
 *
 *  Created on: 14 Nov 2017
 *      Author: Adam Milward
 */
#include "SerialCom.h"
#include "Arduino.h"
#include "Voltmeter.h"
#ifndef STATUSCTR_H_
#define STATUSCTR_H_

class StatusCtr {
public:
    StatusCtr();

    SerialCom* comPtr;

    enum ReportType {REPORT, CSV};
    ReportType reportType = REPORT;

    unsigned long reportDelay = 0;
    unsigned long waitMillisReport = 0;

    void setCom(SerialCom*);
    bool actionSerial(String*, int);
    void report();
    void csv();
    void timer(unsigned long);

private:
    VoltMeter voltMeter;

    void processData(String);
    void secondWord(String*);
    void setReportDelay(float);

    bool set(String*, int);
    void setAll(float);
    void showCalibration();
};
#endif /* STATUSCTR_H_ */
