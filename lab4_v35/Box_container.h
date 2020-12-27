#pragma once
#include "Cursor.h"
#include <memory>
#include <vector>

#include "Box.h"
#include "Cool_box.h"
#include "Fragile_box.h"
#include "Fragile_cool_box.h"

/**
 * @brief A group of boxes combined into a rack, where they are stacked on top of each other
 */
class Box_container 
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Box_container();
	/// <summary>
	/// Constructor that initializes all rack parameters
	/// </summary>
	/// <param name="cursor">Rack reference point</param>
	/// <param name="box">First box in rack</param>
	/// <param name="max_height">Max height of rack</param>
	Box_container(Cursor cursor, Box* box, unsigned int max_height);
	

	//Box_container(const Box_container& container);
	~Box_container();

	/// <summary>
	/// Return number of boxes in the rack
	/// </summary>
	/// <returns>Number of boxes in the rack</returns>
	unsigned int size();
	
	/// <summary>
	/// Places the box in the rack
	/// </summary>
	/// <param name="box">Pointer to the box</param>
	/// <returns>True if there is a place, and false if not</returns>
	bool put_box_auto(Box* box);
	/// <summary>
	/// Removes a box from the rack
	/// </summary>
	/// <param name="index">Removable box index</param>
	void delete_box(int index);

	friend class Warehouse;
private:
	Cursor placed_cursor;

	unsigned int base_length, base_width, temp_height, max_height;

	std::vector<Box*> box_rack;

	bool check_pressure(float mass) const;
	void add_pressure(float mass);

	void put_box_push_back(unsigned int x, unsigned int y, unsigned int z, Box* box);
};


