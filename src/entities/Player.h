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
        uint8_t velocityIdxX = 14;
        uint8_t velocityIdxY = 14;

        SQ15x16 x = 0;
        SQ15x16 y = 0;
        bool deccelerateXFlag = false;
        bool deccelerateYFlag = false;
        

    public:

        Direction getDirectionX()                       { return this->directionX; }
        Direction getDirectionY()                       { return this->directionY; }
        uint8_t getVelocityIdxX()                       { return this->velocityIdxX; }
        uint8_t getVelocityIdxY()                       { return this->velocityIdxY; }
        SQ15x16 getX()                                    { return this->x; }        
        SQ15x16 getY()                                    { return this->y; }        
        bool isDecceleratingX()                         { return this->deccelerateXFlag; }
        bool getDeccelerateY()                          { return this->deccelerateYFlag; }

        void setVelocityIdxX(uint8_t val)               { this->velocityIdxX = val; }
        void setDirectionX(Direction val)               { this->directionX = val; }
        void setDirectionY(Direction val)               { this->directionY = val; }
        void setX(SQ15x16 val)                            { this->x = val; }
        void setY(SQ15x16 val)                            { this->y = val; }

    public:

        SQ15x16 getVelocityX()                           { return static_cast<SQ15x16>(Constants::Velocity_X[this->velocityIdxX]) / 16; }

        SQ15x16 getVelocityY()                           { return Constants::Velocity_Y[this->velocityIdxY] / 16; }

        void incX(SQ15x16 val)                           { this->x = this->x + val; }

        void incY(SQ15x16 val) { 
            
            this->y = this->y + val; 

            if (this->y < 0) this->y = 0;
            if (this->y > 43) this->y = 43;

        }

        void acccelerateX(Direction direction) {

            this->deccelerateXFlag = false;

            switch (direction) {

                case Direction::Left:

                    if (this->velocityIdxX > Constants::Player_Velocity_Right_Min) this->deccelerateXFlag = true;
                    if (this->velocityIdxX > Constants::Player_Velocity_Left_Max) this->velocityIdxX--;
                    break;

                case Direction::Right:

                    if (this->velocityIdxX < Constants::Player_Velocity_Left_Min) this->deccelerateXFlag = true;
                    if (this->velocityIdxX < Constants::Player_Velocity_Right_Max) this->velocityIdxX++;
                    break;

            }

            if (this->velocityIdxX < Constants::Player_Velocity_Stationary) {

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

                    if (this->velocityIdxX < Constants::Player_Velocity_Left_Min - 1) {
                        this->velocityIdxX++;
                        this->deccelerateXFlag = true;
                    }

                    break;

                case Direction::Right:

                    if (this->velocityIdxX > Constants::Player_Velocity_Right_Min + 1) {
                        this->velocityIdxX--;
                        this->deccelerateXFlag = true;
                    }

                    break;

            }

        }


        void acccelerateY(Direction direction) {

            this->deccelerateYFlag = false;
            int8_t xMovementABS = (this->velocityIdxX > Constants::Player_Velocity_Stationary ? this->velocityIdxX - Constants::Player_Velocity_Stationary : abs(Constants::Player_Velocity_Stationary - this->velocityIdxX));
            int8_t yMovementABS = (this->velocityIdxY > Constants::Player_Velocity_Stationary ? this->velocityIdxY - Constants::Player_Velocity_Stationary : abs(Constants::Player_Velocity_Stationary - this->velocityIdxY));

            switch (direction) {

                case Direction::Up:

                    if (this->velocityIdxY > Constants::Player_Velocity_Stationary) this->deccelerateYFlag = true;
                        
                    if (this->velocityIdxY > Constants::Player_Velocity_Stationary) {

                        this->velocityIdxY = Constants::Player_Velocity_Up_Min;

                    }
                    else {

                        if (this->velocityIdxY > Constants::Player_Velocity_Up_Max && (xMovementABS >= yMovementABS)) {
                            this->velocityIdxY--;
                        }

                    }

                    break;

                case Direction::Down:

                    if (this->velocityIdxY < Constants::Player_Velocity_Stationary) this->deccelerateYFlag = true;

                    if (this->velocityIdxY < Constants::Player_Velocity_Stationary) {

                        this->velocityIdxY = Constants::Player_Velocity_Down_Min;

                    }
                    else {

                        if (this->velocityIdxY < Constants::Player_Velocity_Down_Max && (xMovementABS >= yMovementABS)) {
                            this->velocityIdxY++;
                        }

                    }
            
                    break;

            }

            if (this->velocityIdxY < Constants::Player_Velocity_Stationary) {

                this->directionY = Direction::Up;

            }
            else {

                this->directionY = Direction::Down;

            }

        }

        void deccelerateY() {

            this->deccelerateYFlag = false;
            this->velocityIdxY = Constants::Player_Velocity_Stationary;

        }        
};