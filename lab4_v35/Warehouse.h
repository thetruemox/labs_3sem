#pragma once
#include <vector>
#include "Box_container.h"
#include "Warehouse_map.h"

/**
 * @brief Place where racks with boxes are stored
 */
class Warehouse
{
public:
	/// <summary>
	/// Base constructor. Initializes to base values
	/// </summary>
	Warehouse();
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="l">Warehouse length</param>
	/// <param name="w">Warehouse width</param>
	/// <param name="h">Warehouse height</param>
	/// <param name="temperature">Warehouse temperature</param>
	Warehouse(int l, int w, int h, float temperature);
	~Warehouse();

	/// <summary>
	/// Returns warehouse length
	/// </summary>
	/// <returns>Warehouse length</returns>
	unsigned int get_length() { return this->length; }
	/// <summary>
	/// Returns warehouse width
	/// </summary>
	/// <returns>Warehouse width</returns>
	unsigned int get_width() { return this->width; }
	/// <summary>
	/// Returns warehouse height
	/// </summary>
	/// <returns>Warehouse height</returns>
	unsigned int get_height() { return this->height; }
	/// <summary>
	/// Returns warehouse temperature
	/// </summary>
	/// <returns>Warehouse temperature</returns>
	float get_temperature() { return this->temperature; }

	/// <summary>
	/// Displays a description of all boxes in the warehouse
	/// </summary>
	/// <param name="out">Out stream</param>
	void out_all_boxes(std::ostream& out) const;
	/// <summary>
	/// Places a box in the warehouse, automatically finding free space
	/// </summary>
	/// <param name="box">Pointer on the box</param>
	/// <returns>ID of placed box or -1 if box wasnt placed</returns>
	int put_box_auto(Box *box);
	/// <summary>
	/// Places a box in the warehouse at the specified coordinates
	/// </summary>
	/// <param name="box">Pointer on the box</param>
	/// <param name="cursor">Specified coordinates</param>
	/// <returns>True if it was successfully placed and false if not</returns>
	bool put_box_manual(Box* box, Cursor cursor);
	/// <summary>
	/// Removes a box from the warehouse
	/// </summary>
	/// <param name="ID">ID of the box</param>
	/// <returns>True if it was successfully deleted and false if not</returns>
	bool delete_box(int ID);
	/// <summary>
	/// Moves the box to the specified coordinates
	/// </summary>
	/// <param name="ID">ID of the box</param>
	/// <param name="cursor">Specified coordinates</param>
	/// <returns>True if it was successfully moveed and false if not</returns>
	bool move_box(int ID, Cursor cursor);
	/// <summary>
	/// Returns number of boxes placed in warehouse
	/// </summary>
	/// <returns>Number of boxes placed in warehouse</returns>
	int get_size() const;
	/// <summary>
	/// Displays a map
	/// </summary>
	void map_out() const;
	/// <summary>
	/// Return number of free cells on map
	/// </summary>
	/// <returns>Number of free cells on map</returns>
	int free_cells() const;
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
