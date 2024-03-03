

void updatePlayer(uint8_t frameCount) {

    switch (player.getXMovement()) {

        case Constants::PLAYER_SPEED_MIN ... Constants::PLAYER_SPEED_MID - 1:

            player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);

            if (player.isDecceleratingX()) {

                if (playerXOffset >= Constants::PLAYER_OFFSET_X_MID) {

                    playerXOffset =playerXOffset - Constants::Camera_Offset_X[player.getXMovement()];

                }

            }
            else {

                if (playerXOffset <= Constants::PLAYER_OFFSET_X_MAX) {

                    switch (player.getXMovement()) {

                        case 0 ...11:
                            playerXOffset =playerXOffset + Constants::Camera_Offset_X[player.getXMovement()];
                            break;

                        case 12 ... 13:

                            if (playerXOffset <= Constants::PLAYER_OFFSET_X_MID) {
                                playerXOffset = playerXOffset + 2;
                            }

                            break;

                    }

                }

            }

            break;

        case Constants::PLAYER_SPEED_MID:

            if (playerXOffset < Constants::PLAYER_OFFSET_X_MID) {
                playerXOffset = playerXOffset + 32;
            }
            else if (playerXOffset > Constants::PLAYER_OFFSET_X_MID) {
                playerXOffset = playerXOffset - 32;
            }

            break;


        case Constants::PLAYER_SPEED_MID + 1 ... Constants::PLAYER_SPEED_MAX:

            player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);

            if (player.isDecceleratingX()) {

                if (playerXOffset <= Constants::PLAYER_OFFSET_X_MID) {

                    playerXOffset =playerXOffset + Constants::Camera_Offset_X[player.getXMovement()];

                }

            }
            else {

                if (playerXOffset >= Constants::PLAYER_OFFSET_X_MIN) {

                    switch (player.getXMovement()) {

                        case 18 ... 28:
                            playerXOffset =playerXOffset - Constants::Camera_Offset_X[player.getXMovement()];
                            break;

                        case 15 ... 16:

                            if (playerXOffset <= Constants::PLAYER_OFFSET_X_MID) {
                                playerXOffset = playerXOffset - 2;
                            }

                            break;

                    }

                }

            }

            break;

    }







// Serial.print(player.getYMovement());

    switch (player.getYMovement()) {

        case Constants::PLAYER_SPEED_MIN ... Constants::PLAYER_SPEED_MID - 1:
            {
                int8_t yInc = Constants::Movement_X[player.getYMovement()];

                if (player.getY() + yInc >= 0) {        
                    player.setY(player.getY() + Constants::Movement_Y[player.getYMovement()]);
                }
                else {
                    player.setY(0);

                }

            }

            break;


        case Constants::PLAYER_SPEED_MID:

            break;

        case Constants::PLAYER_SPEED_MID + 1 ... Constants::PLAYER_SPEED_MAX:
            {
                int8_t yInc = Constants::Movement_Y[player.getYMovement()];

                if (player.getY() + yInc <= 700) {        
                    player.setY(player.getY() + Constants::Movement_Y[player.getYMovement()]);
                }
                else {
                    player.setY(700);

                }

            }

            break;

    }



    // Update the foreground and background positions relative to the world (middle ground) ..

    if (player.getXMovement() < scenery_XMovement) {

        scenery_XMovement--;
        
    }

    else if (player.getXMovement() > scenery_XMovement) {

        scenery_XMovement++;
        
    }

    world.setBackgroundX(world.getBackgroundX() + (Constants::Movement_X[scenery_XMovement] / 2));
    world.setForegroundX(world.getForegroundX() - (Constants::Movement_X[scenery_XMovement] / 2));

}


void updateBullets(int16_t player_x) {

    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            bullet.update(player_x);

        }

    }
    
}