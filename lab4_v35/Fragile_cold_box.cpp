#include "Fragile_cold_box.h"

Fragile_cold_box::Fragile_cold_box() : Box()
{
	this->temperature = 36.6f;
	this->pressure = 0;
	this->type = FRAGILE_COLD;
}

Fragile_cold_box::Fragile_cold_box(float temperature) : Box()
{
	this->temperature = temperature;
	this->pressure = 0;
	this->type = FRAGILE_COLD;
}

Fragile_cold_box::Fragile_cold_box(int l, int w, int h, float temperature) : Box(l, w, h)
{
	this->temperature = temperature;
	this->type = FRAGILE_COLD;
}

float Fragile_cold_box::get_pressure() const
{
	return this->pressure;
}

float Fragile_cold_box::get_temperature() const
{
	return this->temperature;
}

void Fragile_cold_box::set_pressure(float pressure)
{
	if (pressure >= 0)
	{
		this->pressure = pressure;
	}
}

void Fragile_cold_box::set_temperature(float temperature)
{
	this->temperature = temperature;
}
