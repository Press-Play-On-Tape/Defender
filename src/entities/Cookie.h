#pragma once

#include <ArduboyFX.h>  
#include "../utils/Constants.h"

struct Cookie {

    bool hasSavedGame;
    SoundSettings soundSettings;

    uint8_t health = Constants::HealthMax;
    uint8_t healthBlink = 0;
    uint16_t score = 0;
    uint16_t highScore = 0;

    void decHealth(uint8_t val) {

        if (this->health > val) {
            this->health = this->health - val;
        }
        else {
            this->health = 0;
        }

        if (this->healthBlink == 0) {
            this->healthBlink = this->healthBlink + 15;
        }
        else if (this->healthBlink < 84) {
            this->healthBlink = this->healthBlink + 32;
        }
        
    }

    void incHealth(uint8_t val) {

        if (this->health + val < Constants::HealthMax) {
            this->health = this->health + val;
        }
        else {
            this->health = Constants::HealthMax;
        }

        if (this->healthBlink == 0) {
            this->healthBlink = this->healthBlink + 15;
        }
        else if (this->healthBlink < 84) {
            this->healthBlink = this->healthBlink + 32;
        }
        
    }

};
