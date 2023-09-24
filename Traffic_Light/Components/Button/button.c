#include "gpio.h"
#include "button.h"

bool button_isPressed = false;

void button_disable(void)
{
	HAL_NVIC_DisableIRQ(EXTI0_IRQn);
}

void button_enable(void)
{
	button_isPressed = false;
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
	if(pin == GPIO_PIN_0)
	{
		button_isPressed = true;
	}
}