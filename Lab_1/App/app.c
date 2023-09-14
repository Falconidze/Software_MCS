#include "app.h"
#include "gpio.h"

void app_run()
{
	GPIOD->ODR &= 0x0000;
	while(1)
	{
		HAL_Delay(500);
		GPIOD->ODR = 0x3000;
		HAL_Delay(500);
		GPIOD->ODR = 0xC000;
		HAL_Delay(500);
	}
}