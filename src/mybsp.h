#ifndef MYBSP_H
#define MYBSP_H
#include "myhal.h"

typedef enum LED{
    LED_1,
    LED_2,
    LED_3,
    LED_R,
    LED_G,
    LED_B,
    LED_MAX
}LED;

typedef enum boton{
    TEC_1,
    TEC_2,
    TEC_3,
    TEC_4,
    BOT_MAX
}boton;

/**
 * @brief 
 * 
 */
void configBoard(void);
/**
 * @brief
 * 
 * @param led 
 * @param estado 
 */
void set_led(LED led, bool estado);
/**
 * @brief 
 * 
 * @param bot 
 * @return true 
 * @return false 
 */
bool getBotonState(boton bot);
/**
 * @brief 
 * 
 * @param led 
 */
void toogleLed(LED led);
#endif