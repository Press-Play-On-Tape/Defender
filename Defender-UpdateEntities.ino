#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"

bool updatePlayer(uint8_t frameCount) {

    player.incX(player.getVelocityX());
    player.incY(player.getVelocityY());


}


void updateCamera(Player &player) {

    SQ15x16 tcamx = player.getX() - CAMERA_OFFSET_X;

    tcamx += player.getVelocityX() * (CAMERA_OFFSET_X_VEL_DELTA / PLAYER_MAX_MOVE_VEL_X);

    if (player.getDirectionX() == Direction::Right)
        tcamx += CAMERA_OFFSET_X_DELTA;
    else
        tcamx -= CAMERA_OFFSET_X_DELTA;

    SQ15x16 d2camx =
        (tcamx - camera.getX()) * CAMERA_UPDATE_X_ALPHA -
        camera.getVelocityX() * CAMERA_UPDATE_X_BETA;

    camera.incX(camera.getVelocityX() * CAMERA_UPDATE_X_DT);
    camera.incVelocityX(d2camx * CAMERA_UPDATE_X_DT);

}


// void updatePlayerBullets(int16_t player_x) {

//     for (Bullet &bullet : playerBullets) {

//         if (bullet.isActive()) {

//             bullet.update(player_x);

//             Rect bulletRect = { bullet.getX().getInteger(), bullet.getY().getInteger(), 8, 1 };

//             for (Enemy &enemy : enemies) {

//                 if (enemy.isActive() && enemy.getImageIdx() == 0) {

//                     Rect enemyRect = enemy.getRect();

//                     if (Arduboy2::collide(bulletRect, enemyRect)) {

//                         bullet.setActive(false);
//                         enemy.setImageIdx(1);

//                         launchParticles((enemy.getX() - camera.getX() + 6).getInteger(), enemy.getY().getInteger() + 6);

//                         switch (enemy.getEnemyType()) {

//                             case EnemyType::Mine:
//                                 cookie.score = cookie.score + 25;
//                                 break;

//                             case EnemyType::Plane:
//                                 cookie.score = cookie.score + 50;
//                                 break;

//                             case EnemyType::Heart:
//                                 break;

//                         }

//                     }

//                 }

//             }

//         }

//     }
    
// }


void updatePlayerBullet(int16_t player_x, Bullet &bullet) {

    // for (Bullet &bullet : playerBullets) {

        if (bullet.isActive()) {

            bullet.update(player_x);

            Rect bulletRect = { bullet.getX().getInteger(), bullet.getY().getInteger(), 8, 1 };

            for (Enemy &enemy : enemies) {

                if (enemy.isActive() && enemy.getImageIdx() == 0) {

                    Rect enemyRect = enemy.getRect();

                    if (Arduboy2::collide(bulletRect, enemyRect)) {

                        bullet.setActive(false);
                        enemy.setImageIdx(1);

                        launchParticles((enemy.getX() - camera.getX() + 6).getInteger(), enemy.getY().getInteger() + 6);

                        switch (enemy.getEnemyType()) {

                            case EnemyType::Mine:
                                cookie.score = cookie.score + 25;
                                break;

                            case EnemyType::Plane:
                                cookie.score = cookie.score + 50;
                                break;

                            case EnemyType::Heart:
                                break;

                        }

                    }

                }

            }

        }

    // }
    
}

// void updateEnemyBullets(int16_t player_x) {

//     for (Bullet &bullet : enemyBullets) {

//         if (bullet.isActive()) {

//             bullet.update(player_x);

//             Rect bulletRect = { bullet.getX().getInteger(), bullet.getY().getInteger(), 8, 1 };
//             Rect playerRect = { player.getX().getInteger(), player.getY().getInteger(), 16, 9 };

//             if (Arduboy2::collide(bulletRect, playerRect)) {

