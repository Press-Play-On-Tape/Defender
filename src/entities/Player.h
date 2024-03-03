#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Player {

    private:

        PlayerMovement playerMovement = PlayerMovement::Up_Middle;

        Direction directionX = Direction::East;
        Direction directionY = Direction::North;
        int8_t xMovement = 13;
        int8_t yMovement = 11;

        int16_t x = 5000 + (64 - 4) * 16;
        int16_t y = Constants::Player_YMax - Constants::Player_Offset;
        // int16_t xScreen = 5000 + (64 - 4) * 16;
        // int16_t yScreen = 16 * 16;
        bool deccelerateXFlag = false;
        bool deccelerateYFlag = false;
        

    public:

        // PlayerMovement getMovement()                    { return this->playerMovement; }
        Direction getDirectionX()                       { return this->directionX; }
        Direction getDirectionY()                       { return this->directionY; }
        int8_t getXMovement()                           { return this->xMovement; }
        int8_t getYMovement()                           { return this->yMovement; }
        //int8_t getY_Screen()                            { return this->yScreen / 16; }        
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        
        bool getDeccelerateX()                          { return this->deccelerateXFlag; }
        bool getDeccelerateY()                          { return this->deccelerateYFlag; }

        // void setMovement(PlayerMovement val)            { this->playerMovement = val; }
        void setXMovement(int8_t val)                   { this->xMovement = val; }
        void setDirectionX(Direction val)                { this->directionX = val; }
        void setDirectionY(Direction val)                { this->directionY = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }

    public:

        void acccelerateX(Direction direction) {

            this->deccelerateXFlag = false;

            switch (direction) {

                case Direction::West:

                    if (this->xMovement > Constants::PLAYER_SPEED_MID + 1) this->deccelerateXFlag = true;
                    if (this->xMovement > Constants::PLAYER_SPEED_MIN) this->xMovement--;
                    break;

                case Direction::East:

                    if (this->xMovement < Constants::PLAYER_SPEED_MID - 1) this->deccelerateXFlag = true;
                    if (this->xMovement < Constants::PLAYER_SPEED_MAX) this->xMovement++;
                    break;

            }

            if (this->xMovement < Constants::PLAYER_SPEED_MID) {

                this->directionX = Direction::West;

            }
            else {

                this->directionX = Direction::East;

            }

        }

        void deccelerateX() {

            this->deccelerateXFlag = false;

            switch (this->directionX) {

                case Direction::West:

                    if (this->xMovement < Constants::PLAYER_SPEED_MID - 2) {
                        this->xMovement++;
                        this->deccelerateXFlag = true;
                    }

                    break;

                case Direction::East:

                    if (this->xMovement > Constants::PLAYER_SPEED_MID + 2) {
                        this->xMovement--;
                        this->deccelerateXFlag = true;
                    }

                    break;

            }

        }


        void acccelerateY(Direction direction) {

            this->deccelerateYFlag = false;
            int8_t xMovementABS = (this->xMovement > Constants::PLAYER_SPEED_MID ? this->xMovement - Constants::PLAYER_SPEED_MID : abs(Constants::PLAYER_SPEED_MID - this->xMovement));
            int8_t yMovementABS = (this->yMovement > Constants::PLAYER_SPEED_MID ? this->yMovement - Constants::PLAYER_SPEED_MID : abs(Constants::PLAYER_SPEED_MID - this->yMovement));

            switch (direction) {

                case Direction::North:
// Serial.print("Up ");
// Serial.print(yMovement);
// Serial.print(" ");
// Serial.print(this->xMovement);
// Serial.print(" - ");
// Serial.print(xMovementABS);
// Serial.print(" ");
// Serial.println(yMovementABS);
                    // if (this->yMovement > Constants::PLAYER_SPEED_MID + 1) this->deccelerateYFlag = true;
                    // if (this->yMovement > Constants::PLAYER_SPEED_MIN && (xMovementABS >= yMovementABS)) {
                        
                    //     if (this->yMovement > Constants::PLAYER_SPEED_MID) {
                    //         this->yMovement = Constants::PLAYER_SPEED_MID - 1;
                    //     }
                    //     else {
                    //         this->yMovement--;
                    //     }

                    // }
                    if (this->yMovement > Constants::PLAYER_SPEED_MID + 1) this->deccelerateYFlag = true;
                        
                        if (this->yMovement > Constants::PLAYER_SPEED_MID) {
                            this->yMovement = Constants::PLAYER_SPEED_MID - 1;
                        }
                        else {
                            if (this->yMovement > Constants::PLAYER_SPEED_MIN && (xMovementABS >= yMovementABS)) {
                                this->yMovement--;
                            }
                        }

                    

                    break;

                case Direction::South:
// Serial.print("Down ");
// Serial.print(yMovement);
// Serial.print(" ");
// Serial.print(this->xMovement);
// Serial.print(" - ");
// Serial.print(xMovementABS);
// Serial.print(" ");
// Serial.println(yMovementABS);
                    // if (this->yMovement < Constants::PLAYER_SPEED_MID - 1) this->deccelerateYFlag = true;
                    //     Serial.println("aaa");
                    // if (this->yMovement < Constants::PLAYER_SPEED_MAX ) {
                    //     Serial.println("bbb");
                    // }
                    // if (this->yMovement < Constants::PLAYER_SPEED_MAX && (xMovementABS >= yMovementABS)) {
                    //     Serial.println("ccc");
                    //     if (this->yMovement < Constants::PLAYER_SPEED_MID) {
                    //         this->yMovement = Constants::PLAYER_SPEED_MID + 1;
                    //     }
                    //     else {
                    //         this->yMovement++;
                    //     }

                    // }
                    if (this->yMovement < Constants::PLAYER_SPEED_MID - 1) this->deccelerateYFlag = true;
                        // Serial.println("aaa");
                    if (this->yMovement < Constants::PLAYER_SPEED_MAX ) {
                        // Serial.println("bbb");
                    }
                        // Serial.println("ccc");
                        if (this->yMovement < Constants::PLAYER_SPEED_MID) {
                            this->yMovement = Constants::PLAYER_SPEED_MID + 1;
                        }
                        else {
                    if (this->yMovement < Constants::PLAYER_SPEED_MAX && (xMovementABS >= yMovementABS)) {
                            this->yMovement++;
                    }
                        }

                    
                    break;

            }

            if (this->yMovement < Constants::PLAYER_SPEED_MID) {

                this->directionY = Direction::North;

            }
            else {

                this->directionY = Direction::South;

            }

        }

        void deccelerateY() {

            this->deccelerateYFlag = false;

            // switch (this->directionY) {

            //     case Direction::North:

            //         if (this->yMovement < Constants::PLAYER_SPEED_MID - 2) {
            //             this->yMovement++;
            //             this->deccelerateYFlag = true;
            //         }

            //         break;

            //     case Direction::South:

            //         if (this->yMovement > Constants::PLAYER_SPEED_MID + 2) {
            //             this->yMovement--;
            //             this->deccelerateYFlag = true;
            //         }

            //         break;

            // }
            this->yMovement = Constants::PLAYER_SPEED_MID;
                 //       this->deccelerateYFlag = true;
        }        
};