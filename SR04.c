#include "SR04.h"

int rawCNT=0;

void trig(){
		HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_SET);
    int a;
    a=SysTick->VAL;
    while(SysTick->VAL-a<840);//��ʱ10us
		HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_RESET);
}
//ע�⣺����������Ѿ���д��GPIO�жϺ�������Ҫ���ú�������������д�ĺ���֮��
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

