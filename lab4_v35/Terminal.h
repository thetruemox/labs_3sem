#pragma once
#include "Warehouse.h"

/**
 * @brief User interface that allows you to interact with warehouses
 */
class Terminal
{
public:
	//Terminal();
	~Terminal();

	/// <summary>
	/// Add warehouse
	/// </summary>
	void add_warehouse();
	/// <summary>
	/// Delete warehouse
	/// </summary>
	void delete_warehouse();
	/// <summary>
	/// Put box in warehouse
	/// </summary>
	void put_box();
	/// <summary>
	/// Delete box from warehouse
	/// </summary>
	void delete_box();
	/// <summary>
	/// Move box in warehouse
	/// </summary>
	void move_box();
	/// <summary>
	/// Display information about all boxes in the warehouse
	/// </summary>
	void out_boxes();
	/// <summary>
	/// Display information about all warehouses
	/// </summary>
	void out_warehouses();
	/// <summary>
	/// Display map of warehouse
	/// </summary>
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

