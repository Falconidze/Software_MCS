#ifndef BUTTON_H
#define BUTTON_H
#include "stdbool.h"

extern bool button_isPressed;

void button_disable(void);
void button_enable(void);

#endif