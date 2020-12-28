#include "Warehouse_map.h"

Warehouse_map::Warehouse_map()
{
	this->length = BASE_SIZE;
	this->width = BASE_SIZE;
	this->height = BASE_SIZE;

	map = new bool* [this->length];
	for (int i = 0; i < this->length; i++)
	{
		map[i] = new bool[this->width];
	}

	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			map[i][j] = true;
		}
	}
}

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

void Warehouse_map::clear_place(Cursor cursor, int length, int width)
{
	for (int i = cursor.x_length; i < cursor.x_length + length; i++)
	{
		for (int j = cursor.y_width; j < cursor.y_width + width; j++)
		{
			map[i][j] = true;
		}
	}
}

void Warehouse_map::map_out()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j])
			{
				std::cout << "_" << " ";
			} else
			std::cout << "0" << " ";
		}
		std::cout << std::endl;
	}
}

int Warehouse_map::free_cells()
{
	int num = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (this->map[i][j] == true)
			{
				num++;
			}
		}
	}
	return num;
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


