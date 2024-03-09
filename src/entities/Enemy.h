#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Enemy {

    private:

        Direction direction = Direction::Left;
        float speed = 0;
        float x = 0;
        float y = 0;
        bool active = false;
        
    public:

        Direction getDirection()                        { return this->direction; }
        float getSpeed()                                { return this->speed; }
        float getX()                                    { return this->x; }        
        float getY()                                    { return this->y; }        
        bool isActive()                                 { return this->active; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setSpeed(float val)                        { this->speed = val; }
        void setX(float val)                            { this->x = val; }
        void setY(float val)                            { this->y = val; }
        void setActive(bool val)                        { this->active = val; }

    public:

        void update() {

            switch (this->direction) {

                case Direction::Left:

                    this->x = this->x - this->speed;
                    break;

                case Direction::Right:

                    this->x = this->x + this->speed;
                    break;
            
                default:
                    break;

            }

        }

};