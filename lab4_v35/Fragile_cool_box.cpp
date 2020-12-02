#include "Fragile_cool_box.h"

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

Fragile_cool_box::Fragile_cool_box(int l, int w, int h, float temperature) : Box(l, w, h)
{
	this->temperature = temperature;
	this->type = FRAGILE_COOL;
}

float Fragile_cool_box::get_pressure() const
{
	return this->pressure;
}

float Fragile_cool_box::get_temperature() const
{
	return this->temperature;
}

void Fragile_cool_box::set_pressure(float pressure)
{
	if (pressure >= 0)
	{
		this->pressure = pressure;
	}
}

void Fragile_cool_box::set_temperature(float temperature)
{
	this->temperature = temperature;
}
