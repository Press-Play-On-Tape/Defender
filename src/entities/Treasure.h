#pragma once

#include <Arduboy2.h>
#include "../utils/Enums.h"
#include "../../fxdata/fxdata.h"

class Treasure {

    private:

        float x = 40;
        float y = 47;
        bool active = false;
        
    public:

        float getX()                                    { return this->x; }        
        float getY()                                    { return this->y; }        
        bool isActive()                                 { return this->active; }        

        void setX(float val)                            { this->x = val; }
        void setY(float val)                            { this->y = val; }
        void setActive(bool val)                        { this->active = val; }

    public:

        void incX(float inc) {

            this->x = this->x + inc;

        }
};