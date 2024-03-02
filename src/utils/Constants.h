#pragma once
#include "../../fxdata/fxdata.h"
#include "../../fxdata/images/Images.h"

#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define _DEBUG
#define _DEBUG_RENDER_TILES
#define _DEBUG_LEVEL_LOAD
#define _DEBUG_MOVEMENTS_ROTATORS
#define _DEBUG_CAN_ROTATOR
#define _DEBUG_IS_WALKABLE
#define _DEBUG_ITEM_BITMAP

namespace Music {

    constexpr uint24_t Songs[] = { Music::Song_MainTheme };

    constexpr uint24_t SFXs[] =  { Music::SFX_Death, 
                                   Music::SFX_Victory,
                                   Music::SFX_XPGain,
                                   Music::SFX_Three_Inc,
                                   Music::SFX_Three_Dec  };

}

struct Point_U8 {
    uint8_t x;
    uint8_t y;
};

struct Point_S8 {
    int8_t x;
    int8_t y;
};

namespace Constants {

    constexpr uint8_t CellWidth = 6;
    constexpr uint8_t CellHeight = 6;
    constexpr uint8_t MapTileWidth = 18;
    constexpr uint8_t MapTileHeight = 10;
    constexpr uint8_t EnemyCount = 10;
    constexpr uint8_t EnemyWidth = 4;
    constexpr int16_t Player_XMin = 0;
    constexpr int16_t Player_XMax = 1592;
    constexpr int16_t Player_YMin = 8;
    constexpr int16_t Player_YMax = 900;
    constexpr int16_t Player_Offset = 144;
    constexpr uint8_t Player_Width = 14;
    constexpr uint8_t ParticlesMax = 25;
    constexpr uint8_t BulletCount = 5;


    constexpr int16_t PLAYER_OFFSET_X_MIN = 46 * -16;
    constexpr int16_t PLAYER_OFFSET_X_MID = 0;
    constexpr int16_t PLAYER_OFFSET_X_MAX = 46 * 16;

    constexpr int8_t Movement_X[29] = { -24, -22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -3, -2, -1, 0, 1, 2, 3, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
    constexpr int8_t World_XOffset[29] = { 42, 39, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30, -33, -36, -39, -42 };

};


namespace Images {
    
};
