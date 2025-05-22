
#ifndef __I2C_H
#define __I2C_H

#include <stdint.h>

void I2C_Write(uint8_t device_address, uint8_t register_address, uint8_t data);
int esperar(void);
void I2C_Init(void);
void delay(int count);

#endif // __I2C_H