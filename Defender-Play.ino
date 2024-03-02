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

    for (Particle &particle : particles) {

        particle.setCounter(0);

    }

    for (Bullet &bullet : bullets) {

        bullet.setActive(false);

    }

    player.setX(5000 + (64 - 4) * 16);
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



    int16_t diffX = xWorld - player.getX();





    int16_t bg_Pos = ((bgPos + diffX) % (96 * 16)) / 16;
    int16_t mg_Pos = ((xWorld + diffX) % (96 * 16)) / 16;
    int16_t fg_Pos = ((fgPos + diffX) % (96 * 16)) / 16;

    int8_t bgIdx =    ((bgPos + diffX) / (96 * 16)) % 4;
    int8_t mgIdx =     ((xWorld + diffX) / (96 * 16)) % 4;
    int8_t fgIdx =     ((fgPos + diffX) / (96 * 16)) % 4;


    SpritesU::drawOverwriteFX(bg_Pos - 96, 22, Images::BG_00, (((bgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos, 22, Images::BG_00, (((bgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96, 22, Images::BG_00, (((bgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96 + 96, 22, Images::BG_00, (((bgIdx - 3 + 8) % 4) * 3) + currentPlane);

    SpritesU::drawPlusMaskFX(mg_Pos - 96, 30, Images::MG_00, (((mgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos, 30, Images::MG_00, (((mgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96, 30, Images::MG_00, (((mgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96 + 96, 30, Images::MG_00, (((mgIdx - 3 + 8) % 4) * 3) + currentPlane);





    uint8_t playerX_Offset = 56 + (playerXOffset / 16);



    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            int16_t xDiff = (bullet.getX() - player.getX()) / 16;

            switch (bullet.getDirection()) {

                case Direction::West:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY_Screen(), Images::Player_Bullets, currentPlane);
                    break;

                case Direction::East:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY_Screen(), Images::Player_Bullets, 3 + currentPlane);
                    break;

                
            }

        }

    }









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


    switch (player.getDirection()) {

        case Direction::North ... Direction::SouthEast:

            switch (player.getXMovement()) {

                case 14:

                    SpritesU::drawPlusMaskFX(playerX_Offset, player.getY_Screen(), Images::Player, 9 + currentPlane);
                    break;

                case 15:

                    SpritesU::drawPlusMaskFX(playerX_Offset - 8, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, player.getY_Screen(), Images::Player, 12 + currentPlane);
                    break;

                default:

                    SpritesU::drawPlusMaskFX(playerX_Offset, player.getY_Screen(), Images::Player, 3 + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset - 16, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                    break;
                    
            }
            break;

        default:

            switch (player.getXMovement()) {

                case 14:

                    SpritesU::drawPlusMaskFX(playerX_Offset, player.getY_Screen(), Images::Player, 9 + currentPlane);
                    break;

                case 13:

                    SpritesU::drawPlusMaskFX(playerX_Offset + 8, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, player.getY_Screen(), Images::Player, 6 + currentPlane);
                    break;

                default:

                    SpritesU::drawPlusMaskFX(playerX_Offset, player.getY_Screen(), Images::Player, 0 + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset + 16, player.getY_Screen() + 3, Images::Player_Thrust, (((thrust * 3) + thrust_frameCount) * 3) + currentPlane);
                    break;
                    
            }
            break;

    }


    SpritesU::drawPlusMaskFX(fg_Pos - 96, 28, Images::FG_00, (((fgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos, 28, Images::FG_00, (((fgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos + 96, 28, Images::FG_00, (((fgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos + 96 + 96, 28, Images::FG_00, (((fgIdx - 3 + 8) % 4) * 3) + currentPlane);


    switch (gameState) {

        case GameState::Play:
        case GameState::Play_EndOfGame:
            break;

        case GameState::Play_Quit:
            SpritesU::drawPlusMaskFX(20, 22, Images::Quit, currentPlane);
            break;

    }


    // SpritesU::drawOverwriteFX(128- 25, 0, Images::HUD, ((hudCounter / 3) * 3) + currentPlane);

    uint16_t score = cookie.score / 10000;
    SpritesU::drawOverwriteFX(128 - 21, 0, Images::Numbers_5x3_1D_MB, (score * 3) + currentPlane);
    score = (cookie.score - (score * 10000)) / 100;
    SpritesU::drawOverwriteFX(128 - 17, 0, Images::Numbers_5x3_2D_MB, (score * 3) + currentPlane);
    score = cookie.score % 100;
    SpritesU::drawOverwriteFX(128 - 9, 0, Images::Numbers_5x3_2D_MB, (score * 3) + currentPlane);


    // Render particles and scores ..

    updateAndRenderParticles(frameCount);

}


void play_Update() {

    frameCount++;
    hudCounter = (hudCounter + 1) % (3 * 19);

    uint8_t justPressed = getJustPressedButtons();
    uint8_t pressed = getPressedButtons();

    switch (gameState) {

        case GameState::Play:

            updatePlayer(frameCount);
            updateBullets(player.getX());

            if (justPressed & B_BUTTON) { 
                gameState = GameState::Play_Quit;
            }

            if (justPressed & A_BUTTON) { 

                fireBullet();

            }

            if (frameCount % 4 == 0) {

                if (pressed & LEFT_BUTTON) { 
                    player.acccelerate(Direction::West);
                }
                else if (pressed & RIGHT_BUTTON) { 
                    player.acccelerate(Direction::East);
                }
                else if (frameCount % 8 == 0) {

                    player.deccelerate();

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


void fireBullet() {

    if (player.getXMovement() == 13) return;

    for (Bullet &bullet : bullets) {

        if (!bullet.isActive()) {

            bullet.setActive(true);
            bullet.setY(player.getY() + (8 * 16));

            switch (player.getDirection()) {

                case Direction::NorthEast:
                case Direction::East:
                case Direction::SouthEast:
                    bullet.setX(player.getX() + (Constants::Player_Width * 16));
                    bullet.setDirection(Direction::East);
                    break;

                case Direction::NorthWest:
                case Direction::West:
                case Direction::SouthWest:
                    bullet.setX(player.getX() - (2 * 16));
                    bullet.setDirection(Direction::West);
                    break;
                
            }

            break;

        }

    }

}