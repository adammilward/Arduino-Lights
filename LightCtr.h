/*
 * LightCtr.h
 *
 *  Created on: 22 Feb 2017
 *      Author: Adam Milward
 */

#include "Light.h"
#include "Arduino.h"


#ifndef LightCtr_H_
#define LightCtr_H_


// applies commands from lights remote control
// to instances of lights (Red Green and Blue)
class LightCtr {
public:
    LightCtr();

    static Light Red;
    static Light Green;
    static Light Blue;

    // mode for automatic fading
    //enum fadeMode { STATIC, LIN, SIN, EXP, EXPSIN };
    //static fadeMode fMode;

    bool action(unsigned long value);
    void interrupt();
    int holdCount = 0;          // count how long button pressed

protected:
    enum colour { RED, GREEN, BLUE, WHITE };
    colour LightColour = colour::WHITE;
    float colourStore[4][3] = {
            {0.2, -1, -1}, // red
            {0.5, -1, 0.2}, // purcle
            {0.5, 0.2, -1}, // turqoise
            {0.5, 0.2, 0.2}, // dim white
    };
    float tempStore[3] = {0,0,0}; // for light power while holding
    void retrieveStore(colour);
    void storeThis(colour);
    void half();

    typedef void (LightCtr::*PTR)();
    unsigned long int codes[20] = {
        0xFFA05F,   0xFF20DF,   0x000001,   0xFFE01F,
        0xFF906F,   0xFF10EF,   0xFF50AF,   0xFFD02F,
        0xFFB04F,   0xFF30CF,   0xFF708F,   0xFFF00F,
        0xFFA857,   0xFF28D7,   0xFF6897,   0xFFE817,
        0xFF9867,   0xFF18E7,   0xFF58A7,   0xFFD827
    };
    PTR actions[20] = {
&LightCtr::up,    &LightCtr::down,   &LightCtr::on,   &LightCtr::off   ,
&LightCtr::red,   &LightCtr::green,  &LightCtr::blue, &LightCtr::white ,
&LightCtr::orange,&LightCtr::yellow, &LightCtr::cyan, &LightCtr::purple,
&LightCtr::jump3, &LightCtr::jump7,  &LightCtr::fade3,&LightCtr::fade4 ,
&LightCtr::m1,    &LightCtr::m2,     &LightCtr::m3,   &LightCtr::m4    ,
    };
void up();      void down();    void on();      void off();
void red();     void green ();  void blue  ();  void white ();
void orange();  void yellow();  void cyan  ();  void purple();
void jump3 ();  void jump7 ();  void fade3 ();  void fade4 ();
void m1    ();  void m2    ();  void m3    ();  void m4    ();

};
#endif /* LightCtr_H_ */
