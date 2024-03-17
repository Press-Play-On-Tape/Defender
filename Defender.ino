#define ABG_IMPLEMENTATION
#define ABG_TIMER1
#define ABG_SYNC_PARK_ROW
#define SPRITESU_IMPLEMENTATION

#include <ArduboyFX.h>  
#include <FixedPointsCommon.h>
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "fxdata/images/Images.h"
#include "src/entities/Entities.h"
#include "src/utils/Random.h"

#define SPRITESU_OVERWRITE
#define SPRITESU_PLUSMASK
#define SPRITESU_RECT
#define SPRITESU_FX

#include "src/utils/SpritesU.hpp"

extern ArduboyGBase_Config<ABG_Mode::L4_Triplane> a;
decltype(a) a;

#define SYNTHU_IMPLEMENTATION
#define SYNTHU_NUM_CHANNELS 4
#define SYNTHU_UPDATE_EVERY_N_FRAMES 3
#define SYNTHU_ENABLE_SFX 1
#define SYNTHU_FX_READDATABYTES_FUNC FX::readDataBytes
#include "src/utils/SynthU.hpp"
#define ABG_TIMER1

Cookie cookie;
SoundSettings &soundSettings = cookie.soundSettings;

Player player;
Enemy enemies[Constants::EnemyCount];
Particle particles[Constants::ParticlesMax];
GameState gameState = GameState::SplashScreen_Start;
Bullet playerBullets[Constants::BulletCount_Player];
Bullet enemyBullets[Constants::BulletCount_Enemy];
Treasure treasures[Constants::TreasureCount];
World world;
Camera camera;

uint16_t frameCount = 0;
bool particlesNeedRendering = false;
bool scoresNeedRendering = false;
uint8_t titleCounter = 0;
Enemy *enemyPickup = nullptr;
uint8_t health = Constants::HealthMax;
uint8_t healthBlink = 0;
uint8_t treasureCount = Constants::TreasureCount;
uint8_t zapFlash = 0;
bool gameOver = false;


void setup() {

    a.boot();
    abg_detail::send_cmds_prog<0xDB, 0x20>();
    a.startGray();
    
    FX::begin(FX_DATA_PAGE, FX_SAVE_PAGE);
    FX::loadGameState((uint8_t*)&cookie, sizeof(cookie));

    //SJH audioInit();
    //SJH setAudioOn();

}


void loop() {

    FX::enableOLED();
// Serial.println((zapFlash / 3) % 2);
    if ((zapFlash / 3) % 2 == 0) {
        a.waitForNextPlane(BLACK);
// Serial.println(" BLACK");        
    }
    else {
        a.waitForNextPlane(WHITE);
// Serial.println(" WHITE");        
    }

// if (enemyPickup != nullptr) {
//     Serial.println(frameCount);
// }
    FX::disableOLED();

    switch (gameState) {

        case GameState::SplashScreen_Start ... GameState::SplashScreen_End:
            splashScreen(a);
            break;

        case GameState::Title_Init:
            title_Init();
            [[fallthrough]];

        case GameState::Title_Start ... GameState::Title_End:
            title(a);
            break;

        case GameState::Play_Init:
            play_Init();
            [[fallthrough]];

        case GameState::Play_Start ... GameState::Play_End:
            play(a);
            break;

    }

    if (cookie.score > cookie.highScore) {

        cookie.highScore = cookie.score;

    }

    audioUpdate();

    if (zapFlash > 0) {
        zapFlash--;
    }

}

