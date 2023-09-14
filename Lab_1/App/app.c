#include "app.h"
#include "gpio.h"

void app_run()
{
	GPIOD->ODR &= 0x0000;
	while(1)
	{
		HAL_Delay(500);
		GPIOD->ODR = 0x1000;
		HAL_Delay(500);
		GPIOD->ODR = 0x2000;		
	}
}