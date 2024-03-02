


void updatePlayer(uint8_t frameCount) {

    switch (player.getXMovement()) {

        case 0 ... 13:

            player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);

            if (player.getDeccelerate()) {

                if (playerXOffset >= Constants::PLAYER_OFFSET_X_MID) {

                    switch (player.getXMovement()) {

                        case 0 ... 1:
                            playerXOffset = playerXOffset - 26;
                            break;

                        case 2 ... 3:
                            playerXOffset = playerXOffset - 18;
                            break;

                        case 4 ... 5:
                            playerXOffset = playerXOffset - 12;
                            break;

                        case 6 ... 7:
                            playerXOffset = playerXOffset - 8;
                            break;

                        case 8 ... 9:
                            playerXOffset = playerXOffset - 6;
                            break;

                        case 10 ... 11:
                            playerXOffset = playerXOffset - 4;
                            break;

                        case 12 ... 13:
                            playerXOffset = playerXOffset - 2;
                            break;

                    }

                }

            }
            else {

                if (playerXOffset <= Constants::PLAYER_OFFSET_X_MAX) {

                    switch (player.getXMovement()) {

                        case 0 ... 1:
                            playerXOffset = playerXOffset + 26;
                            break;

                        case 2 ... 3:
                            playerXOffset = playerXOffset + 18;
                            break;

                        case 4 ... 5:
                            playerXOffset = playerXOffset + 12;
                            break;

                        case 6 ... 7:
                            playerXOffset = playerXOffset + 8;
                            break;

                        case 8 ... 9:
                            playerXOffset = playerXOffset + 6;
                            break;

                        case 10 ... 11:
                            playerXOffset = playerXOffset + 4;
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


        case 14:

            if (playerXOffset < Constants::PLAYER_OFFSET_X_MID) {
                playerXOffset = playerXOffset + 32;
            }
            else if (playerXOffset > Constants::PLAYER_OFFSET_X_MID) {
                playerXOffset = playerXOffset - 32;
            }

            break;

        case 15 ... 28:

            player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);

            if (player.getDeccelerate()) {

                if (playerXOffset <= Constants::PLAYER_OFFSET_X_MID) {

                    switch (player.getXMovement()) {

                        case 27 ... 28:
                            playerXOffset = playerXOffset + 26;
                            break;

                        case 25 ... 26:
                            playerXOffset = playerXOffset + 18;
                            break;

                        case 23 ... 24:
                            playerXOffset = playerXOffset + 12;
                            break;

                        case 21 ... 22:
                            playerXOffset = playerXOffset + 8;
                            break;

                        case 19 ... 20:
                            playerXOffset = playerXOffset + 6;
                            break;

                        case 17 ... 18:
                            playerXOffset = playerXOffset + 4;
                            break;

                        case 15 ... 16:
                            playerXOffset = playerXOffset + 2;
                            break;

                    }

                }

            }
            else {

                if (playerXOffset >= Constants::PLAYER_OFFSET_X_MIN) {

                    switch (player.getXMovement()) {

                        case 27 ... 28:
                            playerXOffset = playerXOffset - 26;
                            break;

                        case 25 ... 26:
                            playerXOffset = playerXOffset - 18;
                            break;

                        case 23 ... 24:
                            playerXOffset = playerXOffset - 12;
                            break;

                        case 21 ... 22:
                            playerXOffset = playerXOffset - 8;
                            break;

                        case 19 ... 20:
                            playerXOffset = playerXOffset - 6;
                            break;

                        case 17 ... 18:
                            playerXOffset = playerXOffset - 4;
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

// Serial.print(" ");
// Serial.println(playerXOffset);

    // player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);

    if (player.getXMovement() < scenery_XMovement) {

        scenery_XMovement--;
        
    }

    else if (player.getXMovement() > scenery_XMovement) {

        scenery_XMovement++;
        
    }

    // bgPos = (bgPos - (Constants::Movement_X[scenery_XMovement] / 2));
    // xWorld = (xWorld - Constants::Movement_X[scenery_XMovement]);
    // fgPos = (fgPos - Constants::Movement_X[scenery_XMovement] * 2);


    bgPos = (bgPos + (Constants::Movement_X[scenery_XMovement] / 2));
    //xWorld = (xWorld - Constants::Movement_X[scenery_XMovement]);
    fgPos = (fgPos - Constants::Movement_X[scenery_XMovement] / 2);
}


void updateBullets(int16_t player_x) {

    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            bullet.update(player_x);

        }

    }
    
}