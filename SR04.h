#ifndef __SR04__
#define __SR04__

#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "main.h"
#include "tim.h"

#define CountTim TIM2
#define counthtim htim2

extern int rawCNT;

void trig();

#endif

