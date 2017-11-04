/*
 * SerialCom.h
 *
 *  Created on: 4 Nov 2017
 *      Author: Adam Milward
 */

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "Config.h"

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

class SerialCom {
public:
    SerialCom();

    static SoftwareSerial BT;
    void outLn(String);
    void outWd(String);
};

#endif /* SERIALCOM_H_ */
