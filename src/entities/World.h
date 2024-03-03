#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class World {

    private:

        int16_t x = 0;
        int8_t sceneryVelocityIdxX = 0;

        int16_t backgroundX = 0;
        int16_t foregroundX = 0;
        
    public:

        int16_t getX()                                  { return this->x; }        
        int16_t getBackgroundX()                        { return this->backgroundX; }        
        int16_t getForegroundX()                        { return this->foregroundX; }        

        void setX(int16_t val)                          { this->x = val; }
        void setBackgroundX(int16_t val)                { this->backgroundX = val; }
        void setForegroundX(int16_t val)                { this->foregroundX = val; }

    public:

        bool update(uint8_t playerVelocityIdxX) {

            if (playerVelocityIdxX < this->sceneryVelocityIdxX) {

                this->sceneryVelocityIdxX--;
                
            }

            else if (playerVelocityIdxX > this->sceneryVelocityIdxX) {

                this->sceneryVelocityIdxX++;
                
            }

            this->backgroundX = this->backgroundX + (Constants::Velocity_X[this->sceneryVelocityIdxX] / 2);
            this->foregroundX = this->foregroundX - (Constants::Velocity_X[this->sceneryVelocityIdxX] / 2);
            
        }
};