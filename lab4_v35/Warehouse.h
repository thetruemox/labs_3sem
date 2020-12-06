#pragma once
#include <vector>
#include "Box_container.h"
#include "Warehouse_map.h"


class Warehouse
{
public:

	Warehouse(int l, int w, int h);
	~Warehouse();

	const char* place_box_auto(Type type, int length, int width, int height, int mass);
	

private:
	Warehouse();

	Cursor cursor;
	Warehouse_map* map;

	unsigned int length, width, height;
	std::vector<Box_container> box_racks;

	bool rotate_auto(Cursor cursor, Box* box);
		
};

