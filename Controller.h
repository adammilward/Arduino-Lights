/*
 * RemoteReceive.h
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */
#include "Arduino.h"
#include "LightCtr.h"
#include "SoftwareSerial.h"
#include "Config.h"
#include "SerialCom.h"
#include "StatusCtr.h"

#ifndef REMOTERECEIVE_H_
#define REMOTERECEIVE_H_

class Controller {
public:
    Controller(SerialCom*);
    SerialCom *comPtr;
    const unsigned long int IR_HOLD = 0xFFFFFFFF;
    LightCtr lightRemote;
    StatusCtr statusCtr;
    static SoftwareSerial BTs;
    void irReceive(unsigned long value);
    void serialReceive(String data);

private:

    enum IRMode {IR_LIGHTS, IR_MP3};
    IRMode iRMode = IR_LIGHTS;
    enum Mode {LIGHT, STATUS, COM};
    Mode mode = STATUS;
    String oldData = "report";
    String newCommand[CONFIG::COMMAND_MAX_LENGTH];
    String oldCommand[CONFIG::COMMAND_MAX_LENGTH];
    unsigned long int storedCode = 0;  // for sending when hold is pressed

    bool checkForRepeat(String);
    void checkForMode(String);
    void irDecode(unsigned long, int);
    void processSerial(String);

};
#endif /* REMOTERECEIVE_H_ */
