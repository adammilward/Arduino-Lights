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

#ifndef REMOTERECEIVE_H_
#define REMOTERECEIVE_H_

class Controller {
public:
    Controller();
    const unsigned long int IR_HOLD = 0xFFFFFFFF;
    LightCtr LightRemote;
    static SoftwareSerial BTs;
    void irReceive(unsigned long value);
    void serialReceive(String data);


private:
    enum Mode {LIGHTS, MP3};
    Mode mode;
    String command[CONFIG::COMMAND_LENGTH];
    String lastCommand;
    unsigned long int storedCode = 0;  // for sending when hold is pressed
    void irDecode(unsigned long, int);
    bool processSerial();

};
#endif /* REMOTERECEIVE_H_ */
