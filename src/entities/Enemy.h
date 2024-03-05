#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Enemy {

    private:

        Direction direction = Direction::Left;
        Speed speed = Speed::Slow;
        int16_t x = 0;
        int16_t y = 0;
        bool active = false;
        
    public:

        Direction getDirection()                        { return this->direction; }
        Speed getSpeed()                                { return this->speed; }
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        
        bool isActive()                                 { return this->active; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setSpeed(Speed val)                        { this->speed = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }
        void setActive(bool val)                        { this->active = val; }

    public:

        void update() {

            switch (this->direction) {

                case Direction::Left:

                    switch (this->speed) {

                        case Speed::Slow:
                            this->x = this->x - 24;
                            break;

                        case Speed::Medium:
                            this->x = this->x - 32;
                            break;

                        case Speed::Fast:
                            this->x = this->x - 48;
                            break;
                            
                    }

                    break;

                case Direction::Right:

                    switch (this->speed) {

                        case Speed::Slow:
                            this->x = this->x + 24;
                            break;

                        case Speed::Medium:
                            this->x = this->x + 32;
                            break;

                        case Speed::Fast:
                            this->x = this->x + 48;
                            break;
                            
                    }
                    
                    break;
            
                default:
                    break;

            }

        }

};