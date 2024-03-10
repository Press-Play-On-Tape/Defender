#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"
#include "Player.h"

class Enemy {

    private:

        Direction direction = Direction::Left;
        EnemyType enemyType = EnemyType::Mine;

        SQ15x16 speed = 0;
        SQ15x16 x = 0;
        SQ15x16 y = 0;

        bool active = false;
        uint8_t imageIdx = 0;
        
    public:

        Direction getDirection()                        { return this->direction; }
        EnemyType getEnemyType()                        { return this->enemyType; }
        SQ15x16 getSpeed()                              { return this->speed; }
        SQ15x16 getX()                                  { return this->x; }        
        SQ15x16 getY()                                  { return this->y; }        
        bool isActive()                                 { return this->active; }        
        uint8_t getImageIdx()                           { return this->imageIdx; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setEnemyType(EnemyType val)                { this->enemyType = val; }
        void setSpeed(SQ15x16 val)                      { this->speed = val; }
        void setX(SQ15x16 val)                          { this->x = val; }
        void setY(SQ15x16 val)                          { this->y = val; }
        void setActive(bool val)                        { this->active = val; }
        void setImageIdx(uint8_t val)                   { this->imageIdx = val; }

    public:

        void incX(SQ15x16 inc) {

            this->x = this->x + inc;

        }

        bool update(Player &player) {

            switch (this->enemyType) {

                case EnemyType::Plane:

                    switch (this->direction) {

                        case Direction::Left:
// Serial.println(-player.getVelocityX() / 2);
                            this->x = this->x - this->speed + (player.getDirectionX() == Direction::Right ? player.getVelocityX() / 2 : 0);
                            break;

                        case Direction::Right:
// Serial.println(player.getVelocityX() / 2);

                            this->x = this->x + this->speed - (player.getDirectionX() == Direction::Left ? player.getVelocityX() / 2 : 0);
                            break;
                    
                        default:
                            break;

                    }

                    break;

                default:
                    break;
                
            }

            if (this->imageIdx > 0) {

                this->imageIdx++;

                if (this->imageIdx == 12) {

                    this->active = false;
                    
                }

            }

            return this->x < -Constants::WorldWidth || this->x > Constants::WorldWidth;

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