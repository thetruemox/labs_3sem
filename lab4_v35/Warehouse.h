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

	void out_all_boxes(std::ostream& out) const;

	bool put_box(Box *box);
	bool delete_box(int ID);

	int get_size() const;

private:
	Cursor cursor;
	Warehouse_map* map;

	unsigned int length, width, height;
	float temperature;

	std::vector<Box_container*> racks;

	void set_numbers();
	void put_container_push_back(unsigned int x, unsigned int y, unsigned int z, Box* box);
};

//Основание 