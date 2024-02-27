#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Player {

    private:

        PlayerMovement playerMovement = PlayerMovement::Up_Middle;

        Direction direction = Direction::East;
        int8_t xMovement = 13;

        int16_t x = 5000 + (64 - 4) * 16;
        int16_t y = Constants::Player_YMax - Constants::Player_Offset;
        int16_t xScreen = 5000 + (64 - 4) * 16;
        int16_t yScreen = 16 * 16;
        

    public:

        PlayerMovement getMovement()                    { return this->playerMovement; }
        Direction getDirection()                        { return this->direction; }
        int8_t getXMovement()                           { return this->xMovement; }
        // int8_t getX_Screen()                            { return this->xScreen / 16; }        
        int8_t getY_Screen()                            { return this->yScreen / 16; }        
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        

        void setMovement(PlayerMovement val)            { this->playerMovement = val; }
        void setXMovement(int8_t val)                   { this->xMovement = val; }
        void setDirection(Direction val)                { this->direction = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }

    public:

        void accelerate(Direction direction) {

            switch (direction) {

                case Direction::West:

                    if (this->xMovement > 0) this->xMovement--;
                    break;

                case Direction::East:

                    if (this->xMovement < 28) this->xMovement++;
                    break;

            }

            if (this->xMovement < 14) {

                this->direction = Direction::West;

            }
            else {

                this->direction = Direction::East;

            }

        }

};