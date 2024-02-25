#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Player {

    private:

        PlayerMovement playerMovement = PlayerMovement::Up_Middle;

        uint8_t direction = 6;
        int8_t xMovement = 13;

        int16_t x = 40 * 16;
        int16_t y = Constants::Player_YMax - Constants::Player_Offset;
        int16_t xScreen = 40 * 16;
        int16_t yScreen = Constants::Player_YMax - Constants::Player_Offset;
        

    public:

        PlayerMovement getMovement()                    { return this->playerMovement; }
        uint8_t getDirection()                          { return this->direction; }
        int8_t getXMovement()                           { return this->xMovement; }
        int8_t getX_Screen()                            { return this->xScreen / 16; }        
        int8_t getY_Screen()                            { return this->yScreen / 16; }        
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        

        void setMovement(PlayerMovement val)            { this->playerMovement = val; }
        void setXMovement(int8_t val)                   { this->xMovement = val; }
        void setDirection(uint8_t val)                  { this->direction = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }

    public:

        void shoot() {

            this->playerMovement = static_cast<PlayerMovement>(this->direction + (this->y <= 8 ? 13 : 0));

            if (static_cast<int16_t>(this->y) >= static_cast<int16_t>(Constants::Player_YMax - Constants::Player_Offset)) {
                this->y = this->y + Constants::Player_Offset;
            }

        }

        void accelerate(Direction direction) {

            // switch (direction) {

            //     case Direction::West:

            //         switch (this->xMovement) {

            //             case -14 ... -5:
            //                 this->xMovement = this->xMovement - 2;
            //                 break;

            //             case -4 ... 4:
            //                 this->xMovement = this->xMovement - 1;
            //                 break;

            //             case 5 ... 127:
            //                 this->xMovement = this->xMovement - 2;
            //                 break;

            //         }

            //         break;

            //     case Direction::East:

            //         switch (this->xMovement) {

            //             case -127 ... -5:
            //                 this->xMovement = this->xMovement + 2;
            //                 break;

            //             case -4 ... 4:
            //                 this->xMovement = this->xMovement + 1;
            //                 break;

            //             case 5 ... 14:
            //                 this->xMovement = this->xMovement + 2;
            //                 break;

            //         }

            //         break;

            // }


            switch (direction) {

                case Direction::West:

                    if (this->xMovement > 0) this->xMovement--;
                    break;

                case Direction::East:

                    if (this->xMovement < 28) this->xMovement++;
                    break;

            }

            Serial.println(this->xMovement);

        }

};