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

	unsigned int get_length() { return this->length; }
	unsigned int get_width() { return this->width; }
	unsigned int get_height() { return this->height; }
	float get_temperature() { return this->temperature; }

	void out_all_boxes(std::ostream& out) const;

	bool put_box_auto(Box *box);
	bool put_box_manual(Box* box, Cursor cursor);
	bool delete_box(int ID);
	bool move_box(int ID, Cursor cursor);

	int get_size() const;

private:
	Cursor cursor;
	Warehouse_map* map;

	unsigned int length, width, height;
	float temperature;

	std::vector<Box_container*> racks;

	unsigned int it_ID;
	unsigned int generate_ID();
	int who_is_there(Cursor cursor);
	void put_container_push_back(unsigned int x, unsigned int y, unsigned int z, Box* box, Cursor cursor);
};
