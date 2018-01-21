/*
 * RemoteReceive.h
 *
 *  Created on: 20 Feb 2017
 *      Author: Adam Milward
 */

#include "LightCtr.h"
#include "StatusCtr.h"

#ifndef REMOTERECEIVE_H_
#define REMOTERECEIVE_H_

class Controller {
public:
    Controller(SerialCom*);
    SerialCom *comPtr;
    const unsigned long int IR_HOLD = 0xFFFFFFFF;
    StatusCtr statusCtr;
    void irReceive(unsigned long value);
    void serialReceive(String data);
    void timer(unsigned long);
#ifdef LIGHS
    LightCtr lightCtr;
#endif
private:

    enum IRMode {IR_LIGHTS, IR_MP3};
    IRMode iRMode = IR_LIGHTS;
    enum Mode {LIGHTS, STATUS, COM};
    Mode mode = STATUS;

    byte lastCommandLength = 1;
    String lastCommand[CONFIG::COMMAND_MAX_LENGTH] =  {"repot"};
    unsigned long int storedCode = 0;  // for sending when hold is pressed

    bool checkForRepeat(String);
    bool checkForMode(String*, int);
    void irDecode(unsigned long, int);
    bool processSerial(String*, int);
    void help();
    void copy(String*, String*, int);
};
#endif /* REMOTERECEIVE_H_ */