//                 bullet.setActive(false);
//                 launchParticles((player.getX() - camera.getX() + 6).getInteger(), (player.getY() + 6).getInteger());
//                 cookie.decHealth(Constants::Health_Bullet);

//             }

//         }

//     }
    
// }


void updateEnemyBullet(int16_t player_x, Bullet &bullet) {

    // for (Bullet &bullet : enemyBullets) {

        if (bullet.isActive()) {

            bullet.update(player_x);

            Rect bulletRect = { bullet.getX().getInteger(), bullet.getY().getInteger(), 8, 1 };
            Rect playerRect = { player.getX().getInteger(), player.getY().getInteger(), 16, 9 };

            if (Arduboy2::collide(bulletRect, playerRect)) {

                bullet.setActive(false);
                launchParticles((player.getX() - camera.getX() + 6).getInteger(), (player.getY() + 6).getInteger());
                cookie.decHealth(Constants::Health_Bullet);

            }

        }

    // }
    
}

// void updateEnemies() {

//     for (Enemy &enemy : enemies) {

//         if (enemy.isActive()) {

//             bool enemyInactive = enemy.update();

//             if (!enemyInactive) {
                    
//                 SQ15x16 diffX = enemy.getX() - player.getX();


//                 // If the enemy has moved beyond the 'HUD' then wrap them ..

//                 if (diffX < -Constants::WorldWidth) {
//                     enemy.incX(2 * Constants::WorldWidth);
//                 }

//                 if (diffX > Constants::WorldWidth) {
//                     enemy.incX(-2 * Constants::WorldWidth);
//                 }

//                 Rect enemyRect = enemy.getRect();
//                 Rect playerRect = { static_cast<int16_t>(player.getX()), static_cast<int16_t>(player.getY()), 16, 9 };

//                 if (Arduboy2::collide(playerRect, enemyRect)) {

//                     switch (enemy.getEnemyType()) {

//                         case EnemyType::Mine:
//                         case EnemyType::Plane:

//                             if (enemy.getImageIdx() == 0) {

//                                 cookie.decHealth(Constants::Health_Plane);
//                                 enemy.setImageIdx(1);
//                                 launchParticles((enemy.getX() - camera.getX() + 6).getInteger(), enemy.getY().getInteger() + 6);
                            
//                             }

//                             break;

//                         case EnemyType::Heart:

//                             if (enemy.getImageIdx() == 0) {

//                                 cookie.incHealth(random(Constants::HealthMax / 2, Constants::HealthMax + 1));
//                                 enemy.setImageIdx(11);

//                             }
                        
//                             break;

//                     }

//                 }

//             }
//             else {
                    
//                 relaunchEnemy(enemy);

//             }

//         }

//     }

// }


void updateEnemy(Enemy &enemy) {

    // for (Enemy &enemy : enemies) {

        if (enemy.isActive()) {

            bool enemyInactive = enemy.update();

            if (!enemyInactive) {
                    
                SQ15x16 diffX = enemy.getX() - player.getX();


                // If the enemy has moved beyond the 'HUD' then wrap them ..

                if (diffX < -Constants::WorldWidth) {
                    enemy.incX(2 * Constants::WorldWidth);
                }

                if (diffX > Constants::WorldWidth) {
                    enemy.incX(-2 * Constants::WorldWidth);
                }

                Rect enemyRect = enemy.getRect();
                Rect playerRect = { static_cast<int16_t>(player.getX()), static_cast<int16_t>(player.getY()), 16, 9 };

                if (Arduboy2::collide(playerRect, enemyRect)) {

                    switch (enemy.getEnemyType()) {

                        case EnemyType::Mine:
                        case EnemyType::Plane:

                            if (enemy.getImageIdx() == 0) {

                                cookie.decHealth(Constants::Health_Plane);
                                enemy.setImageIdx(1);
                                launchParticles((enemy.getX() - camera.getX() + 6).getInteger(), enemy.getY().getInteger() + 6);
                            
                            }

                            break;

                        case EnemyType::Heart:

                            if (enemy.getImageIdx() == 0) {

                                cookie.incHealth(random(Constants::HealthMax / 2, Constants::HealthMax + 1));
                                enemy.setImageIdx(11);

                            }
                        
                            break;

                    }

                }

            }
            else {
                    
                relaunchEnemy(enemy);

            }

        }

    //}

}

