#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class World {

    private:

        int16_t x = 0;
        int16_t y = 0;

        int16_t backgroundX = 0;
        int16_t backgroundY = 0;
        int16_t foregroundX = 0;
        int16_t foregroundY = 0;
        
    public:

        int16_t getX()                                  { return this->x; }        
        int16_t getBackgroundX()                        { return this->backgroundX; }        
        int16_t getForegroundX()                        { return this->foregroundX; }        
        int16_t getY()                                  { return this->y; }        
        int16_t getBackgroundY()                        { return this->backgroundY; }        
        int16_t getForegroundY()                        { return this->foregroundY; }        

        void setX(int16_t val)                          { this->x = val; }
        void setBackgroundX(int16_t val)                { this->backgroundX = val; }
        void setForegroundX(int16_t val)                { this->foregroundX = val; }
        void setY(int16_t val)                          { this->y = val; }
        void setBackgroundY(int16_t val)                { this->backgroundY = val; }
        void setForegroundY(int16_t val)                { this->foregroundY = val; }

    public:

        // bool update(int16_t playerX) {

        // }
};