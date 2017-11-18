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
    StatusCtr(SerialCom&);
    SerialCom com;

    bool actionSerial(String);

private:
    VoltMeter voltMeter;

    void processData(String);
    void report();
};
#endif /* STATUSCTR_H_ */
