#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"

uint8_t getJustPressedButtons() {

    a.pollButtons();

    return a.justPressedButtons();

}

uint8_t getPressedButtons() {

    return a.pressedButtons();

}

void saveCookie(bool enableLEDs) {

    #ifdef USE_LED
    if (enableLEDs) {
        #ifndef MICROCADE
            a.setRGBled(RED_LED, 32);
        #else
            a.setRGBledGreenOff();
            a.setRGBledBlueOff();
        #endif
    }
    #endif

    FX::saveGameState(cookie);

    #ifdef USE_LED
    if (enableLEDs) {
        #ifndef MICROCADE
            a.setRGBled(RED_LED, 0);
            a.setRGBled(GREEN_LED, 32);
        #else
            a.setRGBledRedOff();
            a.setRGBledGreenOn();
        #endif
    }
    #endif

}

void deactivateLEDs() {

    #ifdef USE_LED
        #ifndef MICROCADE
            a.setRGBled(0, 0, 0);
        #else
            a.setRGBledRedOff();
            a.setRGBledGreenOff();
            a.setRGBledBlueOff();
        #endif
    #endif

}

void decHealth(uint8_t val) {

    if (health > val) {
        health = health - val;
    }
    else {
        health = 0;
    }

    if (healthBlink == 0) {
        healthBlink = healthBlink + 15;
    }
    else if (healthBlink < 84) {
        healthBlink = healthBlink + 32;
    }
    
}

void incHealth(uint8_t val) {

    if (health + val < Constants::HealthMax) {
        health = health + val;
    }
    else {
        health = Constants::HealthMax;
    }

    if (healthBlink == 0) {
        healthBlink = healthBlink + 15;
    }
    else if (healthBlink < 84) {
        healthBlink = healthBlink + 32;
    }
    
}