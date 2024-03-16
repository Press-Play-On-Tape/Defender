#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"


void launchTreasure(Treasure &treasure) {

    treasure.setActive(true);
    treasure.setX(static_cast<SQ15x16>(random(-Constants::WorldWidth.getInteger() + 100, Constants::WorldWidth.getInteger() - 100)));
    treasure.setY(51);

}

void relaunchEnemy(Enemy &enemy) {

    if (random(0, 2) == 0) {
        enemy.setDirection(Direction::Left);
        enemy.setX(player.getX() + Constants::WorldWidth.getInteger() - 10);
    }
    else {
        enemy.setDirection(Direction::Right);
        enemy.setX(player.getX() - Constants::WorldWidth.getInteger() + 10);
    }

    enemy.setActive(true);
    enemy.setImageIdx(0);
    enemy.setY(random(0, 42));
    enemy.setSpeed(static_cast<SQ15x16>(static_cast<SQ15x16>(random(12, 24)) / 8));

}


void launchEnemy(Enemy &enemy) {

    enemy.setActive(true);
    enemy.setX(static_cast<SQ15x16>(random(-Constants::WorldWidth.getInteger() + 100, Constants::WorldWidth.getInteger() - 100)));
    enemy.setY(random(0, 42));
    enemy.setSpeed(static_cast<SQ15x16>(static_cast<SQ15x16>(random(12, 24)) / 8));
    
    if (random(0, 2) == 0) {
        enemy.setDirection(Direction::Left);
    }
    else {
        enemy.setDirection(Direction::Right);
    }

}


void play_Init() {

    for (uint8_t i = 0; i < Constants::EnemyCount; i++) {

        Enemy &enemy = enemies[i];

        launchEnemy(enemy);

        if (i < Constants::EnemyCount_Heart) {
            enemy.setEnemyType(EnemyType::Heart);
        }
        else if (i < Constants::EnemyCount_Heart + Constants::EnemyCount_Mine) {
            enemy.setEnemyType(EnemyType::Mine);
        }
        else if (i < Constants::EnemyCount_Heart + Constants::EnemyCount_Mine + Constants::EnemyCount_Zap) {
            enemy.setEnemyType(EnemyType::Zap);
        }
        else {        
            enemy.setEnemyType(EnemyType::Plane);
        }

        // enemy.setEnemyType(EnemyType::Plane);
        // enemy.setSpeed(1.5f);

    }


    for (Particle &particle : particles) {

        particle.setCounter(0);

    }

    for (Bullet &bullet : playerBullets) {

        bullet.setActive(false);

    }

    for (Bullet &bullet : enemyBullets) {

        bullet.setActive(false);

    }

    for (Treasure &treasure : treasures) {

        launchTreasure(treasure);

    }


    for (uint8_t i = 0; i < Constants::TreasureCount; i++) {

        Treasure &treasure = treasures[i];
        treasure.setX(5 + (i * 200));

    }

    // player.setX(500 + (64 - 4));
    player.setX(0 + (56 - 4));
    player.setY(12);
    // player.setY(0);

    gameState = GameState::Play;
    cookie.score = 0;

    camera.setX(0);

    world.setX(0);
    world.setBackgroundX(0);
    world.setForegroundX(0);

}

