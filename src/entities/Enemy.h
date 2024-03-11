#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"
#include "Treasure.h"

class Enemy {

    private:

        Direction direction = Direction::Left;
        EnemyType enemyType = EnemyType::Mine;
        Treasure treasure;
        
        SQ15x16 speed = 0;
        SQ15x16 x = 0;
        SQ15x16 y = 0;
        SQ15x16 speed_Orig = 0;
        SQ15x16 x_Orig = 0;
        SQ15x16 y_Orig = 0;

        bool active = false;
        uint8_t imageIdx = 0;
        uint8_t pickupImageIdx = 0;
        uint8_t treasureIdx = 0;
        
    public:

        Direction getDirection()                        { return this->direction; }
        EnemyType getEnemyType()                        { return this->enemyType; }
        Treasure getTreasure()                          { return this->treasure; }
        SQ15x16 getSpeed()                              { return this->speed; }
        SQ15x16 getX()                                  { return this->x; }        
        SQ15x16 getY()                                  { return this->y; }        
        bool isActive()                                 { return this->active; }        
        uint8_t getImageIdx()                           { return this->imageIdx; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setEnemyType(EnemyType val)                { this->enemyType = val; }
        void setTreasure(Treasure val)                  { this->treasure = val; }
        void setSpeed(SQ15x16 val)                      { this->speed = val; this->speed_Orig = val; }
        void setX(SQ15x16 val)                          { this->x = val; this->x_Orig = val; }
        void setY(SQ15x16 val)                          { this->y = val; this->y_Orig = val; }
        void setActive(bool val)                        { this->active = val; }
        void setImageIdx(uint8_t val)                   { this->imageIdx = val; }

    public:

        void incX(SQ15x16 inc) {

            this->x = this->x + inc;

        }

        bool update() {

            switch (this->enemyType) {

                case EnemyType::Plane:

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

                    break;

                case EnemyType::Plane_Decelerate:

                    this->speed = this->speed * 0.94;

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

                    if (this->y < 35) {

                        this->y = this->y * 1.01;
                    }
                    else if (this->y > 41) {

                        this->y = this->y * 0.99;
                    }

                    if (this->speed <= Constants::DecSpeed) {

                        this->enemyType = EnemyType::Plane_SetHeight;
// Serial.println("SetHeight");

                    }

                    break;

                case EnemyType::Plane_Accelerate:

                    if (this->speed < this->speed_Orig) {

                        this->speed = this->speed * 1.05;

                    }

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

                    if (this->speed > 1) {
                            
                        if (this->y.getInteger() < this->y_Orig.getInteger()) {

                            this->y = this->y * 1.01;
    // Serial.println("PA IY ");
                        }
                        else if (this->y.getInteger() > this->y_Orig.getInteger()) {

    // Serial.println("PA DY ");
                            this->y = this->y * 0.99;
                        }

                    }


                    if (this->speed > this->speed_Orig && this->y.getInteger() == this->y_Orig.getInteger()) {

                        this->enemyType = EnemyType::Plane;

                    }

                    break;

                case EnemyType::Plane_SetHeight:
                    {
                        if (this->x < treasure.getX()) {
// Serial.print("DX ");
                            this->x = this->x  + 0.5f;
                        }
                        else if (this->x > treasure.getX()) {

// Serial.print("IX ");
                            this->x = this->x - 0.5f;
                        }

                        if (this->y < 37) {

                            this->y = this->y + 0.5f;
// Serial.print("IY ");
                        }
                        else if (this->y > 40) {

// Serial.print("DY ");
                            this->y = this->y - 0.5f;
                        }

                        SQ15x16 xDiff = this->x - treasure.getX();
                        SQ15x16 yDiff = this->y - 38;

// Serial.print(" E ");
// Serial.print((float)this->x);
// Serial.print(",");
// Serial.print((float)this->y);
// Serial.print(" T ");
// Serial.print((float)treasure.getX());
// Serial.print(",");
// Serial.print((float)treasure.getY());
// Serial.print(" ");
// Serial.print((float)xDiff);
// Serial.print(" ");
// Serial.println((float)yDiff);

                        if (xDiff > static_cast<SQ15x16>(-8.0f) && xDiff < static_cast<SQ15x16>(8.0f) && yDiff > static_cast<SQ15x16>(-1.5f) && yDiff < static_cast<SQ15x16>(1.5f)) {

                            // Serial.println((float)this->x);
                            this->y = 38;
                            this->pickupImageIdx = 0;
                            this->enemyType = EnemyType::Plane_Pickup;

                        }

                    }

                    break;

               

                case EnemyType::Plane_Pickup:

                    this->pickupImageIdx++;

                    if (this->pickupImageIdx == 223) {
                        this->enemyType = EnemyType::Plane_Accelerate;
                    }

                    break;

                default:
                    break;
                
            }

            if (this->imageIdx > 0) {

                this->imageIdx++;

                if (this->imageIdx == 12) {

                    this->active = false;
                    return true;
                    
                }

            }

            // return this->x < -Constants::WorldWidth || this->x > Constants::WorldWidth;
            return false;

        }


        uint8_t getPickupImageIdx() {

            switch (this->pickupImageIdx) {

                case 0 ... 63:
                    // Serial.print("0 - 56 ");
                    // Serial.print(this->pickupImageIdx);
                    // Serial.print(" ");
                    // Serial.println(this->pickupImageIdx / 8);
                    return this->pickupImageIdx / 8;

                case 64 ... 159:
                    // Serial.print(this->pickupImageIdx);
                    // Serial.print(" ");
                    // Serial.println(7 + ((this->pickupImageIdx - 64) % 16 < 8 ? 1 : 0));
                    return 7 + ((this->pickupImageIdx - 64) % 16 < 8 ? 1 : 0);

                case 160 ... 223:
                    // Serial.print("128- ");
                    // Serial.print(this->pickupImageIdx);
                    // Serial.print(" ");
                    // Serial.print(160 + 64 - this->pickupImageIdx);
                    // Serial.print(" ");
                    // Serial.println((160 + 64 - this->pickupImageIdx) / 8);
                    return (160 + 64  - this->pickupImageIdx)/ 8;
                    
            }

        }

        Rect getRect() {

            Rect rect;

            switch (this->enemyType) {

                case EnemyType::Mine:
                    rect.x = this->getX().getInteger() + 1;
                    rect.y = this->getY().getInteger() + 1;
                    rect.width = 7;
                    rect.height = 7;
                    break;

                case EnemyType::Plane:
                    rect.x = this->getX().getInteger() + 1;
                    rect.y = this->getY().getInteger() + 1;
                    rect.width = 19;
                    rect.height = 10;
                    break;

                case EnemyType::Heart:
                    rect.x = this->getX().getInteger() + 1;
                    rect.y = this->getY().getInteger() + 1;
                    rect.width = 5;
                    rect.height = 8;
                    break;
                    
            }

            return rect;

        }

};