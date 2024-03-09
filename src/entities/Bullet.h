#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Bullet {

    private:

        Direction direction = Direction::Right;
        float x = 40;
        float y = 47;
        bool active = false;
        
    public:

        Direction getDirection()                        { return this->direction; }
        float getX()                                    { return this->x; }        
        float getY()                                    { return this->y; }        
        bool isActive()                                 { return this->active; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setX(float val)                            { this->x = val; }
        void setY(float val)                            { this->y = val; }
        void setActive(bool val)                        { this->active = val; }

    public:

        bool update(int16_t playerX) {


            switch (this->direction) {

                case Direction::Right:
                    this->x = this->x + 4;
                    break;

                case Direction::Left:
                    this->x = this->x - 4;
                    break;

            }

            int16_t xDiff = abs(playerX - this->x);

            if (xDiff > 150) { this->active = false; }

            return true;

        }
};