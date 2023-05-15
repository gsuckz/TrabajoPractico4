#include "mybsp.h"

#define LED_R_PORT 2
#define LED_R_PIN 0
#define LED_G_PORT 2
#define LED_G_PIN 1
#define LED_B_PORT 2
#define LED_B_PIN 2
#define LED_1_PORT 2
#define LED_1_PIN 10
#define LED_2_PORT 2
#define LED_2_PIN 11
#define LED_3_PORT 2
#define LED_3_PIN 12
#define TEC_1_PORT 1
#define TEC_1_PIN 0
#define TEC_2_PORT 1
#define TEC_2_PIN 1
#define TEC_3_PORT 1
#define TEC_3_PIN 2
#define TEC_4_PORT 1
#define TEC_4_PIN 6


typedef struct puertoPin{
    uint8_t puerto;
    uint8_t pin;
}puertoPin;

puertoPin botArray[BOT_MAX] = {
    [TEC_1] = {TEC_1_PORT,TEC_1_PIN},
    [TEC_2] = {TEC_2_PORT,TEC_2_PIN},
    [TEC_3] = {TEC_3_PORT,TEC_3_PIN},
    [TEC_4] = {TEC_4_PORT,TEC_4_PIN},
};

puertoPin ledArray[LED_MAX] = {
    [LED_1] = {LED_1_PORT,LED_1_PIN},
    [LED_2] = {LED_2_PORT,LED_2_PIN},
    [LED_3] = {LED_3_PORT,LED_3_PIN},
    [LED_R] = {LED_R_PORT,LED_R_PIN},
    [LED_G] = {LED_G_PORT,LED_G_PIN},
    [LED_B] = {LED_B_PORT,LED_B_PIN},
};


void configBoard(void){
    for (int i=0;i<(LED_MAX);i++)
    {
        pinGPIO const * const pin = getPin(ledArray[i].puerto,ledArray[i].pin);
        configPin(pin, SALIDA);
    };
    for (int i=0;i<(BOT_MAX);i++)
    {
        pinGPIO const * const pin = getPin(botArray[i].puerto,botArray[i].pin);
        configPin(pin, ENTRADA);
    };

}

void set_led(LED led, bool estado)
{
    pinGPIO const * const pin = getPin(ledArray[led].puerto,ledArray[led].pin);
    writePin(pin,estado);

}

bool getBotonState(boton bot)
{
    pinGPIO const * const pin = getPin(botArray[bot].puerto,botArray[bot].pin);
    return readPin(pin);
}

void toogleLed(LED led)
{
    pinGPIO const * const pin = getPin(ledArray[led].puerto,ledArray[led].pin);
    tooglePin(pin);
    return;
}