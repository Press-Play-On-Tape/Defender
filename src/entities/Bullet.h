#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Bullet {

    private:

        Direction direction = Direction::East;
        int16_t x = 40;
        int16_t y = 47;
        bool active = false;
        
    public:

        Direction getDirection()                        { return this->direction; }
        int8_t getX_Screen()                            { return (this->x / 16) - 8; }        
        int8_t getY_Screen()                            { return (this->y / 16) - 2; }        
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        
        bool isActive()                                 { return this->active; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }
        void setActive(bool val)                        { this->active = val; }

    public:

        bool update(int16_t playerX) {


            switch (this->direction) {

                case Direction::East:
                    this->x = this->x + 64;
                    break;

                case Direction::West:
                    this->x = this->x - 64;
                    break;

            }

            int16_t xDiff = abs(playerX - this->x);

            if (xDiff > 2400) { this->active = false; }

            return true;

        }
};