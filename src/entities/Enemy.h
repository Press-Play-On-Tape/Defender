#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"
#include "Player.h"

class Enemy {

    private:

        Direction direction = Direction::Left;
        EnemyType enemyType = EnemyType::Mine;

        float speed = 0;
        float x = 0;
        float y = 0;

        bool active = false;
        uint8_t imageIdx = 0;
        
    public:

        Direction getDirection()                        { return this->direction; }
        EnemyType getEnemyType()                        { return this->enemyType; }
        float getSpeed()                                { return this->speed; }
        float getX()                                    { return this->x; }        
        float getY()                                    { return this->y; }        
        bool isActive()                                 { return this->active; }        
        uint8_t getImageIdx()                           { return this->imageIdx; }        

        void setDirection(Direction val)                { this->direction = val; }
        void setEnemyType(EnemyType val)                { this->enemyType = val; }
        void setSpeed(float val)                        { this->speed = val; }
        void setX(float val)                            { this->x = val; }
        void setY(float val)                            { this->y = val; }
        void setActive(bool val)                        { this->active = val; }
        void setImageIdx(uint8_t val)                   { this->imageIdx = val; }

    public:

        void update(Player &player) {

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

        }

        Rect getRect() {

            Rect rect;

            switch (this->enemyType) {

                case EnemyType::Mine:
                    rect.x = this->getX() + 1;
                    rect.y = this->getY() + 1;
                    rect.width = 7;
                    rect.height = 7;
                    break;

                case EnemyType::Plane:
                    rect.x = this->getX() + 1;
                    rect.y = this->getY() + 1;
                    rect.width = 19;
                    rect.height = 10;
                    break;

                case EnemyType::Heart:
                    rect.x = this->getX() + 1;
                    rect.y = this->getY() + 1;
                    rect.width = 5;
                    rect.height = 8;
                    break;
                    
            }

            return rect;

        }

};