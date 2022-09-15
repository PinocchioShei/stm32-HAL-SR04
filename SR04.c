#include "SR04.h"

int rawCNT=0;

void trig(){
		HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_SET);
    int a;
    a=SysTick->VAL;
    while(SysTick->VAL-a<840);//延时10us
		HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_RESET);
}
//注意：如果工程内已经重写过GPIO中断函数，需要将该函数内容移至你写的函数之中
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
		if (GPIO_Pin == Echo_Pin){
				if(HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin)){
					CountTim->CNT=0;
					HAL_TIM_Base_Start(&counthtim);
				}else{
					rawCNT=CountTim->CNT;
					HAL_TIM_Base_Stop(&counthtim);
				}
		}
}

