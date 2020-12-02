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
*/

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
	//Если на складе нет стеллажей, создаю новый по курсору (0,0)
	if (box_racks.empty())
	{
		Cursor cursor;
		if (map->is_it_empty_here(cursor, length, width, height)) //Прогнать разные повороты коробки
		{
			box_racks.push_back(Box_container(cursor, length, width));
		}

	}

	return nullptr;
}


