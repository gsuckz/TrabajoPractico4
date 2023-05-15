#ifndef HAL_H
#define HAL_H
#include <stdbool.h>
#include <stdint.h>
typedef enum HAL_ModoPin{
    ENTRADA,
    SALIDA
}HAL_ModoPin;

typedef struct pinGPIO pinGPIO;

#define MUX_NUM_PUERTOS 3 
#define MUX_NUM_PINES 13

/**
 * @brief Obtiene el objeto pin que representa un pin fisico
 * @nota Debe verificarse que el puntero no sea NULL (lo que significarìa que no se soporta el pin)
 * @param puerto Número de puerto
 * @param nrPin Número de pin
 * @return pinGPIO const* Puntero al objeto o NULL si no es soportado
 */
pinGPIO const * getPin(uint8_t puerto,uint8_t nrPin);

/**
 * @brief Configura el pin del puerto como entrada o salida, si es salida inicia en 0
 * 
 * @param pin Puntero a objeto pin
 * @param modo HAL_ModoPin "ENTRADA" o "SALIDA"
 */
void configPin(pinGPIO const * pin, HAL_ModoPin modo);
/**
 * @brief Devuelve un Bool con el valor del pin leido
 * 
 * @param pin Puntero a objeto pin
 * @return true Si esta en alto
 * @return false Si esta en bajo
 */
bool readPin(pinGPIO const * pin);
/**
 * @brief Pone el pin del puerto en el valor
 * 
 * 
 * @param pin Puntero a objeto pin
 * @param valor Valor a asignar al pin del puerto 
 */
void writePin(pinGPIO const * pin, bool valor);
/**
 * @brief 
 * 
 * @param pin 
 */
void tooglePin (pinGPIO const * pin );
#endif
