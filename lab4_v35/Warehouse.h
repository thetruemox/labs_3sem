#pragma once
#include <vector>
#include "Box_container.h"
#include "Warehouse_map.h"


class Warehouse
{
public:
	void map_out(); //Для отладки 

	Warehouse();
	Warehouse(int l, int w, int h, float temperature);
	~Warehouse();

	bool put_box(Box *box);
	int get_size();
	int get_all_boxes(Box *box);

private:
	Cursor cursor;
	Warehouse_map* map;

	unsigned int length, width, height;
	float temperature;


	std::vector<Box_container*> racks;
};

//Основание 