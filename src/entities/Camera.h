#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Camera {

    private:

        float x = 0;
        float vx = 0;
        
    public:

        float getX()                                  { return this->x; }        
        float getVelocityX()                          { return this->vx; }        

        void setX(float val)                          { this->x = val; }
        void setVelocityX(float val)                  { this->vx = val; }

    public:

        void incX(float val) {
        
            this->x = this->x + val;
        
        }

        void incVelocityX(float val) {
        
            this->vx = this->vx + val;
        
        }

        bool update(float playerVelocityIdxX) {
            
        }
};