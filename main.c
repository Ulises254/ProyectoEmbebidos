#include "PCA9685.h"
#include "Utils.h"

int main(void) {
    I2C_Init();    // Inicializa I2C
    PCA9685_Init(); // Inicializa PCA9685

    while (1) {

/////SERVO 1
        // Mueve el servo a 0 grados (1 ms)
        Servo_SetPosition(0, 0, SERVO_MIN);
        delay(1000000);  // Espera

        // Mueve el servo a 90 grados (1.5 ms)
        Servo_SetPosition(0, 0, SERVO_MID);
        delay(1000000);  // Espera

        // Mueve el servo a 180 grados (2 ms)
        Servo_SetPosition(0, 0, SERVO_MAX);
        delay(1000000);  // Espera
/////SERVO 2
        // Mueve el servo a 0 grados (1 ms)
        Servo_SetPosition(1, 0, SERVO_MIN);
        delay(1000000);  // Espera

        // Mueve el servo a 90 grados (1.5 ms)
        Servo_SetPosition(1, 0, SERVO_MID);
        delay(1000000);  // Espera

        // Mueve el servo a 180 grados (2 ms)
        Servo_SetPosition(1, 0, SERVO_MAX);
        delay(1000000);  // Espera

////SERVO 3
       // Mueve el servo a 0 grados (1 ms)
      Servo_SetPosition(2, 0, SERVO_MIN);
      delay(1000000);  // Espera

      // Mueve el servo a 90 grados (1.5 ms)
      Servo_SetPosition(2, 0, SERVO_MID);
      delay(1000000);  // Espera

       // Mueve el servo a 180 grados (2 ms)
       Servo_SetPosition(2, 0, SERVO_MAX);
       delay(1000000);  // Espera

////SERVO 4
       // Mueve el servo a 0 grados (1 ms)
        Servo_SetPosition(3, 0, SERVO_MIN);
        delay(1000000);  // Espera

      // Mueve el servo a 90 grados (1.5 ms)
        Servo_SetPosition(3, 0, SERVO_MID);
        delay(1000000);  // Espera

      // Mueve el servo a 180 grados (2 ms)
        Servo_SetPosition(3, 0, SERVO_MAX);
        delay(1000000);  // Espera

////SERVO 5
        // Mueve el servo a 0 grados (1 ms)
        Servo_SetPosition(4, 0, SERVO_MIN);
        delay(1000000);  // Espera

       // Mueve el servo a 90 grados (1.5 ms)
        Servo_SetPosition(4, 0, SERVO_MID);
        delay(1000000);  // Espera

       // Mueve el servo a 180 grados (2 ms)
        Servo_SetPosition(4, 0, SERVO_MAX);
        delay(1000000);  // Espera

    }
}
