


void updatePlayer(uint8_t frameCount) {

    player.setX(player.getX() + Constants::Movement_X[player.getXMovement()]);

    if (player.getXMovement() < scenery_XMovement) {

        scenery_XMovement--;
        
    }

    else if (player.getXMovement() > scenery_XMovement) {

        scenery_XMovement++;
        
    }

    bgPos = (bgPos - (Constants::Movement_X[scenery_XMovement] / 2));
    xWorld = (xWorld - Constants::Movement_X[scenery_XMovement]);
    fgPos = (fgPos - Constants::Movement_X[scenery_XMovement] * 2);


}
