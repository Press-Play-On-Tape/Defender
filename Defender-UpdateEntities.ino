#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"

void updatePlayer(uint8_t frameCount) {

    player.incX(player.getVelocityX());
    player.incY(player.getVelocityY());

}


void updateCamera(Player &player) {

    /*
    float tcamy = py - CAMERA_OFFSET_Y;
    float tcamx = px - CAMERA_OFFSET_X;
    float xmax = map_width * 16 - 129;
    float ymax = map_height * 16 - 65;

    tcamx += vx * (CAMERA_OFFSET_X_VEL_DELTA / PLAYER_MAX_MOVE_VEL_X);

    if(player_facing_right)
        tcamx += CAMERA_OFFSET_X_DELTA;
    else
        tcamx -= CAMERA_OFFSET_X_DELTA;
    
    {
        float dy = tcamy - camy;
        if(dy > CAMERA_Y_HYSTERESIS)
            tcamy -= CAMERA_Y_HYSTERESIS;
        else if(dy < -CAMERA_Y_HYSTERESIS)
            tcamy += CAMERA_Y_HYSTERESIS;
        else
            tcamy = camy;
    }
    
    if($pressed(UP_BUTTON))
        tcamy -= CAMERA_OFFSET_Y_DELTA_UP;
    if($pressed(DOWN_BUTTON))
        tcamy += CAMERA_OFFSET_Y_DELTA_DOWN;
    if(tcamx < 0) tcamx = 0;
    if(tcamy < 0) tcamy = 0;
    if(tcamx > xmax) tcamx = xmax;
    if(tcamy > ymax) tcamy = ymax;
    camy += (tcamy - camy) * CAMERA_UPDATE_Y_FACTOR;

    float d2camx =
        (tcamx - camx) * CAMERA_UPDATE_X_ALPHA -
        dcamx * CAMERA_UPDATE_X_BETA;
    camx += dcamx * CAMERA_UPDATE_X_DT;
    dcamx += d2camx * CAMERA_UPDATE_X_DT;

    */

    float tcamx = player.getX() - CAMERA_OFFSET_X;
    //float xmax = 1000 * 16 - 129;

    tcamx += player.getVelocityX() * (CAMERA_OFFSET_X_VEL_DELTA / PLAYER_MAX_MOVE_VEL_X);

    if (player.getDirectionX() == Direction::Right)
        tcamx += CAMERA_OFFSET_X_DELTA;
    else
        tcamx -= CAMERA_OFFSET_X_DELTA;
    
    //if (tcamx < 0) tcamx = 0;
    //if(tcamx > xmax) tcamx = xmax;

    float d2camx =
        (tcamx - camera.getX()) * CAMERA_UPDATE_X_ALPHA -
        camera.getVelocityX() * CAMERA_UPDATE_X_BETA;

    camera.incX(camera.getVelocityX() * CAMERA_UPDATE_X_DT);
    camera.incVelocityX(d2camx * CAMERA_UPDATE_X_DT);
}



void updateBullets(int16_t player_x) {

    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            bullet.update(player_x);

            Rect bulletRect = { bullet.getX(), bullet.getY(), 8, 1 };

            for (Enemy &enemy : enemies) {

                if (enemy.isActive() && enemy.getImageIdx() == 0) {

                    Rect enemyRect = enemy.getRect();

                    if (Arduboy2::collide(bulletRect, enemyRect)) {

                        bullet.setActive(false);
                        Serial.println("Explode");
                        enemy.setImageIdx(1);

                        launchParticles(static_cast<int16_t>(enemy.getX() - world.getX()), static_cast<int16_t>(enemy.getY()));

                    }

                }

            }

        }

    }
    
}

void updateEnemies() {

    for (Enemy &enemy : enemies) {

        enemy.update();

    }

}
