#pragma once
#include <vector>
#include "Box_container.h"
#include "Warehouse_map.h"


class Warehouse
{
public:
	Warehouse();
	Warehouse(int l, int w, int h, float temperature);
	~Warehouse();

	bool put_box(Box *box);
	void map_out();
		
	
private:
	Cursor cursor;
	Warehouse_map* map;

	unsigned int length, width, height;
	float temperature;


	std::vector<Box_container*> racks;
};

