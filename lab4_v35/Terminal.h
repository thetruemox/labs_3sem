#pragma once
#include "Warehouse.h"

class Terminal
{
public:
	//Terminal();
	~Terminal();

	void add_warehouse();
	void put_box();
	void delete_box();
	void move_box();
	void out_boxes();
	void out_warehouses();
	void map_out();

private:
	int wh_size(int index);

	int get_int_pos();
	int get_int_pos_wzero();
	int get_int_any();
	float get_float_any();
	float get_float_pos();

	std::vector<Warehouse*> warehouses;
};

