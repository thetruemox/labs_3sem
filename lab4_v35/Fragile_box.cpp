#include "Fragile_box.h"


Fragile_box::Fragile_box() : Box()
{
	this->max_pressure = 100.0f;
}

Fragile_box::Fragile_box(int l, int w, int h, float mass, int max_pressure) : Box(l, w, h, mass)
{
	this->max_pressure = max_pressure;
}

    
