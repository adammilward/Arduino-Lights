/*
 * LightCtr.cpp
 *
 *  Created on: 22 Feb 2017
 *      Author: Adam Milward
 */

#include "LightCtr.h"

Light LightCtr::Red(CONFIG::RED_PIN, 0);
Light LightCtr::Green(CONFIG::GREEN_PIN, 1);
Light LightCtr::Blue(CONFIG::BLUE_PIN, 2);


LightCtr::LightCtr() {
    comPtr = NULL;
}

void LightCtr::setCom(SerialCom *inCom) {
    comPtr = inCom;
}

bool LightCtr::actionSerial(String data){
    comPtr->outLn("Status Mode");
    comPtr->outLn("lightRemote actionSerial()");
    return true;
}

bool LightCtr::actionSerial(String command[], int arrayLength){

    for ( int i = 0 ; i <= arrayLength ; i++ ) comPtr->outLn(command[i]);

    for (byte i = 0; i < 20; i++) {
        if (remoteAlias[i] == command[0]) {
            (this->*actions[ctrMode][i])();
            return true;
        }
    }
    for (byte i = 0; i < 20; i++) {
        //Serial.println(i); // don't know why this fails if it is removed
        // todo add nested loop to look for successive commands
        if (serialCommands[i][1] == command[0]) {
            (this->*actions[ctrMode][i])();
            return true;
        }
    }
    Serial.println("command not found");
    return false;
}
bool LightCtr::actionRemote(unsigned long inValue){
    for (int i = 0; i < 20; i++) {
        //Serial.print(ctrMode);
        //Serial.print("    ");
        //Serial.println(i);
        if (codes[i] == inValue) {
            (this->*actions[ctrMode][i])();
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

        counter = 0;
        break;
    }
    counter++;
}
void LightCtr::retrieveStore(colour inColour){
    //Serial.print("retrieveStore Colour: ");
    //Serial.println(inColour);
    tempStore[0] = Red.base;
    tempStore[1] = Green.base;
    tempStore[2] = Blue.base;
    //Serial.print("Stored Values: ");
    //Serial.print(colourStore[inColour][0]);
    //Serial.print(colourStore[inColour][1]);
    //Serial.println(colourStore[inColour][2]);
    Red.set(colourStore[inColour][0]);
    Green.set(colourStore[inColour][1]);
    Blue.set(colourStore[inColour][2]);
    ctrMode = STATIC;
}
void LightCtr::storeThis(colour inColour){
    //Serial.print("store New Colour ");
    //Serial.println(inColour);
    Red.set(tempStore[0]);
    Green.set(tempStore[1]);
    Blue.set(tempStore[2]);
    colourStore[inColour][0] = tempStore[0];
    colourStore[inColour][1] = tempStore[1];
    colourStore[inColour][2] = tempStore[2];
    //Serial.print("Stored Values: ");
    //Serial.print(colourStore[inColour][0]);
    //Serial.print(colourStore[inColour][1]);
    //Serial.println(colourStore[inColour][2]);
}
void LightCtr::up(){
    //Serial.println("up");
    Red.shift(+1);
    Green.shift(+1);
    Blue.shift(+1);
}

void LightCtr::down(){
    //Serial.println("down");
    Red.shift(-1);
    Green.shift(-1);
    Blue.shift(-1);
}
void LightCtr::on (){ //off
    //Serial.println("on");
    Red.set(1);
    Green.set(1);
    Blue.set(1);
}
void LightCtr::off (){ //off
    //Serial.println("off");
    Red.set(-1);
    Green.set(-1);
    Blue.set(-1);
    ctrMode = STATIC;
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
    //Serial.println("jump3()");
    if (holdCount == 0) {
        retrieveStore(RED);
    } else if (holdCount == 4) {
        storeThis(RED);
    }
    //Serial.print("holdCount ");
    //Serial.println(holdCount);
}
void LightCtr::jump7 () {
    if (holdCount == 0) {
        retrieveStore(GREEN);
    } else if (holdCount == 4) {
        storeThis(GREEN);
    }
}
void LightCtr::fade3 () {
    if (holdCount == 0) {
        retrieveStore(BLUE);
    } else if (holdCount == 4) {
        storeThis(BLUE);
    }
}
void LightCtr::fade4 () {
    if (holdCount == 0) {
        retrieveStore(WHITE);
    } else if (holdCount == 4) {
        storeThis(WHITE);
    }
}
void LightCtr::m1    () {
    ctrMode = FADE;
    Light::fMode = Light::LIN;
    //Serial.println(Light::fMode);
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}
void LightCtr::m2    () {
    ctrMode = FADE;
    Light::fMode = Light::SIN;
    //Serial.println(Light::fMode);
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}
void LightCtr::m3    () {
    ctrMode = FADE;
    Light::fMode = Light::EXP;
    //Serial.println(Light::fMode);
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}
void LightCtr::m4    () {
    ctrMode = FADE;
    Light::fMode = Light::EXPSIN;
    //Serial.println(Light::fMode);
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}

void LightCtr::red_f(){
    Red.changeLower(+1, 0.2);
    Green.changeLower(+1, 0.2);
    Blue.changeLower(+1, 0.2);
};
void LightCtr::orange_f (){
    Red.changeLower(-1, 0.2);
    Green.changeLower(-1, 0.2);
    Blue.changeLower(-1, 0.2);
};
void LightCtr::green_f (){
    Red.changeUpper(+1, 0.2);
    Green.changeUpper(+1, 0.2);
    Blue.changeUpper(+1, 0.2);
};
void LightCtr::yellow_f(){
    Red.changeUpper(-1, 0.2);
    Green.changeUpper(-1, 0.2);
    Blue.changeUpper(-1, 0.2);
};
void LightCtr::white_f(){
    delay *= 4;
    checkDelay();
    //Serial.print("delay  ");
    //Serial.println(delay);
};
void LightCtr::purple_f(){
    delay /= 4;
    checkDelay();
    //Serial.print("delay  ");
    //Serial.println(delay);
};
void LightCtr::checkDelay(){
    if (delay > CONFIG::DELAY_MAX) {
        delay = CONFIG::DELAY_MAX;
        Red.flashHalf();
        Green.flashHalf();
        Blue.flashHalf();
    } else if (delay < CONFIG::DELAY_MIN) {
        delay = CONFIG::DELAY_MIN;
        Red.flashHalf();
        Green.flashHalf();
        Blue.flashHalf();
    }
        Red.flashOff();
        Green.flashOff();
        Blue.flashOff();
        Serial.println(delay);
}

