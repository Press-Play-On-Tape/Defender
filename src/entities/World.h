#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class World {

    private:

        float x = 0;
        int8_t sceneryVelocityIdxX = 0;

        float backgroundX = 0;
        float foregroundX = 0;
        
    public:

        float getX()                                  { return this->x; }        
        float getBackgroundX()                        { return this->backgroundX; }        
        float getForegroundX()                        { return this->foregroundX; }        

        void setX(float val)                          { this->x = val; }
        void setBackgroundX(float val)                { this->backgroundX = val; }
        void setForegroundX(float val)                { this->foregroundX = val; }

    public:

        bool update(uint8_t playerVelocityIdxX) {

            if (playerVelocityIdxX < this->sceneryVelocityIdxX) {

                this->sceneryVelocityIdxX--;
                
            }

            else if (playerVelocityIdxX > this->sceneryVelocityIdxX) {

                this->sceneryVelocityIdxX++;
                
            }

            this->backgroundX = this->backgroundX + (static_cast<float>(Constants::Velocity_X[this->sceneryVelocityIdxX]) / 32);
            this->foregroundX = this->foregroundX - (static_cast<float>(Constants::Velocity_X[this->sceneryVelocityIdxX]) / 32);
            
        }
};