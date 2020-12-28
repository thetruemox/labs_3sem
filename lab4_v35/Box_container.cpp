#include "Box_container.h"

#define BASE_SIZE 1
Box_container::Box_container()
{
	Cursor cursor;
	this->placed_cursor = cursor;
	this->base_length = BASE_SIZE;
	this->base_width = BASE_SIZE;
	this->max_height = BASE_SIZE;
	this->temp_height = 0;
}

Box_container::Box_container(Cursor cursor, Box* box, unsigned  int max_height)
{
	this->placed_cursor = cursor;
	this->box_rack.push_back(box);

	this->base_length = box->get_length();
	this->base_width = box->get_width();

	this->max_height = max_height;
	this->temp_height = box->get_height();
}

Box_container::~Box_container()
{
	for (int i = 0; i < box_rack.size(); i++)
	{
		delete box_rack[i];
	}
}

bool Box_container::put_box_auto(Box* box)
{
	if(!check_pressure(box->get_mass())) return false;
	
	unsigned int x = box->get_length();
	unsigned int y = box->get_width();
	unsigned int z = box->get_height();

	if (x <= this->base_length && y <= this->base_width && (z + this->temp_height) <= max_height) // XY
	{
		put_box_push_back(x, y, z, box);
		return true;
	} 
	else if (y <= this->base_length && x <= this->base_width && (z + this->temp_height) <= max_height) // YX
	{
		put_box_push_back(y, x, z, box);
		return true;
	}

	if (dynamic_cast<Cool_box*>(box) == nullptr) return false;

	if (y <= this->base_length && z <= this->base_width && (x + this->temp_height) <= max_height) // YZ
	{
		put_box_push_back(y, z, x, box);
		return true;
	}
	else if (z <= this->base_length && y <= this->base_width && (x + this->temp_height) <= max_height) // ZY
	{
		put_box_push_back(z, y, x, box);
		return true;
	}

	if (x <= this->base_length && z <= this->base_width && (y + this->temp_height) <= max_height) // XZ
	{
		put_box_push_back(x, z, y, box);
		return true;
	}
	else if (z <= this->base_length && x <= this->base_width && (y + this->temp_height) <= max_height) // ZX
	{
		put_box_push_back(z, x, y, box);
		return true;
	}

	return false;
}

void Box_container::delete_box(int index)
{
	Fragile_box* fb_ptr = nullptr;
	for (int i = 0; i < index; i++)
	{
		fb_ptr = dynamic_cast<Fragile_box*>(this->box_rack[i]);
		if (fb_ptr != nullptr)
		{
			fb_ptr->set_pressure(fb_ptr->get_pressure() - this->box_rack[index]->get_mass());
		}
	}
	this->temp_height -= this->box_rack[index]->get_height();
	delete this->box_rack[index];
	this->box_rack.erase(this->box_rack.begin() + index);
}

void Box_container::put_box_push_back(unsigned int x, unsigned int y, unsigned int z, Box* box)
{
	box->set_all(x, y, z);
	this->temp_height += z;

	this->box_rack.push_back(box);
	add_pressure(box->get_mass());
}

bool Box_container::check_pressure(float mass) const
{
	Fragile_box* f_ptr = nullptr;

	for (int i = 0; i < box_rack.size(); i++)
	{
		f_ptr = dynamic_cast<Fragile_box*>(box_rack[i]);
		if (f_ptr != nullptr)
		{
			if ((f_ptr->get_pressure() + mass) > f_ptr->get_max_pressure()) return false;
		}
		f_ptr = nullptr;
	}

	return true;
}

void Box_container::add_pressure(float mass)
{
	Fragile_box* f_ptr = nullptr;

	for (int i = 0; i < box_rack.size() - 1; i++)
	{
		f_ptr = dynamic_cast<Fragile_box*>(box_rack[i]);
		if (f_ptr != nullptr)
		{
			f_ptr->set_pressure(f_ptr->get_pressure() + mass);
		}
		f_ptr = nullptr;
	}
}

unsigned int Box_container::size()
{
	return this->box_rack.size();
}


