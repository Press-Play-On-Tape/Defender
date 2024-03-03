#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Enemy {

    private:

        Movement movement = Movement::Middle;
        Speed speed = Speed::Slow;
        int8_t directionMovement = 1;
        int16_t x = 40;
        int16_t y = 47;
        bool active = false;
        
    public:

        Movement getMovement()                          { return this->movement; }
        Speed getSpeed()                                { return this->speed; }
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        
        bool isActive()                                 { return this->active; }        

        void setMovement(Movement val)                  { this->movement = val; }
        void setSpeed(Speed val)                        { this->speed = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }
        void setActive(bool val)                        { this->active = val; }

    public:

};