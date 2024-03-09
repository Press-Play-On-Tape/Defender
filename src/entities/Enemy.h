#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

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

        void update() {

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

                default:
                    break;
                
            }

            if (this->imageIdx > 0) {

                this->imageIdx++;

                if (this->imageIdx == 4) {

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
                    rect.width = 9;
                    rect.height = 9;
                    break;

                case EnemyType::Plane:
                    rect.x = this->getX() + 1;
                    rect.y = this->getY() + 1;
                    rect.width = 19;
                    rect.height = 10;
                    break;
                    
            }

            return rect;

        }

};