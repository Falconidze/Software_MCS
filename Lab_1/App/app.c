#include "app.h"
#include "gpio.h"

void app_run()
{
	while(1)
	{
		HAL_Delay(100);
		GPIOD->ODR = 0x1000;
		HAL_Delay(100);
		GPIOD->ODR = 0x2000;		
		HAL_Delay(100);
		GPIOD->ODR = 0x4000;
		HAL_Delay(100);
		GPIOD->ODR = 0x8000;
		HAL_Delay(50);
		GPIOD->ODR = 0x0000;
		for(int i = 0; i < 3; i++)
		{		
			HAL_Delay(500);
			GPIOD->ODR = 0xF000;
			HAL_Delay(500);		
			GPIOD->ODR = 0x0000;			
		}
	}
}