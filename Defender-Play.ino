#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"

void launchEnemy(Enemy &enemy) {

    enemy.setActive(true);
    enemy.setX(random(-3000, 3000));
    // enemy.setX(500 + (56 - 4));
    enemy.setY(random(0, 42));
    enemy.setSpeed(static_cast<float>(random(2, 4)));
    
    if (random(0, 2) == 0) {
        enemy.setDirection(Direction::Left);
    }
    else {
        enemy.setDirection(Direction::Right);
    }

}


void launchEnemy(Enemy &enemy, float xOffset) {

    enemy.setActive(true);
    enemy.setX(enemy.getX() + xOffset);
    // enemy.setX(500 + (56 - 4));
    enemy.setY(random(0, 42));
    enemy.setSpeed(static_cast<float>(random(1, 3)));

}


void play_Init() {

    for (uint8_t i = 0; i < Constants::EnemyCount; i++) {

        Enemy &enemy = enemies[i];

        launchEnemy(enemy);

        if (i < 1) {
            enemy.setEnemyType(EnemyType::Heart);
        }
        else if (i < 6) {
            enemy.setEnemyType(EnemyType::Mine);
        }
        else {        
            enemy.setEnemyType(EnemyType::Plane);
        }
// enemy.setEnemyType(EnemyType::Mine);
    }

    for (Particle &particle : particles) {

        particle.setCounter(0);

    }

    for (Bullet &bullet : bullets) {

        bullet.setActive(false);

    }

    // player.setX(500 + (64 - 4));
    player.setX(500 + (56 - 4));
    player.setY(16);

    gameState = GameState::Play;
    cookie.score = 0;

    camera.setX(500);

    world.setX(500);
    world.setBackgroundX(500);
    world.setForegroundX(500);

}

void render(uint8_t currentPlane) {

    float diffX = world.getX() - camera.getX();// + camera.getX();
  

    // Render background and middle ground ..

    int16_t bg_Pos = static_cast<int32_t>(world.getBackgroundX() + diffX) % (96);
    int16_t mg_Pos = static_cast<int32_t>(world.getX() + diffX) % (96);
    int16_t fg_Pos = static_cast<int32_t>(world.getForegroundX() + diffX) % (96);

    int8_t bgIdx =   static_cast<int32_t>((world.getBackgroundX() + diffX) / 96) % 4;
    int8_t mgIdx =   static_cast<int32_t>((world.getX() + diffX) / 96) % 4;
    int8_t fgIdx =   static_cast<int32_t>((world.getForegroundX() + diffX) / 96) % 4;


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


    // Health

    uint8_t i = health / 16;
    if ((healthBlink / 16) % 2 == 0)
    SpritesU::drawOverwriteFX(2, 1, Images::Health, (i * 3) + currentPlane);


    // HUD

    uint8_t y = static_cast<uint8_t>(player.getY()) / 10;

    SpritesU::fillRect(Constants::HUD_Left, 6, 48, 1, a.color(DARK_GRAY));
    SpritesU::fillRect(Constants::HUD_Left - 1 + (48 / 2), 0, 1, 6, a.color(DARK_GRAY));
    SpritesU::fillRect(Constants::HUD_Left - 2 + (48 / 2), y, 3, 2, a.color(WHITE));

    for (Enemy &enemy : enemies) {

        if (enemy.isActive()) {
        
            float diffX = enemy.getX() - player.getX();
            uint8_t y = static_cast<uint8_t>(enemy.getY()) / 10;

            if (diffX > -1530 && diffX < 1530) {
                SpritesU::fillRect(Constants::HUD_Left + (48 / 2) + (diffX / 64), y, 2, 2, a.color(LIGHT_GRAY));
            }

            if (diffX < -2500) {
                launchEnemy(enemy, 5000);
            }

            if (diffX > 2500) {
                launchEnemy(enemy, -5000);
            }

        }

    }


    // Render bullets ..

    uint8_t playerX_Offset = (player.getX() - camera.getX());
    uint8_t playerY = player.getY();

    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            int16_t xDiff = (bullet.getX() - player.getX());

            switch (bullet.getDirection()) {

                case Direction::Left:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY(), Images::Player_Bullets, currentPlane);
                    break;

                case Direction::Right:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY(), Images::Player_Bullets, 3 + currentPlane);
                    break;

                
            }

        }

    }




    uint8_t thrustImg = Constants::Thrust_Img[player.getVelocityIdxX()];
    uint8_t thrustFrameCount = ((frameCount % 9 / 3));

    switch (player.getDirectionX()) {

        case Direction::Right:

            switch (player.getVelocityIdxX()) {

                case Constants::Player_Velocity_Stationary:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 9 + currentPlane);
                    break;

                case Constants::Player_Velocity_Right_Min:

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

            switch (player.getVelocityIdxX()) {

                case Constants::Player_Velocity_Stationary:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 9 + currentPlane);
                    break;

                case Constants::Player_Velocity_Left_Min:

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



    // Render enemies ..


    for (Enemy &enemy : enemies) {

        if (enemy.isActive()) {

            switch (enemy.getEnemyType()) {

                case EnemyType::Plane:
                
                    switch (enemy.getDirection()) {

                        case Direction::Right:

                            SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()), enemy.getY(), Images::Enemy_00, (12 + enemy.getImageIdx()) + currentPlane);
                            break;

                        default:

                            SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()), enemy.getY() , Images::Enemy_00, enemy.getImageIdx() + currentPlane);
                            break;

                    }

                    break;

                case EnemyType::Mine:
// Serial.print(world.getX());
// Serial.print(" ");
// Serial.print(camera.getX());
// Serial.print(" ");
// Serial.print(enemy.getX());
// Serial.print(" ");
// Serial.print(player.getX());
// Serial.println(" ");
        
                    SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()), enemy.getY(), Images::Enemy_01, enemy.getImageIdx() + currentPlane);
                    break;

                case EnemyType::Heart:
        
                    SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()), enemy.getY(), Images::Enemy_02, (((frameCount / 12) % 4) * 3) + currentPlane);
                    break;
                    
            }

        }

    }



    // Render foregorund ..
    
    SpritesU::drawPlusMaskFX(fg_Pos - 96, 36, Images::FG_00, (((fgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos, 36, Images::FG_00, (((fgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos + 96, 36, Images::FG_00, (((fgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(fg_Pos + 96 + 96, 36, Images::FG_00, (((fgIdx - 3 + 8) % 4) * 3) + currentPlane);


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
            updateCamera(player);
            world.update(player.getVelocityIdxX());

            updateBullets(player.getX());
            updateEnemies();

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

            if (healthBlink > 0) healthBlink--;
            // Serial.println(healthBlink);

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

    if (player.getVelocityIdxX() == Constants::Player_Velocity_Stationary) return;


    // Otherwise look for an inactive bullet and fire ..

    for (Bullet &bullet : bullets) {

        if (!bullet.isActive()) {

            bullet.setActive(true);
            bullet.setY(player.getY() + 6);

            switch (player.getDirectionX()) {

                case Direction::Right:
                    bullet.setX(player.getX() + Constants::Player_Width);
                    bullet.setDirection(Direction::Right);
                    break;

                case Direction::Left:
                    bullet.setX(player.getX() - 2);
                    bullet.setDirection(Direction::Left);
                    break;
                
            }

            break;

        }

    }

}