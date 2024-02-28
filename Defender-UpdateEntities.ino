


void updatePlayer(uint8_t frameCount) {

// Serial.print("Inc ");
// Serial.println(Constants::Movement_X[player.getXMovement()]);


int16_t playerX = (player.getX() - xWorld);
int8_t inc = Constants::Movement_X[player.getXMovement()];

Serial.print(player.getXMovement());
Serial.print(" ");
Serial.print(playerX);
Serial.print(" ");



    switch (player.getXMovement()) {

        case 0 ... 13:
            Serial.print("left");
            player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);
            if (playerX < 800) {
                playerXOffset = playerXOffset + 2;
            }
            break;

        case 14:
            Serial.print("none");
            if (playerX > 450 && playerX < 800) {
                playerXOffset = playerXOffset + 2;
            }
            else if (playerX > 100 && playerX < 450) {
                playerXOffset = playerXOffset - 2;
            }

            break;

        case 15 ... 28:
            Serial.print("right");
            player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);
            if (playerX > 100) {
                playerXOffset = playerXOffset - 2;
            }
            break;

    }

Serial.print(" ");
Serial.println(playerXOffset);

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
