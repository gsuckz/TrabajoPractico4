#include "myhal.h"
#include <chip.h>
#include <stddef.h>

struct pinGPIO {
    uint8_t puerto;
    uint8_t pin;
    uint8_t numRegistroGPIO;
    uint8_t bitRegistroGPIO;
    uint8_t funcion;   
};

static pinGPIO const tablaConfigPinGpio[MUX_NUM_PUERTOS][MUX_NUM_PINES] = {
    [0] = {{0}}, // NO USADO
    [1] = {
        [0]  = {.puerto=1,.pin=0 ,.numRegistroGPIO = 0, .bitRegistroGPIO = 4,  .funcion = 0},
        [1]  = {.puerto=1,.pin=1 ,.numRegistroGPIO = 0, .bitRegistroGPIO = 8,  .funcion = 0},
        [2]  = {.puerto=1,.pin=2 ,.numRegistroGPIO = 0, .bitRegistroGPIO = 9,  .funcion = 0},
        [3]  = {.puerto=1,.pin=3 ,.numRegistroGPIO = 0, .bitRegistroGPIO = 10, .funcion = 0},
        [4]  = {.puerto=1,.pin=4 ,.numRegistroGPIO = 0, .bitRegistroGPIO = 11, .funcion = 0},
        [5]  = {.puerto=1,.pin=5 ,.numRegistroGPIO = 1, .bitRegistroGPIO = 8,  .funcion = 0},
        [6]  = {.puerto=1,.pin=6 ,.numRegistroGPIO = 1, .bitRegistroGPIO = 9,  .funcion = 0},
        [7]  = {.puerto=1,.pin=7 ,.numRegistroGPIO = 1, .bitRegistroGPIO = 0,  .funcion = 0},
        [8]  = {.puerto=1,.pin=8 ,.numRegistroGPIO = 1, .bitRegistroGPIO = 1,  .funcion = 0},
        [9]  = {.puerto=1,.pin=9 ,.numRegistroGPIO = 1, .bitRegistroGPIO = 2,  .funcion = 0},
        [10] = {.puerto=1,.pin=10,.numRegistroGPIO = 1, .bitRegistroGPIO = 3,  .funcion = 0},
        [11] = {.puerto=1,.pin=11,.numRegistroGPIO = 1, .bitRegistroGPIO = 4,  .funcion = 0},
        [12] = {.puerto=1,.pin=12,.numRegistroGPIO = 1, .bitRegistroGPIO = 5,  .funcion = 0}},
    [2] = {
        [0]  = {.puerto=2,.pin= 0,.numRegistroGPIO = 5, .bitRegistroGPIO = 0,  .funcion = 4},
        [1]  = {.puerto=2,.pin= 1,.numRegistroGPIO = 5, .bitRegistroGPIO = 1,  .funcion = 4},
        [2]  = {.puerto=2,.pin= 2,.numRegistroGPIO = 5, .bitRegistroGPIO = 2,  .funcion = 4},
        [3]  = {.puerto=2,.pin= 3,.numRegistroGPIO = 5, .bitRegistroGPIO = 3,  .funcion = 4},
        [4]  = {.puerto=2,.pin= 4,.numRegistroGPIO = 5, .bitRegistroGPIO = 4,  .funcion = 4},
        [5]  = {.puerto=2,.pin= 5,.numRegistroGPIO = 5, .bitRegistroGPIO = 5,  .funcion = 4},
        [6]  = {.puerto=2,.pin= 6,.numRegistroGPIO = 5, .bitRegistroGPIO = 6,  .funcion = 4},
        [7]  = {.puerto=2,.pin= 7,.numRegistroGPIO = 0, .bitRegistroGPIO = 7,  .funcion = 0},
        [8]  = {.puerto=2,.pin= 8,.numRegistroGPIO = 5, .bitRegistroGPIO = 7,  .funcion = 4},
        [9]  = {.puerto=2,.pin= 9,.numRegistroGPIO = 1, .bitRegistroGPIO = 10, .funcion = 0},
        [10] = {.puerto=2,.pin=10,.numRegistroGPIO = 0, .bitRegistroGPIO = 14, .funcion = 0},
        [11] = {.puerto=2,.pin=11,.numRegistroGPIO = 1, .bitRegistroGPIO = 11, .funcion = 0},
        [12] = {.puerto=2,.pin=12,.numRegistroGPIO = 1, .bitRegistroGPIO = 12, .funcion = 0}}
};

pinGPIO const * getPin(uint8_t puerto,uint8_t nrPin)
{
    pinGPIO const *valor = NULL;
    if (puerto < MUX_NUM_PUERTOS && nrPin < MUX_NUM_PINES)
        valor = &tablaConfigPinGpio[puerto][nrPin];
    return valor;
}


void configPin(pinGPIO const * pin, HAL_ModoPin modo)
{   
    Chip_SCU_PinMuxSet(pin->puerto, pin->pin, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | pin->funcion);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, pin->numRegistroGPIO, pin->bitRegistroGPIO, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, pin->numRegistroGPIO, pin->bitRegistroGPIO, modo);
}   


bool readPin(pinGPIO const * pin)
    {
        return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, pin->numRegistroGPIO, pin->bitRegistroGPIO);
    }


void writePin(pinGPIO const * pin, bool valor)
    {
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, pin->numRegistroGPIO, pin->bitRegistroGPIO, valor);        
        return;
    }

void tooglePin (pinGPIO const * pin ){
    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, pin->numRegistroGPIO, pin->bitRegistroGPIO);
}