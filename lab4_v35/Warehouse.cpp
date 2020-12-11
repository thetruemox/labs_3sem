#include "Warehouse.h"

/*
* #define BASE_SIZE 10
Warehouse::Warehouse()
{
	this->cursor.x_length = 0;
	this->cursor.y_width = 0;

	this->length = BASE_SIZE;
	this->width = BASE_SIZE;
	this->height = BASE_SIZE;
}


Warehouse::Warehouse(int l, int w, int h)
{
	map = new Warehouse_map(l, w, h);

	this->cursor.x_length = 0;
	this->cursor.y_width = 0;

	if (l > 0)
	{
		this->length = l;
	}
	else this->length = 10;

	if (w > 0)
	{
		this->width = w;
	}
	else this->width = 10;

	if (h > 0)
	{
		this->height = h;
	}
	else this->height = 10;
}

Warehouse::~Warehouse()
{
	delete map;
}

const char* Warehouse::place_box_auto(Type type, int length, int width, int height, int mass)
{
	Box* box;

	switch (type)
	{
	case COOL:
		box = new Cool_box(length, width, height, 0); //сделай с температурой что-то
		break;
	case FRAGILE:
		box = new Fragile_box(length, width, height, 0); //сделай с давлением что-то
		break;
	case FRAGILE_COOL:
		box = new Fragile_cool_box(length, width, height, 0, 0); //сделай с температурой давлением что-то
		break;
	default:
		break;
	}
	
	//Если на складе нет стеллажей, создаю новый по курсору (0,0)
	if (box_racks.empty())
	{
		Cursor cursor;

		if (rotate_auto(cursor, box))
		{
			//место найдено, добавляем стеллаж
			this->box_racks.push_back(Box_container(cursor, box->get_length(), box->get_width()));


		}
		else return "There is no place for this box";

		

	}

	return nullptr;
}

bool Warehouse::rotate_auto(Cursor cursor, Box* box)
{
	Type type = box->get_type();

	int x, y, z;
	x = box->get_length();
	y = box->get_width();
	z = box->get_height();

	if (map->is_it_empty_here(cursor, x, y, z)) // lw
	{
		box->set_all(x, y, z);
		return true;
	}
	if (map->is_it_empty_here(cursor, y, x, z)) // wl
	{
		box->set_all(y, x, z);
		return true;
	}

	if (type != COOL) return false;

	if (map->is_it_empty_here(cursor, z, x, y)) // hl
	{
		box->set_all(z, x, y);
		return true;
	}
	if (map->is_it_empty_here(cursor, x, z, y)) // lh
	{
		box->set_all(x, z, y);
		return true;
	}

	if (map->is_it_empty_here(cursor, y, z, x)) // wh
	{
		box->set_all(y, z, x);
		return true;
	}
	if (map->is_it_empty_here(cursor, z, y, x)) // hw
	{
		box->set_all(z, y, x);
		return true;
	}

	return false;
}

*/
