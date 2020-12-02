#include "Warehouse_map.h"

Warehouse_map::Warehouse_map(int length, int width, int height)
{
	this->length = length;
	this->width = width;
	this->height = height;

	map = new bool* [length];
	for (int i = 0; i < length; i++)
	{
		map[i] = new bool[width];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[i][j] = true;
		}
	}

}

Warehouse_map::~Warehouse_map()
{
	for (int i = 0; i < length; i++)
	{
		delete map[i];
	}
	delete map;
}

bool Warehouse_map::is_it_empty_here(Cursor cursor, int length, int width, int height)
{
	if (((cursor.x_length + length) > this->length) || ((cursor.y_width + width) > this->width) || (height > this->height))
	{
		return false;
	}

	for (int i = cursor.x_length; i < cursor.x_length + length; i++)
	{
		for (int j = cursor.y_width; j < cursor.y_width + width; j++)
		{
			if (!map[i][j])
			{
				return false;
			}
		}
	}

	place_container(cursor, length, width);
	return true;
}

void Warehouse_map::place_container(Cursor cursor, int length, int width)
{
	for (int i = cursor.x_length; i < cursor.x_length + length; i++)
	{
		for (int j = cursor.y_width; j < cursor.y_width + width; j++)
		{
			map[i][j] = false;
		}
	}
}


