#include "Box_container.h"

Box_container::Box_container()
{
	Cursor cursor;
	this->placed_cursor = cursor;
	this->base_length = 1;
	this->base_width = 1;
	this->temp_height = 0;
}

Box_container::Box_container(Cursor cursor, Box* box)
{
	this->placed_cursor = cursor;

	this->box_rack.push_back(box);

	this->base_length = box->length;
	this->base_width = box->width;
	this->temp_height = box->height;
}

bool Box_container::put_box(Box* box)
{
	/* TODO: 
		Проверка на давление сверху
		Температура не учитывается
		Максимальная высота не учитывается
	*/
	
	int x = box->length;
	int y = box->width;
	int z = box->height;

	if (x <= this->base_length && y <= this->base_width) // XY
	{
		box->set_all(x, y, z);
		this->box_rack.push_back(box);
		return true;
	} 
	else if (y <= this->base_length && x <= this->base_width) // YX
	{
		box->set_all(y, x, z);
		this->box_rack.push_back(box);
		return true;
	}

	if (dynamic_cast<Cool_box*>(box) == nullptr) return false;

	if (y <= this->base_length && z <= this->base_width) // YZ
	{
		box->set_all(y, z, x);
		this->box_rack.push_back(box);
		return true;
	}
	else if (z <= this->base_length && y <= this->base_width) // ZY
	{
		box->set_all(z, y, x);
		this->box_rack.push_back(box);
		return true;
	}

	if (x <= this->base_length && z <= this->base_width) // XZ
	{
		box->set_all(x, z, y);
		this->box_rack.push_back(box);
		return true;
	}
	else if (z <= this->base_length && x <= this->base_width) // ZX
	{
		box->set_all(z, x, y);
		this->box_rack.push_back(box);
		return true;
	}

	return false;
}

int Box_container::size()
{
	return this->box_rack.size();
}


