#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"

void play_Init() {

    for (Enemy &enemy : enemies) {

        enemy.setActive(false);
        enemy.setX(0);
        enemy.setY(0);

    }

    for (Score &score : scores) {

        score.setActive(false);
        score.setX(0);
        score.setY(0);

    }

    for (Particle &particle : particles) {

        particle.setCounter(0);

    }

    launchEnemyCounter = 1;
    launchEnemyCounter_Max = 255;

    launchEnemy();

    player.setX(16 * (64 - 8));
    player.setY(16 * 16);

    gameState = GameState::Play;
    cookie.score = 0;
    scorePerPass = 0;
    gameOverCounter = 0;
    hudCounter = 0;

}

void render(uint8_t currentPlane) {

    uint8_t explodeCount = 0;
    uint8_t xCoord[4] = { 0, 0, 0, 0 };
    uint8_t yCoord[4] = { 0, 0, 0, 0 };
    uint8_t imageIdx[4] = { 0, 0, 0, 0 };

    int8_t world_XOff = Constants::World_XOffset[player.getXMovement()];

    int16_t bg_Pos = (bgPos % (96 * 16)) / 16;
    int16_t mg_Pos = (mgPos % (96 * 16)) / 16;
    int16_t fg_Pos = (fgPos % (96 * 16)) / 16;

    int8_t bgIdx =    ( bgPos / (96 * 16)) % 4;
    int8_t mgIdx =     (mgPos / (96 * 16)) % 4;
    int8_t fgIdx =     (fgPos / (96 * 16)) % 4;


    SpritesU::drawOverwriteFX(bg_Pos - 96, 22, Images::BG_00, (((bgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos, 22, Images::BG_00, (((bgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96, 22, Images::BG_00, (((bgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96 + 96, 22, Images::BG_00, (((bgIdx - 3 + 8) % 4) * 3) + currentPlane);


// Serial.print(fgIdx);
// Serial.print(",");

// Serial.print(((fgIdx + 8) % 4));
// Serial.print(",");
// Serial.print(((fgIdx - 1 + 8) % 4));
// Serial.print(",");
// Serial.print(((fgIdx - 2 + 8) % 4));
// Serial.print(" =");

// Serial.print(fgPos);
// Serial.print(",");
// Serial.println(fg_Pos);


    SpritesU::drawPlusMaskFX(mg_Pos - 96, 30, Images::MG_00, (((mgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos, 30, Images::MG_00, (((mgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96, 30, Images::MG_00, (((mgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96 + 96, 30, Images::MG_00, (((mgIdx - 3 + 8) % 4) * 3) + currentPlane);


    // Render enemies ..

    // for (Enemy &enemy : enemies) {

    //     if (enemy.isActive()) {

    //         if (enemy.getX() < 1568) {

    //             SpritesU::drawPlusMask(enemy.getX_Screen(), enemy.getY_Screen(), Images::Enemy, currentPlane);

    //         }
    //         else {

    //             if (player.getPlayerMode() != PlayerMode::Dead || (player.getPlayerMode() == PlayerMode::Dead && frameCount % 24 < 12)) {

    //                 SpritesU::drawPlusMask(enemy.getX_Screen(), enemy.getY_Screen(), Images::Enemy, currentPlane);

    //             }

    //         }

    //     }

    // }


    // Render player ..

    // switch (player.getPlayerMode()) {

    //     case PlayerMode::Rotate:
    //         {
    //             uint8_t offset = player.getY_Screen() > 40 ? 13 : 0;
    //             uint24_t imageIdx = FX::readIndexedUInt24(Images::Player_Rotate, player.getDirection() + offset);
    //             int8_t playerOffset_X = Constants::PlayerOffset_X[player.getDirection()];
    //             SpritesU::drawPlusMaskFX(player.getX_Screen() + playerOffset_X, player.getY_Screen(), imageIdx, currentPlane);
    //         }
            
    //         break;

        // case PlayerMode::Moving:
            

uint8_t thrust = 0;
uint8_t thrust_frameCount = ((frameCount % 9 / 3));
switch (player.getXMovement()) {


    case 0 ... 3:
        thrust = 2;
        break;

    case 4 ... 8:
        thrust = 1;
        break;

    case 9 ... 13:
        thrust = 0;
        break;

    case 14 ... 18:
        thrust = 3;
        break;

    case 19 ... 24:
        thrust = 4;
        break;

    case 25 ... 28:
        thrust = 5;
        break;
        
}

// switch (player.getDirection()) {

//     case Direction::North ... Direction::SouthEast:
//         break;

//     default:
//         thrust = thrust + 3;
//         break;

// }
// Serial.print(player.getXMovement());
// Serial.print(" ");
// Serial.print(thrust * 3);
// Serial.print(" ");
// Serial.println(thrust_frameCount);

            switch (player.getDirection()) {

                case Direction::North ... Direction::SouthEast:

                    switch (player.getXMovement()) {

                        // case 13 ... 14:
                        case 13:
Serial.println("1");                        
                            SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, 9 + currentPlane);
                            break;

                        // case 15 ... 16:
                        case 14:
Serial.println("2");                        
                            SpritesU::drawPlusMaskFX(player.getX_Screen() - 8, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                            SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, 12 + currentPlane);
                            break;

                        default:
Serial.println("3");                        
                            SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, 3 + currentPlane);
                            SpritesU::drawPlusMaskFX(player.getX_Screen() - 16, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                            break;
                            
                    }
                    break;

                default:

                    switch (player.getXMovement()) {

                        // case 12 ... 13:
                        case 13:
Serial.println("4");                        
                            SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, 9 + currentPlane);
                            break;

                        // case 10 ... 11:
                        case 12:
Serial.println("5");                        
                            SpritesU::drawPlusMaskFX(player.getX_Screen() + 8, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                            SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, 6 + currentPlane);
                            break;

                        default:
Serial.println("6");                        
                            SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, 0 + currentPlane);
                            SpritesU::drawPlusMaskFX(player.getX_Screen() + 16, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                            break;
                            
                    }
                    break;

                    // SpritesU::drawPlusMaskFX(player.getX_Screen(), player.getY_Screen(), Images::Player, currentPlane);
                    // SpritesU::drawPlusMaskFX(player.getX_Screen() + 16, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                    break;

            }



    SpritesU::drawPlusMaskFX(fg_Pos - 96, 28, Images::FG_00, (((fgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos, 28, Images::FG_00, (((fgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos + 96, 28, Images::FG_00, (((fgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos + 96 + 96, 28, Images::FG_00, (((fgIdx - 3 + 8) % 4) * 3) + currentPlane);

    // int16_t x = player.getX();
    // x = x / 16;


    // int16_t xStart = x - world_XOff + 56;




    //         SpritesU::drawPlusMaskFX(world_XOff + 56, player.getY() / 16, Images::Player, currentPlane);
            // break;

    //     case PlayerMode::Dead:
            
    //         if (gameOverCounter < 128) {
    //             gameOverCounter++;
    //         }
    //         else {
    //             SpritesU::drawPlusMaskFX(24, 13, Images::GameOver, currentPlane);
    //         }
    //         break;

    //     default:
    //         break;

    // }


    switch (gameState) {

        case GameState::Play:
        case GameState::Play_EndOfGame:
            break;

        case GameState::Play_Quit:
            SpritesU::drawPlusMaskFX(20, 22, Images::Quit, currentPlane);
            break;

    }


    // SpritesU::drawOverwriteFX(128- 25, 0, Images::HUD, ((hudCounter / 3) * 3) + currentPlane);

    // uint16_t score = cookie.score / 10000;
    // SpritesU::drawOverwriteFX(128 - 22, 10, Images::Numbers_5x3_1D_WB, (score * 3) + currentPlane);
    // score = (cookie.score - (score * 10000)) / 100;
    // SpritesU::drawOverwriteFX(128 - 18, 10, Images::Numbers_5x3_2D_WB, (score * 3) + currentPlane);
    // score = cookie.score % 100;
    // SpritesU::drawOverwriteFX(128 - 10, 10, Images::Numbers_5x3_2D_WB, (score * 3) + currentPlane);

    // score = cookie.highScore / 10000;
    // SpritesU::drawOverwriteFX(128 - 22, 28, Images::Numbers_5x3_1D_WB, (score * 3) + currentPlane);
    // score = (cookie.highScore - (score * 10000)) / 100;
    // SpritesU::drawOverwriteFX(128 - 18, 28, Images::Numbers_5x3_2D_WB, (score * 3) + currentPlane);
    // score = cookie.highScore % 100;
    // SpritesU::drawOverwriteFX(128 - 10, 28, Images::Numbers_5x3_2D_WB, (score * 3) + currentPlane);


    // Render particles and scores ..

    updateAndRenderParticles(frameCount);
    updateAndRenderScores(frameCount, currentPlane);

}


void play_Update() {

    frameCount++;
    hudCounter = (hudCounter + 1) % (3 * 19);

    uint8_t justPressed = getJustPressedButtons();
    uint8_t pressed = getPressedButtons();

    switch (gameState) {

        case GameState::Play:

            updatePlayer(frameCount);
            updateEnemies(frameCount);
            launchEnemy();

            if (justPressed & B_BUTTON) { 
                gameState = GameState::Play_Quit;
            }

            if (frameCount % 4 == 0) {

                if (pressed & LEFT_BUTTON) { 
                    player.accelerate(Direction::West);
                }
                if (pressed & RIGHT_BUTTON) { 
                    player.accelerate(Direction::East);
                }

            }

            break;

        case GameState::Play_Quit:

            if (justPressed & A_BUTTON) { 
                gameState = GameState::Title_Init;
            }

            if (justPressed & B_BUTTON) { 
                gameState = GameState::Play;
            }

            break;

        default:

            if (gameOverCounter == 128 && justPressed & A_BUTTON) { 
                gameState = GameState::Title_Init;
            }

           break;

    }

}            


void play(ArduboyGBase_Config<ABG_Mode::L4_Triplane> &a) {
    
    if (a.needsUpdate()) play_Update();

    uint8_t currentPlane = a.currentPlane();
    render(currentPlane);

}



void launchEnemy() {

    // uint8_t movement = random(0, static_cast<uint8_t>(Movement::Down_02_06) + 1);
    // uint8_t speed = random(0, static_cast<uint8_t>(Speed::Fast) + 1);

    // if (launchEnemyCounter > 0) launchEnemyCounter--;

    // if (launchEnemyCounter == 0) {

    //     for (Enemy &enemy : enemies) {

    //         if (!enemy.isActive()) {

    //             enemy.setActive(true);
    //             enemy.setX(-120);
    //             enemy.setY(random(40 + 40, 900 - 40));
    //             enemy.setMovement(static_cast<Movement>(movement));
    //             enemy.setSpeed(static_cast<Speed>(speed));

    //             launchEnemyCounter = launchEnemyCounter_Max;
    //             if (launchEnemyCounter_Max > 5) launchEnemyCounter_Max--;
    //             break;

    //         }

    //     }

    // }
    
}


void updateEnemies(uint8_t frameCount) {

    // for (Enemy &enemy : enemies) {

    //     if (enemy.isActive()) {

    //         bool endOfGame = updateEnemy(enemy, frameCount);

    //         if (endOfGame) {

    //             if (player.getPlayerMode() != PlayerMode::Dead) {

    //                 saveCookie(true);

    //             }

    //             launchParticles(player.getX_Screen() + 4, player.getY_Screen() + 4);
    //             player.setPlayerMode(PlayerMode::Dead);
    //             gameState = GameState::Play_EndOfGame;
    //             playSFX(MusicSFX::SFX_Death);

    //         }   
    //         else {
                        
    //             if (enemy.getX_Screen() >= -4) {
                      

    //             }

    //         }

    //     }

    // }
    
}

