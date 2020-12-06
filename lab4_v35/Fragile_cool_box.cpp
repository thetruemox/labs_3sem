#include "Fragile_cool_box.h"

/*
Fragile_cool_box::Fragile_cool_box() : Box()
{
	this->temperature = 36.6f;
	this->pressure = 0;
	this->type = FRAGILE_COOL;
}

Fragile_cool_box::Fragile_cool_box(float temperature) : Box()
{
	this->temperature = temperature;
	this->pressure = 0;
	this->type = FRAGILE_COOL;
}
*/

Fragile_cool_box::Fragile_cool_box(int l, int w, int h, float temperature, float max_pressure) : Box(l, w, h)
{
	this->temperature = temperature;
	this->type = FRAGILE_COOL;
}

float Fragile_cool_box::get_max_pressure() const
{
	return this->max_pressure;
}

float Fragile_cool_box::get_temperature() const
{
	return this->temperature;
}

void Fragile_cool_box::set_max_pressure(float max_pressure)
{
	if (max_pressure >= 0)
	{
		this->max_pressure = max_pressure;
	}
}

void Fragile_cool_box::set_temperature(float temperature)
{
	this->temperature = temperature;
}
