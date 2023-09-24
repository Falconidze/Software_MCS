#include "app.h"
#include "light.h"
#include "stdint.h"
#include "tim.h"
#include "button.h"

// Variants
/*
1. Red
2. Red + Yellow
3. Green
4. Green blink
5. Yelow
*/

enum trafic_light_mode
{
	yelow_blink = 0,
	red,
	red_yellow,
	green,
	green_blink,
	yelow,
};

void app_init(void)
{
	
	light_set_color_state(light_all, light_off);
}	

void app_run(void)
{
	while(1)
	{
		if ((button_isPressed == false) && (HAL_GPIO_ReadPin(LED_GREEN_GPIO_Port, LED_GREEN_Pin) == GPIO_PIN_RESET))
		{
			light_set_color_state(light_green, light_on);
		}
		if (button_isPressed == true)
		{
			button_disable();
			
			for(int i = 0; i < 6; i++)
			{
				if (HAL_GPIO_ReadPin(LED_GREEN_GPIO_Port, LED_GREEN_Pin) == GPIO_PIN_RESET)
				{
					light_set_color_state(light_green, light_on);
					HAL_Delay(500);
				}
				else if (HAL_GPIO_ReadPin(LED_GREEN_GPIO_Port, LED_GREEN_Pin) == GPIO_PIN_SET)
				{
					light_set_color_state(light_green, light_off);
					HAL_Delay(500);
				}
			}
			
			light_set_color_state(light_all, light_off);
			light_set_color_state(light_yellow, light_on);
			HAL_Delay(3000);
			
			light_set_color_state(light_yellow, light_off);
			light_set_color_state(light_red, light_on);
			HAL_Delay(10000);
			
			light_set_color_state(light_yellow, light_on);
			HAL_Delay(3000);
			
			light_set_color_state(light_all, light_off);
			light_set_color_state(light_green, light_on);
			button_enable();
		}
	}
}

