#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Player {

    private:

        PlayerMovement playerMovement = PlayerMovement::Up_Middle;

        Direction directionX = Direction::Right;
        Direction directionY = Direction::None;
        uint8_t accelerationIdxX = 14;
        uint8_t accelerationIdxY = 14;

        int16_t x = 0;
        int16_t y = 0;
        bool deccelerateXFlag = false;
        bool deccelerateYFlag = false;
        

    public:

        Direction getDirectionX()                       { return this->directionX; }
        Direction getDirectionY()                       { return this->directionY; }
        uint8_t getAccelerationIdxX()                   { return this->accelerationIdxX; }
        uint8_t getAccelerationIdxY()                   { return this->accelerationIdxY; }
        int16_t getX()                                  { return this->x; }        
        int16_t getY()                                  { return this->y; }        
        bool isDecceleratingX()                         { return this->deccelerateXFlag; }
        bool getDeccelerateY()                          { return this->deccelerateYFlag; }

        void setAccelerationIdxX(uint8_t val)           { this->accelerationIdxX = val; }
        void setDirectionX(Direction val)               { this->directionX = val; }
        void setDirectionY(Direction val)               { this->directionY = val; }
        void setX(int16_t val)                          { this->x = val; }
        void setY(int16_t val)                          { this->y = val; }

    public:

        int8_t getAccelerationX()                       { return Constants::Acceleration_X[this->accelerationIdxX]; }
        int8_t getAccelerationY()                       { return Constants::Acceleration_Y[this->accelerationIdxY]; }

        void incX(int16_t val)                          { this->x = this->x + val; }

        void incY(int16_t val) { 
            
            this->y = this->y + val; 

            if (this->y < 0) this->y = 0;
            if (this->y > 700) this->y = 700;

        }

        void acccelerateX(Direction direction) {

            this->deccelerateXFlag = false;

            switch (direction) {

                case Direction::Left:

                    if (this->accelerationIdxX > Constants::Player_Acceleration_Right_Min) this->deccelerateXFlag = true;
                    if (this->accelerationIdxX > Constants::Player_Acceleration_Left_Max) this->accelerationIdxX--;
                    break;

                case Direction::Right:

                    if (this->accelerationIdxX < Constants::Player_Acceleration_Left_Min) this->deccelerateXFlag = true;
                    if (this->accelerationIdxX < Constants::Player_Acceleration_Right_Max) this->accelerationIdxX++;
                    break;

            }

            if (this->accelerationIdxX < Constants::Player_Acceleration_Stationary) {

                this->directionX = Direction::Left;

            }
            else {

                this->directionX = Direction::Right;

            }

        }

        void deccelerateX() {

            this->deccelerateXFlag = false;

            switch (this->directionX) {

                case Direction::Left:

                    if (this->accelerationIdxX < Constants::Player_Acceleration_Left_Min - 1) {
                        this->accelerationIdxX++;
                        this->deccelerateXFlag = true;
                    }

                    break;

                case Direction::Right:

                    if (this->accelerationIdxX > Constants::Player_Acceleration_Right_Min + 1) {
                        this->accelerationIdxX--;
                        this->deccelerateXFlag = true;
                    }

                    break;

            }

        }


        void acccelerateY(Direction direction) {

            this->deccelerateYFlag = false;
            int8_t xMovementABS = (this->accelerationIdxX > Constants::Player_Acceleration_Stationary ? this->accelerationIdxX - Constants::Player_Acceleration_Stationary : abs(Constants::Player_Acceleration_Stationary - this->accelerationIdxX));
            int8_t yMovementABS = (this->accelerationIdxX > Constants::Player_Acceleration_Stationary ? this->accelerationIdxX - Constants::Player_Acceleration_Stationary : abs(Constants::Player_Acceleration_Stationary - this->accelerationIdxY));

            switch (direction) {

                case Direction::Up:

                    if (this->accelerationIdxY > Constants::Player_Acceleration_Stationary) this->deccelerateYFlag = true;
                        
                    if (this->accelerationIdxY > Constants::Player_Acceleration_Stationary) {

                        this->accelerationIdxY = Constants::Player_Acceleration_Up_Min;

                    }
                    else {

                        if (this->accelerationIdxY > Constants::Player_Acceleration_Up_Max && (xMovementABS >= yMovementABS)) {
                            this->accelerationIdxY--;
                        }

                    }

                    break;

                case Direction::Down:

                    if (this->accelerationIdxY < Constants::Player_Acceleration_Stationary) this->deccelerateYFlag = true;

                    if (this->accelerationIdxY < Constants::Player_Acceleration_Stationary) {

                        this->accelerationIdxY = Constants::Player_Acceleration_Down_Min;

                    }
                    else {

                        if (this->accelerationIdxY < Constants::Player_Acceleration_Down_Max && (xMovementABS >= yMovementABS)) {
                            this->accelerationIdxY++;
                        }

                    }
            
                    break;

            }

            if (this->accelerationIdxY < Constants::Player_Acceleration_Stationary) {

                this->directionY = Direction::Up;

            }
            else {

                this->directionY = Direction::Down;

            }

        }

        void deccelerateY() {

            this->deccelerateYFlag = false;
            this->accelerationIdxY = Constants::Player_Acceleration_Stationary;

        }        
};