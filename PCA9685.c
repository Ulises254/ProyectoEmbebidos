#include "PCA9685.h"
#include "I2C.h"

// Direcciones y registros del PCA9685
#define PCA9685_ADDRESS 0x40
#define MODE1 0x00
#define MODE2 0x01
#define PRE_SCALE 0xFE

// Inicializa el módulo PCA9685
void PCA9685_Init(void) {
    I2C_Write(PCA9685_ADDRESS, MODE1, 0x10);  // Reinicia y configura el PCA9685
    I2C_Write(PCA9685_ADDRESS, MODE2, 0x04);  // Modo de salida
    I2C_Write(PCA9685_ADDRESS, PRE_SCALE, 0x79);  // Configura el pre-escaler para 50 Hz (valor calculado para 50 Hz)
    I2C_Write(PCA9685_ADDRESS, MODE1, 0xA1);

}

// Función para controlar el canal del servo
void Servo_SetPosition(uint8_t channel, uint16_t on_value, uint16_t off_value) {
    I2C_Write(PCA9685_ADDRESS, 0x06 + 4 * channel, on_value & 0xFF);     // LEDn_ON_L
    I2C_Write(PCA9685_ADDRESS, 0x07 + 4 * channel, on_value >> 8);       // LEDn_ON_H
    I2C_Write(PCA9685_ADDRESS, 0x08 + 4 * channel, off_value & 0xFF);    // LEDn_OFF_L
    I2C_Write(PCA9685_ADDRESS, 0x09 + 4 * channel, off_value >> 8);      // LEDn_OFF_H
}