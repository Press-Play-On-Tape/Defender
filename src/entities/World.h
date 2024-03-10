#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class World {

    private:

        SQ15x16 x = 0;
        int8_t sceneryVelocityIdxX = 0;

        SQ15x16 backgroundX = 0;
        SQ15x16 foregroundX = 0;
        
    public:

        SQ15x16 getX()                                  { return this->x; }        
        SQ15x16 getBackgroundX()                        { return this->backgroundX; }        
        SQ15x16 getForegroundX()                        { return this->foregroundX; }        

        void setX(SQ15x16 val)                          { this->x = val; }
        void setBackgroundX(SQ15x16 val)                { this->backgroundX = val; }
        void setForegroundX(SQ15x16 val)                { this->foregroundX = val; }

    public:

        bool update(uint8_t playerVelocityIdxX) {

            if (playerVelocityIdxX < this->sceneryVelocityIdxX) {

                this->sceneryVelocityIdxX--;
                
            }

            else if (playerVelocityIdxX > this->sceneryVelocityIdxX) {

                this->sceneryVelocityIdxX++;
                
            }

            this->backgroundX = this->backgroundX + (static_cast<SQ15x16>(Constants::Velocity_X[this->sceneryVelocityIdxX]) / 32);
            this->foregroundX = this->foregroundX - (static_cast<SQ15x16>(Constants::Velocity_X[this->sceneryVelocityIdxX]) / 32);
            
        }
};