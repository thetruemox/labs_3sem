#include "Cool_box.h"

#define BASE_SIZE 1
Cool_box::Cool_box() : Box()
{
    this->temperature = BASE_SIZE;
}

Cool_box::Cool_box(const Cool_box& box) : Box(box)
{
    this->temperature = box.temperature;
}

Cool_box::Cool_box(int l, int w, int h, float mass, float temperature) : Box(l, w, h, mass)
{
    this->temperature = temperature;
}

float Cool_box::get_temperature() const
{
    return this->temperature;
}

void Cool_box::set_temperature(float t)
{
    this->temperature = t;
}

