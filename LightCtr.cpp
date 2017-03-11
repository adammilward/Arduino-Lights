/*
 * LightCtr.cpp
 *
 *  Created on: 22 Feb 2017
 *      Author: Adam Milward
 */

#include "LightCtr.h"

Light LightCtr::Red(CONFIG::RED_PIN, 0.002, 0, 1);
Light LightCtr::Green(CONFIG::GREEN_PIN, 0.00181, 0, 0.7);
Light LightCtr::Blue(CONFIG::BLUE_PIN, 0.00173, 0, 0.7);

//Light::fadeMode Light::fMode = Light::EXP;

LightCtr::LightCtr() {

    //downPtr = &down;
    //LightColour = WHITE;
}
bool LightCtr::action(unsigned long inValue){
    for (int i = 0; i < 20; i++) {
        //Serial.println(i);
        if (codes[i] == inValue) {
            (this->*actions[i])();
            return true;
        }
    }
    return false;
}
void LightCtr::interrupt(){
    static int counter = 0;  // increments each repetition
    switch (counter) {
    case 1:
        // slide should not be more than 0.002 for sm0otheness
        Red.slide();
        break;
    case 2:
        Green.slide();
        break;
    case 3:
        Blue.slide();
        break;
    default:
        /*
        Serial.print(Red.base * 100);
        Serial.print(" ");
        Serial.print(Red.power);
        Serial.print(" ");
        Serial.print(Green.base * 100);
        Serial.print(" ");
        Serial.print(Green.power);
        Serial.print(" ");
        Serial.print(Blue.base * 100);
        Serial.print(" ");
        Serial.print(Blue.power);
        Serial.println(" ");
        */
        counter = 0;
        break;
    }
    counter++;
}

void LightCtr::up(){
    Serial.println("up");
    Red.shift(+1);
    Green.shift(+1);
    Blue.shift(+1);
}

void LightCtr::down(){
    Serial.println("down");
    Red.shift(-1);
    Green.shift(-1);
    Blue.shift(-1);
}
void LightCtr::on (){ //off
    Serial.println("on");
    Red.set(1);
    Green.set(1);
    Blue.set(1);
}
void LightCtr::off (){ //off
    Serial.println("off");
    Red.set(-1);
    Green.set(-1);
    Blue.set(-1);
}
void LightCtr::red   () {Red.shift(+1);}
void LightCtr::green () { Green.shift(+1); }
void LightCtr::blue  () { Blue.shift(+1); }
void LightCtr::white () { Blue.shift(+1); }
void LightCtr::orange() { Red.shift(-1); }
void LightCtr::yellow() { Green.shift(-1); }
void LightCtr::cyan  () { Blue.shift(-1); }
void LightCtr::purple() { Blue.shift(-1); }

void LightCtr::jump3 () {
    Serial.println("jump3()");
    if (holdCount == 0) {
        Serial.println("case 0");
        tempStore[0] = Red.base;
        tempStore[1] = Green.base;
        tempStore[2] = Blue.base;
        Serial.print(colourStore[0][0]);
        Serial.print(colourStore[0][1]);
        Serial.println(colourStore[0][2]);
        Red.set(colourStore[0][0]);
        Green.set(colourStore[0][1]);
        Blue.set(colourStore[0][2]);
        Light::fMode = Light::STATIC;
        holdCount++;
    } else if (holdCount == 4) {
        Serial.println("case 4");
        Red.set(tempStore[0]);
        Green.set(tempStore[1]);
        Blue.set(tempStore[2]);
        colourStore[0][0] = tempStore[0];
        colourStore[0][1] = tempStore[1];
        colourStore[0][2] = tempStore[2];
        holdCount = 0;
    } else {
        Serial.println("case 123");
        holdCount++;
    }
    Serial.print("holdCount ");
    Serial.println(holdCount);
}
void LightCtr::jump7 () {
    Red.set(colourStore[1][0]);
    Green.set(colourStore[1][1]);
    Blue.set(colourStore[1][2]);
    Light::fMode = Light::STATIC;
}
void LightCtr::fade3 () {
    Red.set(colourStore[2][0]);
    Green.set(colourStore[2][1]);
    Blue.set(colourStore[2][2]);
    Light::fMode = Light::STATIC;
}
void LightCtr::fade4 () {
    Red.set(colourStore[3][0]);
    Green.set(colourStore[3][1]);
    Blue.set(colourStore[3][2]);
    Light::fMode = Light::STATIC;
}

void LightCtr::m1    () {
    Light::fMode = Light::LIN;
    Serial.println(Light::fMode);
    Red.half();
    Green.half();
    Blue.half();
}
void LightCtr::m2    () {
    Light::fMode = Light::SIN;
    Serial.println(Light::fMode);
    Red.half();
    Green.half();
    Blue.half();
}
void LightCtr::m3    () {
    Light::fMode = Light::EXP;
    Serial.println(Light::fMode);
    Red.half();
    Green.half();
    Blue.half();
}
void LightCtr::m4    () {
    Light::fMode = Light::EXPSIN;
    Serial.println(Light::fMode);
    Red.half();
    Green.half();
    Blue.half();
}
