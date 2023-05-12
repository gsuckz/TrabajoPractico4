#ifndef MYBSP_H
#define MYBSP_H
#include "myhal.h"

typedef struct puertoPin{
    int puerto;
    int pin;
}puertoPin;

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

void set_led(LED led, bool estado);
bool getBotonState(boton bot);
void toogleLed(LED led);
#endif