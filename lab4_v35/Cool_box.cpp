#include "Cool_box.h"

/*
Cool_box::Cool_box() : Box()
{
    this->temperature = 36.6f;
    this->type = COOL;
}

Cool_box::Cool_box(float temperature) : Box()
{
    this->temperature = temperature;
    this->type = COOL;
}
*/

Cool_box::Cool_box(int l, int w, int h, float temperature) : Box(l, w, h)
{
    this->temperature = temperature;
    this->type = COOL;
}

float Cool_box::get_temperature() const
{
    return this->temperature;
}

void Cool_box::set_temperature(float temperature)
{
    this->temperature = temperature;
}

