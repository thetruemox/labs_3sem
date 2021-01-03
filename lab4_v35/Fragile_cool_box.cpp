#include "Fragile_cool_box.h"

#define BASE_SIZE 1
Fragile_cool_box::Fragile_cool_box() : Box()
{
	this->set_temperature(BASE_SIZE);
	this->set_max_pressure(BASE_SIZE);
	this->set_pressure(0);
}

Fragile_cool_box::Fragile_cool_box(const Fragile_cool_box& box) : Box(box)
{
	this->set_temperature(box.get_temperature());
	this->set_max_pressure(box.get_max_pressure());
	this->set_pressure(box.get_pressure());
}

Box* Fragile_cool_box::copy(Box* obj)
{
	Fragile_box* f_ptr = dynamic_cast<Fragile_box*>(obj);
	Cool_box* c_ptr = dynamic_cast<Cool_box*>(obj);

	if (f_ptr == nullptr || c_ptr == nullptr) return nullptr;

	Fragile_cool_box* copy_obj = new Fragile_cool_box;

	copy_obj->set_all(obj->get_length(), obj->get_width(), obj->get_height());
	copy_obj->set_ID(obj->get_ID());
	copy_obj->set_mass(obj->get_mass());
	copy_obj->set_pressure(f_ptr->get_pressure());
	copy_obj->set_max_pressure(f_ptr->get_max_pressure());
	copy_obj->set_temperature(c_ptr->get_temperature());

	return copy_obj;
}

Fragile_cool_box::Fragile_cool_box(int l, int w, int h, float mass, float temperature, float max_pressure) : Box(l, w, h, mass)
{
	if (max_pressure < 0)
	{
		throw "Fragile_cool_box: Incorrect values specified";
	}
	else
	{
		this->set_temperature(temperature);
		this->set_max_pressure(max_pressure);
		this->set_pressure(0);
	}
	
}
