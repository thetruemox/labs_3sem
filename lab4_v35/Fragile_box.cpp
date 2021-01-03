#include "Fragile_box.h"

#define BASE_SIZE 1
Fragile_box::Fragile_box() : Box()
{
	this->max_pressure = BASE_SIZE;
	this->pressure = 0;
}

Fragile_box::Fragile_box(const Fragile_box& box) : Box(box)
{
	this->pressure = box.pressure;
	this->max_pressure = box.max_pressure;
}

Fragile_box::Fragile_box(int l, int w, int h, float mass, float max_pressure) : Box(l, w, h, mass)
{
	if (max_pressure < 0)
	{
		throw "Fragile_box: Incorrect values specified";
	}
	else
	{
		this->max_pressure = max_pressure;
		this->pressure = 0;
	}
}

Box* Fragile_box::copy(Box* obj)
{
	Fragile_box* ptr = dynamic_cast<Fragile_box*>(obj);
	if (ptr == nullptr) return nullptr;

	Fragile_box* copy_obj = new Fragile_box;

	copy_obj->set_all(obj->get_length(), obj->get_width(), obj->get_height());
	copy_obj->set_ID(obj->get_ID());
	copy_obj->set_mass(obj->get_mass());
	copy_obj->set_pressure(ptr->get_pressure());
	copy_obj->set_max_pressure(ptr->get_max_pressure());

	return copy_obj;
}

void Fragile_box::set_pressure(float mass)
{
	if (mass >= 0) this->pressure = mass;
	else throw "Negative pressure";
}

void Fragile_box::set_max_pressure(float max)
{
	if (max >= 0) this->max_pressure = max;
	else throw "Negative pressure";
}

float Fragile_box::get_pressure() const
{
	return this->pressure;
}

float Fragile_box::get_max_pressure() const
{
	return this->max_pressure;
}

    
