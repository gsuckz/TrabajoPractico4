#include "myhal.h"
#include <chip.h>

static pinGPIO const tablaConfigPinGpio[MUX_NUM_PUERTOS][MUX_NUM_PINES] = {
    [0] = {0}, // NO USADO
    [1] = {
        [0]  = {.numRegistroGPIO = 0, .bitRegistroGPIO = 4,  .funcion = 0},
        [1]  = {.numRegistroGPIO = 0, .bitRegistroGPIO = 8,  .funcion = 0},
        [2]  = {.numRegistroGPIO = 0, .bitRegistroGPIO = 9,  .funcion = 0},
        [3]  = {.numRegistroGPIO = 0, .bitRegistroGPIO = 10, .funcion = 0},
        [4]  = {.numRegistroGPIO = 0, .bitRegistroGPIO = 11, .funcion = 0},
        [5]  = {.numRegistroGPIO = 1, .bitRegistroGPIO = 8,  .funcion = 0},
        [6]  = {.numRegistroGPIO = 1, .bitRegistroGPIO = 9,  .funcion = 0},
        [7]  = {.numRegistroGPIO = 1, .bitRegistroGPIO = 0,  .funcion = 0},
        [8]  = {.numRegistroGPIO = 1, .bitRegistroGPIO = 1,  .funcion = 0},
        [9]  = {.numRegistroGPIO = 1, .bitRegistroGPIO = 2,  .funcion = 0},
        [10] = {.numRegistroGPIO = 1, .bitRegistroGPIO = 3,  .funcion = 0},
        [11] = {.numRegistroGPIO = 1, .bitRegistroGPIO = 4,  .funcion = 0},
        [12] = {.numRegistroGPIO = 1, .bitRegistroGPIO = 5,  .funcion = 0}},
    [2] = {
        [0]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 0,  .funcion = 4},
        [1]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 1,  .funcion = 4},
        [2]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 2,  .funcion = 4},
        [3]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 3,  .funcion = 4},
        [4]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 4,  .funcion = 4},
        [5]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 5,  .funcion = 4},
        [6]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 6,  .funcion = 4},
        [7]  = {.numRegistroGPIO = 0, .bitRegistroGPIO = 7,  .funcion = 0},
        [8]  = {.numRegistroGPIO = 5, .bitRegistroGPIO = 7,  .funcion = 4},
        [9]  = {.numRegistroGPIO = 1, .bitRegistroGPIO = 10, .funcion = 0},
        [10] = {.numRegistroGPIO = 0, .bitRegistroGPIO = 14, .funcion = 0},
        [11] = {.numRegistroGPIO = 0, .bitRegistroGPIO = 11, .funcion = 0},
        [12] = {.numRegistroGPIO = 0, .bitRegistroGPIO = 12, .funcion = 0}}
};

/**
 * @brief Configura el pin del puerto como entrada o salida 
 * 
 * @param puerto Puerto al que pertenece el pin, solo 1 o 2
 * @param pin Pin del puerto que se confiegura como entrada o salida 
 * @param modo HAL_ModoPin "entrada" o "salida", si es salida, inicia en 0
 */
void configPin(int puerto, int pin, HAL_ModoPin modo)
{   
    Chip_SCU_PinMuxSet(puerto, pin, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | tablaConfigPinGpio[puerto][pin].funcion);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, tablaConfigPinGpio[puerto][pin].numRegistroGPIO, tablaConfigPinGpio[puerto][pin].bitRegistroGPIO, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, tablaConfigPinGpio[puerto][pin].numRegistroGPIO, tablaConfigPinGpio[puerto][pin].bitRegistroGPIO, modo);
}   

/**
 * @brief Devuelve un Bool con el valor del pin leido
 * 
 * @param puerto Puerto donde esta el pin, solo 1 o 2
 * @param pin Pin del puerto
 * @return true Si esta en alto
 * @return false Si esta en bajo
 */
bool readPin(int puerto, int pin)
    {
        return Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, tablaConfigPinGpio[puerto][pin].numRegistroGPIO, tablaConfigPinGpio[puerto][pin].bitRegistroGPIO);
    }

/**
 * @brief Pone el pin del puerto en el valor
 * 
 * 
 * @param puerto Puerto del pin
 * @param pin Pin del puerto
 * @param valor Valor a asignar al pin del puerto 
 */
void writePin(int puerto, int pin, bool valor)
    {
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, tablaConfigPinGpio[puerto][pin].numRegistroGPIO, tablaConfigPinGpio[puerto][pin].bitRegistroGPIO, valor);
        return;
    }

void tooglePin (int puerto, int pin ){
    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, tablaConfigPinGpio[puerto][pin].numRegistroGPIO, tablaConfigPinGpio[puerto][pin].bitRegistroGPIO);
}