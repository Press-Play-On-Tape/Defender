#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Camera {

    private:

        int16_t x = 0;
        int16_t vx = 0;
        
    public:

        int16_t getX()                                  { return this->x; }        
        int16_t getVelocityX()                          { return this->vx; }        

        void setX(int16_t val)                          { this->x = val; }
        void setVelocityX(int16_t val)                  { this->vx = val; }

    public:

        void incX(int8_t val) {
        
            this->x = this->x + val;
        
        }

        void incVelocityX(int8_t val) {
        
            this->vx = this->vx + val;
        
        }

        bool update(uint8_t playerAccelerationIdxX) {
            
        }
};