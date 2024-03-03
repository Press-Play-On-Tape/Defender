

void updatePlayer(uint8_t frameCount) {

    player.incX(player.getAccelerationX());
    player.incY(player.getAccelerationY());

    camera.incX(player.getAccelerationX());

}


void updateCamera(uint8_t frameCount) {

    int16_t x = player.getX() - camera.getX();

Serial.print("x = ");
Serial.println(x);

    switch (player.getAccelerationIdxX()) {

        case Constants::Player_Acceleration_Left_Max ... Constants::Player_Acceleration_Left_Min:

            if (player.isDecceleratingX()) {

                if (x >= Constants::Player_Offset_X_Mid) {
Serial.println("A1");
                    camera.incX(Constants::Camera_Offset_X[player.getAccelerationIdxX()]);

                }

            }
            else {

                if (x <= Constants::Player_Offset_X_Max) {

                    switch (player.getAccelerationIdxX()) {

                        case 0 ...11:
Serial.println("A2");
                            camera.incX(-Constants::Camera_Offset_X[player.getAccelerationIdxX()]);
                            break;

                        case 12 ... 13:

                            if (x <= Constants::Player_Offset_X_Mid) {
Serial.println("A3");
                                camera.incX(-2);
                            }

                            break;

                    }

                }

            }

            break;

        case Constants::Player_Acceleration_Stationary:

            if (x < Constants::Player_Offset_X_Mid) {
Serial.println("A4");
                camera.incX(-32);
            }
            else if (x > Constants::Player_Offset_X_Mid) {
Serial.println("A5");
                camera.incX(32);
            }

            break;


        case Constants::Player_Acceleration_Right_Min ... Constants::Player_Acceleration_Right_Max:

            if (player.isDecceleratingX()) {

                if (x <= Constants::Player_Offset_X_Mid) {
Serial.println("A6");

                    camera.incX(-Constants::Camera_Offset_X[player.getAccelerationIdxX()]);

                }

            }
            else {

                if (x >= Constants::Player_Offset_X_Min) {

                    switch (player.getAccelerationIdxX()) {

                        case 18 ... 28:
Serial.println("A7");
                            camera.incX(Constants::Camera_Offset_X[player.getAccelerationIdxX()]);
                            break;

                        case 15 ... 16:

                            if (camera.getX() <= Constants::Player_Offset_X_Mid) {
Serial.println("A8");
                                camera.incX(2);
                            }

                            break;

                    }

                }

            }

            break;

    }

}


void updateBullets(int16_t player_x) {

    for (Bullet &bullet : bullets) {

        if (bullet.isActive()) {

            bullet.update(player_x);

        }

    }
    
}