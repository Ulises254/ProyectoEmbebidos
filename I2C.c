#include<stdbool.h>
#include "I2C.h"

// Definiciones de registros del puerto y del módulo I2C (igual que antes)
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCI2C_R        (*((volatile uint32_t *)0x400FE620))
#define SYSCTL_PRGPIO_R        (*((volatile uint32_t *)0x400FEA08))
#define GPIO_PORTB_AFSEL_R      (*((volatile uint32_t *)0x40059420))
#define GPIO_PORTB_ODR_R        (*((volatile uint32_t *)0x4005950C))
#define GPIO_PORTB_DEN_R        (*((volatile uint32_t *)0x4005951C))
#define GPIO_PORTB_PCTL_R       (*((volatile uint32_t *)0x4005952C))
#define GPIO_PORTB_DATA_R       (*((volatile uint32_t *)0x400593FC))

#define I2C0_MSA_R              (*((volatile uint32_t *)0x40020000))
#define I2C0_MCS_R              (*((volatile uint32_t *)0x40020004))
#define I2C0_MDR_R              (*((volatile uint32_t *)0x40020008))
#define I2C0_MTPR_R             (*((volatile uint32_t *)0x4002000C))
#define I2C0_MCR_R              (*((volatile uint32_t *)0x40020020))

// Definición de bits de control para I2C
#define I2C_MCS_RUN 0x00000001
#define I2C_MCS_START 0x00000002
#define I2C_MCS_STOP 0x00000004
#define I2C_MCS_ACK 0x00000008
#define I2C_MCS_ERROR 0x00000002

int i=0;
int error;

// Función para escribir datos por I2C
void I2C_Write(uint8_t device_address, uint8_t register_address, uint8_t data) {

    while(I2C0_MCS_R&0x00000001){};

    I2C0_MSA_R = (device_address << 1) & 0xFE;  // Dirección del esclavo
    I2C0_MDR_R = register_address;  // Registro al que escribir
    I2C0_MCS_R = (I2C_MCS_START | I2C_MCS_RUN);  // Inicia la transmisión
    for(i=0;i<150;i++){}
    esperar();


    I2C0_MDR_R = data;  // Enviar el dato
    I2C0_MCS_R = (I2C_MCS_STOP | I2C_MCS_RUN);  // Condición de parada
    for(i=0;i<150;i++){}
    esperar();

}

// Función de delay simple
int esperar(){
    while(I2C0_MCS_R&0x00000001){}; //Espero a que la transmisión acabe
      if(I2C0_MCS_R&0x00000002==1){ //¿Hubo error?
          error=1;
          return error;
      };
      return 0;

}


// Inicialización básica de I2C
void I2C_Init(void) {
    // Configuración de pines y módulo I2C, similar a la que ya tienes en tu código
    SYSCTL_RCGCGPIO_R |= 0x02;   // Habilitar puerto B
    SYSCTL_RCGCI2C_R |= 0x01;    // Habilitar I2C módulo 0
    while((SYSCTL_PRGPIO_R&0x0002) == 0){};
    while(I2C0_MCS_R&0x00000001){};


    GPIO_PORTB_AFSEL_R |= 0x0C;  // Activar funciones alternativas para PB2 y PB3
    GPIO_PORTB_ODR_R |= 0x08;    // Activar Open-Drain para PB3 (SDA)
    GPIO_PORTB_DEN_R |= 0x0C;    // Habilitar el pin digital para PB2 y PB3
    GPIO_PORTB_PCTL_R = 0x00002200;

    I2C0_MCR_R = 0x10;           // Inicializar el maestro I2C
    I2C0_MTPR_R = 0x07;          // Configuración de velocidad de I2C para ~100kHz
}

