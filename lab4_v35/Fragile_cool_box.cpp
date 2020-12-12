#include "Fragile_cool_box.h"

Fragile_cool_box::Fragile_cool_box(int l, int w, int h, float mass, float temperature, float max_pressure) : Box(l, w, h, mass)
{
	this->temperature = temperature;
	this->max_pressure = max_pressure;
}
