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
    comPtr = 0;
}

void LightCtr::setCom(SerialCom *inCom) {
    comPtr = inCom;
    Red.setCom(inCom);
    Green.setCom(inCom);
    Blue.setCom(inCom);
}

bool LightCtr::actionSerial(String* firstWordPtr, int arrayLength){
    bool actioned = false;
    if (1 == arrayLength) {
        actioned = actionOneWord(firstWordPtr);
    } else if (2 == arrayLength) {
        actioned = actionTwoWords(firstWordPtr);
    }
    if (!actioned) {
        comPtr->out("Command not recognised, options are:");
        comPtr->out("the name of a button on the remote;");
        comPtr->out("'report';");
        comPtr->out("'red/green/blue/all'  'up/down/top/bottom'; ");
        comPtr->out("setting with numbers has not been configured");
    }
    return actioned;
}

bool LightCtr::actionOneWord(String* word){
    int i = remoteAliasLength;
    while (i --) {
        comPtr->debug("mode= "+String(ctrMode)+" index= "+String(i));
        if (remoteAlias[i] == *word) {
            (this->*actions[ctrMode][i])();
            return true;
        }
    }
    if (*word == "report") {
        report();
        return true;
    }
    return false;
}

bool LightCtr::actionTwoWords(String* firstWordPtr){
    int i = firstOfTwoLength;
    while (i --) {
        comPtr->debug("index= "+String(i));
        if (firstOfTwoCommands[i] == *firstWordPtr) {
            int j = secondOfTwoLength;
            while (j --) {
                comPtr->debug("Jindex= "+String(j));
                if (secondOfTwoCommands[j] == *(firstWordPtr+1)) {
                    (this->*twoWordActions[i][j])();
                    return true;
                }
            }
        }
    }
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

void LightCtr::report() {
    comPtr->out("Red      base: "+String(Red.base)+
        "  power: "+String(Red.power));
    comPtr->out("Green  base: "+String(Green.base)+
        "  power: "+String(Green.power));
    comPtr->out("Blue     base: "+String(Blue.base)+
        "  power: "+String(Blue.power));
    comPtr->out("Red      gain: "+String(Red.gain));
    comPtr->out("Green  gain: "+String(Green.gain));
    comPtr->out("Blue     gain: "+String(Blue.gain));
    comPtr->out("Red      lower: "+String(Red.lower)+
        "  range: "+String(Red.range));
    comPtr->out("Green  lower: "+String(Green.lower)+
        "  range: "+String(Green.range));
    comPtr->out("Blue     lower: "+String(Blue.lower)+
        "  range: "+String(Blue.range));
    if (STATIC == ctrMode) {
        comPtr->out("Mode: STATIC");
    } else {
        comPtr->outWd("FadeMode: ");
        comPtr->outWd(Light::fadeModes[Light::fMode]);
        comPtr->out("Delay: "+String(delay));
    }
}

void LightCtr::interrupt(){
    static int counter = 0;  // increments each repetition
    switch (counter) {
    case 1:
        // slide should not be more than 0.002 for smootheness
        Red.slide();
        break;
    case 2:
        Green.slide();
        break;
    case 3:
        Blue.slide();
        break;
    default:
comPtr->debugWd(String(Red.base * 100)+"    "+String(Red.power)+"    ");
comPtr->debugWd(String(Green.base * 100)+"    "+String(Green.power)+"    ");
comPtr->debug(String(Blue.base * 100)+"    "+String(Blue.power)+"    ");
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
    Red.set(0.5);
    Green.set(0.5);
    Blue.set(0.5);
}
void LightCtr::off (){ //off
    //Serial.println("off");
    Red.set(-1);
    Green.set(-1);
    Blue.set(-1);
    ctrMode = STATIC;
}
void LightCtr::red   () { Red.shift(+1);}
void LightCtr::green () { Green.shift(+1); }
void LightCtr::white () { Blue.shift(+1); }
void LightCtr::orange() { Red.shift(-1); }
void LightCtr::yellow() { Green.shift(-1); }
void LightCtr::purple() { Blue.shift(-1); }

void LightCtr::allBot(){
    Red.set(0);
    Green.set(0);
    Blue.set(0);
}
void LightCtr::allTop(){
    Red.set(1);
    Green.set(1);
    Blue.set(1);
}
void LightCtr::redBot() { Red.set(0);}
void LightCtr::redTop() { Red.set(1);}
void LightCtr::greenBot() { Green.set(0);}
void LightCtr::greenTop() { Green.set(1);}
void LightCtr::blueBot() { Blue.set(0);}
void LightCtr::blueTop() { Blue.set(1);}
void LightCtr::lowerBot() {
    Red.changeLower(-1, 1);
    Green.changeLower(-1, 1);
    Blue.changeLower(-1, 1);
}
void LightCtr::lowerTop() {
    Red.changeLower(1, 1);
    Green.changeLower(1, 1);
    Blue.changeLower(1, 1);
}
void LightCtr::upperBot() {
    Red.changeUpper(-1, 1);
    Green.changeUpper(-1, 1);
    Blue.changeUpper(-1, 1);
}
void LightCtr::upperTop() {
    Red.changeUpper(1, 1);
    Green.changeUpper(1, 1);
    Blue.changeUpper(1, 1);
}
void LightCtr::delayBot(){
    delay = CONFIG::DELAY_MIN-1;
    checkDelay();
    comPtr->out("delay= "+String(delay));
}
void LightCtr::delayTop() {
    delay = CONFIG::DELAY_MAX+1;
    checkDelay();
    comPtr->out("delay= "+String(delay));
}

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
}
void LightCtr::orange_f (){
    Red.changeLower(-1, 0.2);
    Green.changeLower(-1, 0.2);
    Blue.changeLower(-1, 0.2);
}
void LightCtr::green_f (){
    Red.changeUpper(+1, 0.2);
    Green.changeUpper(+1, 0.2);
    Blue.changeUpper(+1, 0.2);
}
void LightCtr::yellow_f(){
    Red.changeUpper(-1, 0.2);
    Green.changeUpper(-1, 0.2);
    Blue.changeUpper(-1, 0.2);
}
void LightCtr::white_f(){
    delay *= 4;
    checkDelay();
    //Serial.print("delay  ");
    //Serial.println(delay);
}
void LightCtr::purple_f(){
    delay /= 4;
    checkDelay();
    comPtr->out("delay= "+String(delay));
    //Serial.print("delay  ");
    //Serial.println(delay);
}
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

