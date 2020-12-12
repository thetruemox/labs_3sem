#include "Box_container.h"

Box_container::Box_container()
{
	Cursor cursor;
	this->placed_cursor = cursor;
	this->base_length = 1;
	this->base_width = 1;
	this->temp_height = 0;
}

Box_container::Box_container(Cursor cursor, Box* box, int max_height)
{
	this->placed_cursor = cursor;
	this->box_rack.push_back(box);

	this->base_length = box->length;
	this->base_width = box->width;

	this->max_height = max_height;
	this->temp_height = box->height;
}

bool Box_container::put_box(Box* box)
{
	if(!check_pressure(box->mass)) return false;
	
	int x = box->length;
	int y = box->width;
	int z = box->height;

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

void Box_container::put_box_push_back(int x, int y, int z, Box* box)
{
	box->set_all(x, y, z);
	this->temp_height += z;

	this->box_rack.push_back(box);
	add_pressure(box->mass);
}

bool Box_container::check_pressure(float mass)
{
	Fragile_box* f_ptr = nullptr;

	for (int i = 0; i < box_rack.size(); i++)
	{
		f_ptr = dynamic_cast<Fragile_box*>(box_rack[i]);
		if (f_ptr != nullptr)
		{
			if ((f_ptr->pressure + mass) > f_ptr->max_pressure) return false;
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
			f_ptr->pressure += mass;
		}
		f_ptr = nullptr;
	}

}



int Box_container::size()
{
	return this->box_rack.size();
}


