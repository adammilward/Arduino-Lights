/*
 * LightCtr.h
 *
 *  Created on: 22 Feb 2017
 *      Author: Adam Milward
 */

#include "Light.h"
#include "Arduino.h"
#include "SerialCom.h"

#ifndef LightCtr_H_
#define LightCtr_H_


// applies commands from lights remote control
// to instances of lights (Red Green and Blue)
class LightCtr {
public:
    LightCtr();
    LightCtr(SerialCom&);

    static Light Red;
    static Light Green;
    static Light Blue;

    SerialCom com;

    enum controllerMode { STATIC, FADE };
    controllerMode ctrMode = controllerMode::STATIC;

    int delay = CONFIG::DELAY_MIN*2;

    bool actionSerial(String);
    bool actionSerial(String[], int);
    bool actionRemote(unsigned long);
    void interrupt();
    int holdCount = 0;          // count how long button pressed

private:

    enum colour { RED, GREEN, BLUE, WHITE };
    colour LightColour = colour::WHITE;
    float colourStore[4][3] = {
            {0.2, -1, -1}, // red
            {0.5, -1, 0.2}, // purple
            {0.5, 0.2, -1}, // turcoise
            {0.5, 0.2, 0.2}, // dim white
    };
    float tempStore[3] = {0,0,0}; // for light power while holding
    void retrieveStore(colour);
    void storeThis(colour);
    void half();
    void checkDelay();

    String remoteAlias[20] = {
        "up",   "down",   "on",   "off",
        "red",   "green",   "blue",   "white",
        "orange",   "yellow",   "cyan",   "purple",
        "j1",   "j2",   "j3",   "j4",
        "m1",   "m1",   "m1",   "m1"
    };
    String serialCommands[8][2] = {
            {"all", "up"},
            {"all", "down"},
            {"red", "up"},
            {"red", "down"},
            {"geen", "up"},
            {"green", "down"},
            {"blue", "up"},
            {"blue", "down"}
    };
    unsigned long int codes[20] = {
        0xFFA05F,   0xFF20DF,   0x000001,   0xFFE01F,
        0xFF906F,   0xFF10EF,   0xFF50AF,   0xFFD02F,
        0xFFB04F,   0xFF30CF,   0xFF708F,   0xFFF00F,
        0xFFA857,   0xFF28D7,   0xFF6897,   0xFFE817,
        0xFF9867,   0xFF18E7,   0xFF58A7,   0xFFD827
    };

    // declare the function pointer
    typedef void (LightCtr::*PTR)();
    PTR actions[2][20] = {
        {   // first array for static mode
&LightCtr::up,    &LightCtr::down,   &LightCtr::on,   &LightCtr::off   ,
&LightCtr::red,   &LightCtr::green,  &LightCtr::blue, &LightCtr::white ,
&LightCtr::orange,&LightCtr::yellow, &LightCtr::cyan, &LightCtr::purple,
&LightCtr::jump3, &LightCtr::jump7,  &LightCtr::fade3,&LightCtr::fade4 ,
&LightCtr::m1,    &LightCtr::m2,     &LightCtr::m3,   &LightCtr::m4    ,
        },
        {   // second array for fade mode
&LightCtr::up,    &LightCtr::down,   &LightCtr::on,   &LightCtr::off   ,
&LightCtr::red_f,   &LightCtr::green_f,  &LightCtr::blue, &LightCtr::white_f ,
&LightCtr::orange_f,&LightCtr::yellow_f, &LightCtr::cyan, &LightCtr::purple_f,
&LightCtr::jump3, &LightCtr::jump7,  &LightCtr::fade3,&LightCtr::fade4 ,
&LightCtr::m1,    &LightCtr::m2,     &LightCtr::m3,   &LightCtr::m4    ,
        }
    };
void up();      void down();    void on();      void off();
void red();     void green ();  void blue  ();  void white ();
void orange();  void yellow();  void cyan  ();  void purple();
void jump3 ();  void jump7 ();  void fade3 ();  void fade4 ();
void m1    ();  void m2    ();  void m3    ();  void m4    ();

void red_f();     void green_f ();                void white_f ();
void orange_f();  void yellow_f();                void purple_f();

};
#endif /* LightCtr_H_ */
