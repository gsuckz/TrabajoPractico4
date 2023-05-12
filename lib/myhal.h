#ifndef HAL_H
#define HAL_H
#include <stdbool.h>
#include <stdint.h>
typedef enum HAL_ModoPin{
    entrada,
    salida
}HAL_ModoPin;

typedef struct pinGPIO {
    uint8_t numRegistroGPIO;
    uint8_t bitRegistroGPIO;
    uint8_t funcion;   
}pinGPIO;

#define MUX_NUM_PUERTOS 3 
#define MUX_NUM_PINES 13

void configPin(int puerto, int pin, HAL_ModoPin modo);
bool readPin(int puerto, int pin);
void writePin(int puerto, int pin, bool valor);
#endif
