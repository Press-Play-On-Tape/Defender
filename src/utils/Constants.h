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


// constexpr float CAMERA_OFFSET_X = 64;
constexpr float CAMERA_OFFSET_X = 58;
constexpr float CAMERA_OFFSET_X_DELTA = 8;
constexpr float CAMERA_OFFSET_X_VEL_DELTA = 100;

constexpr float CAMERA_UPDATE_X_OMEGA = 45;
constexpr float CAMERA_UPDATE_X_ZETA = 1;
constexpr float CAMERA_UPDATE_X_ALPHA = CAMERA_UPDATE_X_OMEGA * CAMERA_UPDATE_X_OMEGA;
constexpr float CAMERA_UPDATE_X_BETA = CAMERA_UPDATE_X_OMEGA * CAMERA_UPDATE_X_ZETA * 2;
//constexpr float CAMERA_UPDATE_X_DT = 0.004;
constexpr float CAMERA_UPDATE_X_DT = 0.007;

constexpr float PLAYER_MAX_MOVE_VEL_X = 4.0;
constexpr float PLAYER_MAX_VEL_X = 4.0;


namespace Constants {

    constexpr uint8_t CellWidth = 6;
    constexpr uint8_t CellHeight = 6;
    constexpr uint8_t MapTileWidth = 18;
    constexpr uint8_t MapTileHeight = 10;
    constexpr uint8_t EnemyCount = 10;
    constexpr uint8_t EnemyWidth = 4;

    constexpr uint8_t Player_Width = 14;
    constexpr uint8_t ParticlesMax = 25;
    constexpr uint8_t BulletCount = 5;
    constexpr uint8_t TreasureCount = 5;

    constexpr uint8_t HUD_Left = 40;

    // constexpr int16_t Player_Offset_X_Min = 46 * -16;
    // constexpr int16_t Player_Offset_X_Mid = 0;
    // constexpr int16_t Player_Offset_X_Max = 46 * 16;
    constexpr int16_t Player_Offset_X_Min = 0;
    constexpr int16_t Player_Offset_X_Mid = 60 * 16;            // 960
    constexpr int16_t Player_Offset_X_Max = 60 * 16 * 2;        // 1920

    constexpr int16_t Player_Velocity_Left_Max = 0;
    constexpr int16_t Player_Velocity_Left_Min = 13;
    constexpr int16_t Player_Velocity_Up_Max = 0;
    constexpr int16_t Player_Velocity_Up_Min = 13;
    constexpr int16_t Player_Velocity_Stationary = 14;
    constexpr int16_t Player_Velocity_Right_Min = 15;
    constexpr int16_t Player_Velocity_Right_Max = 28;
    constexpr int16_t Player_Velocity_Down_Min = 15;
    constexpr int16_t Player_Velocity_Down_Max = 28;

//    constexpr int8_t Velocity_X[29] = { -24, -22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -3, -2, -1, 0, 1, 2, 3, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
    constexpr int8_t Velocity_X[29] = { -32, -32, -32, -32, -32, -30, -28, -26, -23, -20, -16, -12, -8, -4, 0, 4, 8, 12, 16, 20, 23, 26, 28, 30, 32, 32, 32, 32, 32 };
    constexpr int8_t Velocity_Y[29] = { -32, -32, -32, -32, -32, -30, -28, -26, -23, -20, -16, -12, -8, -4, 0, 4, 8, 12, 16, 20, 23, 26, 28, 30, 32, 32, 32, 32, 32 };
    constexpr int8_t Camera_Offset_X[29] = { 26, 26, 18, 18, 12, 12, 8, 8, 6, 6, 4, 4, 2, 2, 0, 2, 2, 4, 4, 6, 6, 8, 8, 12, 12, 18, 18, 26, 26 };

    constexpr int8_t Thrust_Img[29] = { 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4,4, 5, 5, 5, 5 };


};


namespace Images {
    
};