void updateTreasures() {

    for (Treasure &treasure : treasures) {

        if (treasure.isActive()) {

            SQ15x16 diffX = treasure.getX() - player.getX();

            // If the treasures has moved beyond the 'HUD' then wrap them ..

            if (diffX < -Constants::WorldWidth) {
                treasure.incX(2 * Constants::WorldWidth);
            }

            if (diffX > Constants::WorldWidth) {
                treasure.incX(-2 * Constants::WorldWidth);
            }

        }

    }

}

// void testForTreasures() {

//                     // Is the enemy near a treasure?
//     for (Enemy &enemy : enemies) {

//         if (enemy.isActive() && enemy.getImageIdx() == 0) {
            
//             bool pickup = false;

//             for (Treasure &treasure : treasures) {

//                 SQ15x16 xDiff = treasure.getX() - enemy.getX();
//                 SQ15x16 xRatio = xDiff / enemy.getSpeed();

//                 switch (enemy.getDirection()) {

//                     case Direction::Right:

//                         if (xRatio >= static_cast<SQ15x16>(18.0f) && xRatio <= static_cast<SQ15x16>(22.0f)) {

//                             Serial.println("Right");

//                         }

//                         break;

//                 }

//             }

//         }

//     }

// }

void testForTreasures(Enemy &enemy) {

                    // Is the enemy near a treasure?
    //for (Enemy &enemy : enemies) {

        if (enemy.isActive() && enemy.getImageIdx() == 0) {
            
            bool pickup = false;

            for (Treasure &treasure : treasures) {



                switch (enemy.getDirection()) {

                    case Direction::Right:
                        {

                            if (treasure.getX() < enemy.getX()) continue;
                SQ15x16 xDiff = treasure.getX() - enemy.getX();

                if (xDiff < static_cast<SQ15x16>(-60.0f) || xDiff > static_cast<SQ15x16>(60.0f)) continue;

                SQ15x16 xRatio = xDiff / enemy.getSpeed();
// Serial.print((float)xDiff);
// Serial.print(" ");
// Serial.print((float)enemy.getSpeed());
// Serial.print(" ");
// Serial.println((float)xRatio);
                        if (xRatio >= static_cast<SQ15x16>(18.0f) && xRatio <= static_cast<SQ15x16>(22.0f)) {

                            // Serial.println("Right");
                            // Serial.println(enemy.getY().getInteger());
                            enemy.setEnemyType(EnemyType::Plane_Decelerate);
                            enemy.setTreasure(treasure);

// Serial.print("found treasure ");                            
// Serial.println((float)treasure.getX());

                        }

                        }

                        break;

                    case Direction::Left:
                        {
                            if (treasure.getX() > enemy.getX()) continue;
                SQ15x16 xDiff = treasure.getX() - enemy.getX();

                if (xDiff < static_cast<SQ15x16>(-75.0f) || xDiff > static_cast<SQ15x16>(75.0f)) continue;

                SQ15x16 xRatio = xDiff / enemy.getSpeed();
// Serial.print((float)xDiff);
// Serial.print(" ");
// Serial.print((float)enemy.getSpeed());
// Serial.print(" ");
// Serial.println((float)xRatio);
                        if (xRatio >= static_cast<SQ15x16>(-22.0f) && xRatio <= static_cast<SQ15x16>(-18.0f)) {

                            Serial.println("Left");
                            enemy.setEnemyType(EnemyType::Plane_Decelerate);
                            enemy.setTreasure(treasure);

                        }
                        }

                        break;
                }

            }

        }

    //}

}