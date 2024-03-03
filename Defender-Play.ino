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

    camera.setX(5000);

    world.setX(5000);
    world.setBackgroundX(5000);
    world.setForegroundX(5000);

}

void render(uint8_t currentPlane) {

    int16_t diffX = world.getX() - player.getX();


    // Render background and middle ground ..

    int16_t bg_Pos = ((world.getBackgroundX() + diffX) % (96 * 16)) / 16;
    int16_t mg_Pos = ((world.getX() + diffX) % (96 * 16)) / 16;
    int16_t fg_Pos = ((world.getForegroundX() + diffX) % (96 * 16)) / 16;

    int8_t bgIdx =    ((world.getBackgroundX() + diffX) / (96 * 16)) % 4;
    int8_t mgIdx =     ((world.getX() + diffX) / (96 * 16)) % 4;
    int8_t fgIdx =     ((world.getForegroundX() + diffX) / (96 * 16)) % 4;


    SpritesU::drawOverwriteFX(bg_Pos - 96, 22, Images::BG_00, (((bgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos, 22, Images::BG_00, (((bgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96, 22, Images::BG_00, (((bgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96 + 96, 22, Images::BG_00, (((bgIdx - 3 + 8) % 4) * 3) + currentPlane);

    SpritesU::drawPlusMaskFX(mg_Pos - 96, 30, Images::MG_00, (((mgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos, 30, Images::MG_00, (((mgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96, 30, Images::MG_00, (((mgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96 + 96, 30, Images::MG_00, (((mgIdx - 3 + 8) % 4) * 3) + currentPlane);



    // Render scoreboard ..

    uint16_t score = cookie.score / 10000;
    SpritesU::drawOverwriteFX(128 - 21, 0, Images::Numbers_5x3_1D_MB, (score * 3) + currentPlane);
    score = (cookie.score - (score * 10000)) / 100;
    SpritesU::drawOverwriteFX(128 - 17, 0, Images::Numbers_5x3_2D_MB, (score * 3) + currentPlane);
    score = cookie.score % 100;
    SpritesU::drawOverwriteFX(128 - 9, 0, Images::Numbers_5x3_2D_MB, (score * 3) + currentPlane);

Serial.print("W ");
Serial.print(world.getX());
Serial.print(", C ");
Serial.print(camera.getX());
Serial.print(", P ");
Serial.print(player.getX());
Serial.println(" ");


    // Render bullets ..

    // uint8_t playerX_Offset = 56 + (camera.getX() / 16);
    uint8_t playerX_Offset = (player.getX() - camera.getX()) / 16;
    uint8_t playerY = player.getY() / 16;

    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            int16_t xDiff = (bullet.getX() - player.getX()) / 16;

            switch (bullet.getDirection()) {

                case Direction::Left:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY_Screen(), Images::Player_Bullets, currentPlane);
                    break;

                case Direction::Right:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY_Screen(), Images::Player_Bullets, 3 + currentPlane);
                    break;

                
            }

        }

    }




    uint8_t thrustImg = Constants::Thrust_Img[player.getAccelerationIdxX()];
    uint8_t thrustFrameCount = ((frameCount % 9 / 3));

    switch (player.getDirectionX()) {

        case Direction::Right:

            switch (player.getAccelerationIdxX()) {

                case Constants::Player_Acceleration_Stationary:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 9 + currentPlane);
                    break;

                case Constants::Player_Acceleration_Right_Min:

                    SpritesU::drawPlusMaskFX(playerX_Offset - 8, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 12 + currentPlane);
                    break;

                default:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 3 + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset - 16, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    break;
                    
            }
            break;

        default:

            switch (player.getAccelerationIdxX()) {

                case Constants::Player_Acceleration_Stationary:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 9 + currentPlane);
                    break;

                case Constants::Player_Acceleration_Left_Min:

                    SpritesU::drawPlusMaskFX(playerX_Offset + 8, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 6 + currentPlane);
                    break;

                default:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 0 + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset + 16, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    break;
                    
            }
            break;

    }


    // Render foregorund ..
    
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


    // Render particles and scores ..

    updateAndRenderParticles(frameCount);

}


void play_Update() {

    frameCount++;

    uint8_t justPressed = getJustPressedButtons();
    uint8_t pressed = getPressedButtons();

    switch (gameState) {

        case GameState::Play:

            updatePlayer(frameCount);
            updateCamera(frameCount);
            world.update(player.getAccelerationIdxX());

            updateBullets(player.getX());

            if (justPressed & B_BUTTON) { 
                gameState = GameState::Play_Quit;
            }

            if (justPressed & A_BUTTON) { 

                fireBullet();

            }

            if (frameCount % 4 == 0) {

                if (pressed & LEFT_BUTTON) { 
                    player.acccelerateX(Direction::Left);
                }
                else if (pressed & RIGHT_BUTTON) { 
                    player.acccelerateX(Direction::Right);
                }
                else if (frameCount % 8 == 0) {
                    player.deccelerateX();
                }

                if (pressed & UP_BUTTON) { 
                    player.acccelerateY(Direction::Up);
                }
                else if (pressed & DOWN_BUTTON) { 
                    player.acccelerateY(Direction::Down);
                }
                else if (frameCount % 8 == 0) {
                    player.deccelerateY();
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

            if (justPressed & A_BUTTON) { 
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


    // Cannot fire a bullet when facing the screen ..

    if (player.getAccelerationIdxX() == Constants::Player_Acceleration_Stationary) return;


    // Otherwise look for an inactive bullet and fire ..

    for (Bullet &bullet : bullets) {

        if (!bullet.isActive()) {

            bullet.setActive(true);
            bullet.setY(player.getY() + (8 * 16));

            switch (player.getDirectionX()) {

                case Direction::Right:
                    bullet.setX(player.getX() + (Constants::Player_Width * 16));
                    bullet.setDirection(Direction::Right);
                    break;

                case Direction::Left:
                    bullet.setX(player.getX() - (2 * 16));
                    bullet.setDirection(Direction::Left);
                    break;
                
            }

            break;

        }

    }

}