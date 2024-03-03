#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Camera {

    private:

        int16_t x = 0;
        
    public:

        int16_t getX()                                  { return this->x; }        

        void setX(int16_t val)                          { this->x = val; }

    public:

        void incX(int8_t val) {
        
            this->x = this->x + val;
        
        }

        bool update(uint8_t playerAccelerationIdxX) {
            
        }
};