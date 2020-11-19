#include "Cold_box.h"

Cold_box::Cold_box() : Box()
{
    this->temperature = 36.6f;
}

Cold_box::Cold_box(float temperature) : Box()
{
    this->temperature = temperature;
}

Cold_box::Cold_box(int l, int w, int h, float temperature) : Box(l, w, h)
{
    this->temperature = temperature;
}

float Cold_box::get_temperature() const
{
    return this->temperature;
}

void Cold_box::set_temperature(float temperature)
{
    this->temperature = temperature;
}

