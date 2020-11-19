#include "Fragile_box.h"

Fragile_box::Fragile_box() : Box()
{
	pressure = 0;
}

Fragile_box::Fragile_box(int l, int w, int h) : Box(l, w, h)
{
	pressure = 0;
}

float Fragile_box::get_pressure() const
{
    return this->pressure;
}

void Fragile_box::set_pressure(float pressure)
{
    this->pressure = pressure;
}
    
