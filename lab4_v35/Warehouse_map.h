#pragma once
#include "Cursor.h"

class Warehouse_map
{
public:
	Warehouse_map(int length, int width, int height);
	~Warehouse_map();

	bool is_it_empty_here(Cursor cursor, int length, int width, int height);

private:
	Warehouse_map();

	void place_container(Cursor cursor, int length, int width);

	bool** map;
	int length, width, height;
};
