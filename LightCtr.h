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
    void setCom(SerialCom*);

    static Light Red;
    static Light Green;
    static Light Blue;

    SerialCom *comPtr;

    enum controllerMode { STATIC, FADE };
    controllerMode ctrMode = controllerMode::STATIC;

    int delay = CONFIG::DELAY_MIN*2;

    bool actionSerial(String*, int);
    bool actionRemote(unsigned long);
    void interrupt();
    byte holdCount = 0;          // count how long button pressed

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

    void report();
    void reportRepeat(float delay = 0);
    void retrieveStore(colour);
    void storeThis(colour);
    void half();
    void checkDelay();

    bool actionOneWord(String*);
    bool actionTwoWords(String*);
    bool parseTwoWords(String*);
    bool actionWordAndFloat(String*, float);
    bool isNum(String*);

    byte remoteAliasLength = 20;
    String remoteAlias[20] = {
        "up",   "down",   "on",   "off",
        "red",   "green",   "blue",   "white",
        "orange",   "yellow",   "cyan",   "purple",
        "j1",   "j2",   "j3",   "j4",
        "m1",   "m2",   "m3",   "m4"
    };

    // declare the function pointer
    typedef void (LightCtr::*PTR)();
    typedef void (LightCtr::*PTR_f)(float);

    const static byte singleLength = 8;
    String oneWordCommands[singleLength] = {
            "report",
            "top",
            "bottom"
            "static",
            "lin",
            "sin",
            "exp",
            "sinexp"
    };
    PTR oneWordActions[singleLength]{
        &LightCtr::report,
        &LightCtr::allTop,
        &LightCtr::allBot,
        &LightCtr::fadeOff,
        &LightCtr::lin,
        &LightCtr::sin,
        &LightCtr::exp,
        &LightCtr::sinExp
    };

    const static byte firstOfTwoLength = 7;
    String firstOfTwoCommands[firstOfTwoLength] = {
            "all", "red", "green", "blue",
            "lower", "upper", "delay"
    };
    const static byte secondOfTwoLength = 5;
    String secondOfTwoCommands[secondOfTwoLength] = {
            "up", "down", "bottom", "top", "off"
    };

    const static byte wordAndFloatLength = 5;
    String wordAndFloatCommands[wordAndFloatLength] = {
            "report",
            "all",
            "red",
            "green",
            "blue",

    };
    PTR_f wordAndFloatActions[wordAndFloatLength] = {
            &LightCtr::reportRepeat,
            &LightCtr::allSet,
            &LightCtr::redSet,
            &LightCtr::greenSet,
            &LightCtr::blueSet,
    };

    PTR twoWordActions[firstOfTwoLength][secondOfTwoLength]{
{&LightCtr::allUp, &LightCtr::allDown, &LightCtr::allBot, &LightCtr::allTop, &LightCtr::off},// all
{&LightCtr::redUp, &LightCtr::redDown, &LightCtr::redBot, &LightCtr::redTop, &LightCtr::redOff},// red
{&LightCtr::greenUp, &LightCtr::greenDown, &LightCtr::greenBot, &LightCtr::greenTop, &LightCtr::greenOff},// green
{&LightCtr::blueUp, &LightCtr::blueDown, &LightCtr::blueBot, &LightCtr::blueTop, &LightCtr::blueOff},// blue
{&LightCtr::red_f, &LightCtr::orange_f, &LightCtr::lowerBot, &LightCtr::lowerTop, &LightCtr::null},// lower
{&LightCtr::green_f, &LightCtr::yellow_f, &LightCtr::upperBot, &LightCtr::upperTop, &LightCtr::null },// upper
{&LightCtr::white_f, &LightCtr::purple_f, &LightCtr::delayBot, &LightCtr::delayTop, &LightCtr::null }// delay
    };

    unsigned long int codes[20] = {
        0xFFA05F,   0xFF20DF,   0x000001,   0xFFE01F,
        0xFF906F,   0xFF10EF,   0xFF50AF,   0xFFD02F,
        0xFFB04F,   0xFF30CF,   0xFF708F,   0xFFF00F,
        0xFFA857,   0xFF28D7,   0xFF6897,   0xFFE817,
        0xFF9867,   0xFF18E7,   0xFF58A7,   0xFFD827
    };
    PTR actions[2][20] = {
        {   // first array for static mode
&LightCtr::allUp,    &LightCtr::allUp,   &LightCtr::on,   &LightCtr::off   ,
&LightCtr::redUp,   &LightCtr::greenUp,  &LightCtr::blueUp, &LightCtr::blueUp ,
&LightCtr::redDown,&LightCtr::greenDown, &LightCtr::blueDown, &LightCtr::blueDown,
&LightCtr::store1, &LightCtr::store2,  &LightCtr::store3,&LightCtr::store4 ,
 &LightCtr::lin,    &LightCtr::sin,     &LightCtr::exp,   &LightCtr::sinExp    ,
        },
        {   // second array for fade mode
&LightCtr::allUp,    &LightCtr::allDown,   &LightCtr::on,   &LightCtr::off   ,
&LightCtr::red_f,   &LightCtr::green_f,  &LightCtr::white_f, &LightCtr::white_f ,
&LightCtr::orange_f,&LightCtr::yellow_f, &LightCtr::purple_f, &LightCtr::purple_f,
&LightCtr::store1, &LightCtr::store2,  &LightCtr::store3,&LightCtr::store4 ,
&LightCtr::lin,    &LightCtr::sin,     &LightCtr::exp,   &LightCtr::sinExp    ,
        }
    };
void allUp();      void allDown();    void on();      void off();
void redUp();     void greenUp ();                  void blueUp ();
void redDown();  void greenDown();                  void blueDown();
void store1 ();  void store2 ();  void store3();  void store4 ();
void lin    ();  void sin    ();  void exp    ();  void sinExp    ();

void red_f();     void green_f ();                void white_f ();
void orange_f();  void yellow_f();                void purple_f();

void fadeOff();

void allSet(float);
void redSet(float);
void greenSet(float);
void blueSet(float);

void allBot(); void allTop();
void redBot(); void redTop(); void redOff();
void greenBot(); void greenTop(); void greenOff();
void blueBot(); void blueTop(); void blueOff();
void lowerBot(); void lowerTop();
void upperBot(); void upperTop();
void delayBot(); void delayTop();

void null();

};
#endif /* LightCtr_H_ */
