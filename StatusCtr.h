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

    unsigned int reportDelay = 0;
    unsigned long waitMillisReport = 0;

    void setCom(SerialCom*);
    bool actionSerial(String*, int);
    void report();


private:
    VoltMeter voltMeter;

    void processData(String);
    void setReportDelay(float);
};
#endif /* STATUSCTR_H_ */