void render(uint8_t currentPlane) {

    SQ15x16 diffX = world.getX() - camera.getX();// + camera.getX();
  

    // Render background and middle ground ..

    int16_t bg_Pos = (world.getBackgroundX() + diffX).getInteger() % (96);
    int16_t mg_Pos = (world.getX() + diffX).getInteger() % (96);
    int16_t fg_Pos = (world.getForegroundX() + diffX).getInteger() % (96);

    int8_t bgIdx =   ((zapFlash / 3) % 2);
    int8_t mgIdx =   ((world.getX() + diffX).getInteger() / 96) % 4;
    int8_t fgIdx =   ((world.getForegroundX() + diffX).getInteger() / 96) % 4;

    SpritesU::drawOverwriteFX(bg_Pos - 96, 22, Images::BG_00, (bgIdx * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos, 22, Images::BG_00, (bgIdx * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96, 22, Images::BG_00, (bgIdx * 3) + currentPlane);
    SpritesU::drawOverwriteFX(bg_Pos + 96 + 96, 22, Images::BG_00, (bgIdx * 3) + currentPlane);

    SpritesU::drawPlusMaskFX(mg_Pos - 96, 30, Images::MG_00, (((mgIdx + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos, 30, Images::MG_00, (((mgIdx - 1 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96, 30, Images::MG_00, (((mgIdx - 2 + 8) % 4) * 3) + currentPlane);
    SpritesU::drawPlusMaskFX(mg_Pos + 96 + 96, 30, Images::MG_00, (((mgIdx - 3 + 8) % 4) * 3) + currentPlane);



    // Render scoreboard ..

if (bgIdx == 0) {

    uint16_t score = cookie.score / 1000;
    SpritesU::drawOverwrite(128 - 17, 0, Images::Numbers_5x3_2D_MB, (score * 3) + currentPlane);
    score = cookie.score % 100;
    SpritesU::drawOverwrite(128 - 9, 0, Images::Numbers_5x3_2D_MB, (score * 3) + currentPlane);

    SpritesU::drawOverwrite(95, 0, Images::Numbers_5x3_2D_MB, (treasureCount * 3) + currentPlane);
    SpritesU::drawOverwrite(104, 1, Images::HUD_Treasure, currentPlane);


    // Health

    uint8_t i = health / 16;
    if ((healthBlink / 16) % 2 == 0)
    SpritesU::drawOverwrite(2, 1, Images::Health, (i * 3) + currentPlane);


    // HUD

    uint8_t y = static_cast<uint8_t>(player.getY().getInteger()) / 10;

    SpritesU::fillRect(Constants::HUD_Left, 6, 48, 1, a.color(DARK_GRAY));
    SpritesU::fillRect(Constants::HUD_Left - 1 + (48 / 2), 0, 1, 6, a.color(DARK_GRAY));
    a.drawPixel(Constants::HUD_Left - 1 + (48 / 2), y, WHITE);

    for (Enemy &enemy : enemies) {

        if (enemy.isActive()) {
        
            SQ15x16 diffX = enemy.getX() - player.getX();
            uint8_t y = static_cast<uint8_t>(enemy.getY()) / 10;
            a.drawPixel(Constants::HUD_Left - 1 + (48 / 2) + (diffX.getInteger() / 64), y, LIGHT_GRAY);

        }

    }

    if ((frameCount % 64)  < 32) {
            
        for (Treasure &treasure : treasures) {

            if (treasure.isActive()) {
            
                SQ15x16 diffX = treasure.getX() - player.getX();
                uint8_t y = static_cast<uint8_t>(treasure.getY()) / 10;
                a.drawPixel(Constants::HUD_Left + (48 / 2) + (diffX.getInteger() / 64), y, WHITE);

            }

        }

        
        if (enemyPickup != nullptr) {

            if (enemyPickup->getX() < player.getX()) {

                SpritesU::drawOverwrite(36, 1, Images::Arrows, currentPlane);

            }

            else if (enemyPickup->getX() > player.getX()) {

                SpritesU::drawOverwrite(89, 1, Images::Arrows, 3 + currentPlane);

            }
            
        }

    }

}

    // Render bullets ..

    uint8_t playerX_Offset = (player.getX() - camera.getX()).getInteger();
    uint8_t playerY = player.getY().getInteger();

    for (Bullet &bullet : playerBullets) {

        if (bullet.isActive()) {

            int16_t xDiff = (bullet.getX() - player.getX()).getInteger();

            switch (bullet.getDirection()) {

                case Direction::Left:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY().getInteger(), Images::Player_Bullets, currentPlane);
                    break;

                case Direction::Right:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY().getInteger(), Images::Player_Bullets, 3 + currentPlane);
                    break;

                
            }

        }

        if (currentPlane == 2) {

            updatePlayerBullet(player.getX().getInteger(), bullet);
        
        }

    }

    for (Bullet &bullet : enemyBullets) {

        if (bullet.isActive()) {

            int16_t xDiff = (bullet.getX() - player.getX()).getInteger();

            switch (bullet.getDirection()) {

                case Direction::Left:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY().getInteger(), Images::Player_Bullets, currentPlane);
                    break;

                case Direction::Right:
                    SpritesU::drawPlusMask(playerX_Offset + xDiff, bullet.getY().getInteger(), Images::Player_Bullets, 3 + currentPlane);
                    break;

                
            }

        }

        if (currentPlane == 2) {

            updateEnemyBullet(player.getX().getInteger(), bullet);
        
        }

    }




    uint8_t thrustImg = Constants::Thrust_Img[player.getVelocityIdxX()];
    uint8_t thrustFrameCount = ((frameCount % 9 / 3));

    switch (player.getDirectionX()) {

        case Direction::Right:

            switch (player.getVelocityIdxX()) {

                case Constants::Player_Velocity_Stationary:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (4 * 3) + currentPlane);
                    break;

                case Constants::Player_Velocity_Right_Min:

                    SpritesU::drawPlusMaskFX(playerX_Offset - 8, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (5 * 3) + currentPlane);
                    break;

                case Constants::Player_Velocity_Right_Min + 1:

                    SpritesU::drawPlusMaskFX(playerX_Offset - 8, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (6 * 3) + currentPlane);
                    break;

                default:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (1 * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset - 16, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    break;
                    
            }

            break;

        default:

            switch (player.getVelocityIdxX()) {

                case Constants::Player_Velocity_Stationary:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (4 * 3) + currentPlane);
                    break;

                case Constants::Player_Velocity_Left_Min:

                    SpritesU::drawPlusMaskFX(playerX_Offset + 8, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (3 * 3) + currentPlane);
                    break;

                case Constants::Player_Velocity_Left_Min - 1:

                    SpritesU::drawPlusMaskFX(playerX_Offset + 8, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, (2 * 3) + currentPlane);
                    break;

                default:

                    SpritesU::drawPlusMaskFX(playerX_Offset, playerY, Images::Player, 0 + currentPlane);
                    SpritesU::drawPlusMaskFX(playerX_Offset + 16, playerY + 3, Images::Player_Thrust, (((thrustImg * 3) + thrustFrameCount) * 3) + currentPlane);
                    break;
                    
            }

            break;

    }


    // Render treasures ..

    for (Treasure &treasure : treasures) {

        if (treasure.isActive()) {

            SpritesU::drawPlusMask((treasure.getX() - camera.getX()).getInteger(), treasure.getY().getInteger(), Images::Treasure, (((frameCount / 12) % 4) * 3) + currentPlane);

        }

    }



    // Render enemies ..

    for (Enemy &enemy : enemies) {

        if (enemy.isActive()) {

            switch (enemy.getEnemyType()) {

                case EnemyType::Plane:
                case EnemyType::Plane_Decelerate:
                case EnemyType::Plane_SetHeight:
                case EnemyType::Plane_Accelerate:

                    switch (enemy.getDirection()) {

                        case Direction::Right:

                            SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_00, (12 + enemy.getImageIdx()) + currentPlane);
                            break;

                        default:

                            SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_00, enemy.getImageIdx() + currentPlane);
                            break;

                    }

                    break;

                case EnemyType::Plane_Pickup:
                
                    switch (enemy.getDirection()) {

                        case Direction::Right:

                            SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_00_Pickup, ((9 + enemy.getPickupImageIdx()) * 3) + currentPlane);
                            break;

                        default:

                            SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_00_Pickup, (enemy.getPickupImageIdx() * 3) + currentPlane);
                            break;

                    }

                    break;


                case EnemyType::Mine:
        
                    SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_01, enemy.getImageIdx() + currentPlane);
                    break;

                case EnemyType::Heart:
        
                    SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_02, (((frameCount / 12) % 4) * 3) + currentPlane);
                    break;

                case EnemyType::Zap:
        
                    SpritesU::drawPlusMaskFX((enemy.getX() - camera.getX()).getInteger(), enemy.getY().getInteger(), Images::Enemy_03, (enemy.getPickupImageIdx() * 3) + currentPlane);
                    break;
                    
            }

        }

        if (currentPlane == 2) {
    
            updateEnemy(enemy);

            if (enemy.getEnemyType() == EnemyType::Plane && frameCount % 4 == 0) {

                testForTreasures(player, enemy);

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

    if (frameCount % 512 == 0) cookie.score++;

    uint8_t justPressed = getJustPressedButtons();
    uint8_t pressed = getPressedButtons();

    switch (gameState) {

        case GameState::Play:

            updatePlayer(frameCount);
            updateCamera(player);
            world.update(player.getVelocityIdxX());

            updateTreasures();
            enemyFireBullet();

            SQ15x16 offset = 0;
            bool wrap = false;

            if (player.getX() < -Constants::WorldWidth) {

                offset = Constants::WorldWidth;
                wrap = true;

            }
            else if (player.getX() > Constants::WorldWidth) {

                offset = -Constants::WorldWidth;
                wrap = true;
            
            }

            if (wrap) {

                player.incX(offset);
                camera.incX(offset);

                for (Enemy &enemy : enemies) {
                    enemy.incX(offset);
                }

                for (Bullet &bullet : playerBullets) {
                    bullet.incX(offset);
                }

                for (Bullet &bullet : enemyBullets) {
                    bullet.incX(offset);
                }

                for (Treasure &treasure : treasures) {
                    treasure.incX(offset);
                }

            }

            if (justPressed & B_BUTTON) { 
                gameState = GameState::Play_Quit;
            }

            if (justPressed & A_BUTTON) { 
                playerFireBullet();
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


void playerFireBullet() {


    // Cannot fire a bullet when facing the screen ..

    if (player.getVelocityIdxX() == Constants::Player_Velocity_Stationary) return;


    // Otherwise look for an inactive bullet and fire ..

    for (Bullet &bullet : playerBullets) {

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



void enemyFireBullet() {

    if (random(0, 16) != 0) return;


    uint8_t i = 0;
    bool found = false;

    // Bullet &bullet = enemyBullets[i];

    for (i = 0; i < Constants::BulletCount_Enemy; i++) {

        Bullet &bullet = enemyBullets[i];

        if (!bullet.isActive()) {

            found = true;
            break;

        }

    }

    if (found) {
            
        Bullet &bullet = enemyBullets[i];

        uint8_t iStart = Constants::EnemyCount_Heart + Constants::EnemyCount_Mine + Constants::EnemyCount_Zap; // 5
        uint8_t r = random(0, Constants::EnemyCount);

        for (uint8_t enemyIdx = iStart + r; enemyIdx < r + Constants::EnemyCount; enemyIdx++) {

            i = enemyIdx;
            if (i >= Constants::EnemyCount) i = i - Constants::EnemyCount + iStart;
            Enemy &enemy = enemies[i];

            if (enemy.isActive()) {
                bullet.setActive(true);
                bullet.setY(enemy.getY() + 4);

                switch (enemy.getDirection()) {

                    case Direction::Right:
                        bullet.setX(enemy.getX() + Constants::Player_Width);
                        bullet.setDirection(Direction::Right);
                        break;

                    case Direction::Left:
                        bullet.setX(enemy.getX() - 2);
                        bullet.setDirection(Direction::Left);
                        break;
                    
                }

                return;

            }

        }

    }

}