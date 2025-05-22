#ifndef __PCA9685_H
#define __PCA9685_H

#include <stdint.h>

// Variables para los valores de posición del servo
#define SERVO_MIN  90 // 1 ms para 0 grados-----90
#define SERVO_MID  310  // 1.5 ms para 90 grados---310
#define SERVO_MAX 530 // 2 ms para 180 grados----530

void PCA9685_Init(void);
void Servo_SetPosition(uint8_t channel, uint16_t on_value, uint16_t off_value);

#endif // __PCA9685_H
