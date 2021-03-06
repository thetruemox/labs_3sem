#pragma once
#include "Cursor.h"

#include <iostream>
#define BASE_SIZE 1
/**
 * @brief Map showing free and occupied places in the warehouse
 */
class Warehouse_map
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Warehouse_map();
	/// <summary>
	/// Map constructor. Initializes its dimensions
	/// </summary>
	/// <param name="length">Map length</param>
	/// <param name="width">Map width</param>
	/// <param name="height">Map height</param>
	Warehouse_map(int length, int width, int height);
	~Warehouse_map();

	/// <summary>
	/// Checks if the box with the given coordinates will fit in the warehouse
	/// </summary>
	/// <param name="cursor">Box start point</param>
	/// <param name="length">Box length</param>
	/// <param name="width">Box width</param>
	/// <param name="height">Box height</param>
	/// <returns>True if there is a place, false if not. If there is space, place the rack on the map</returns>
	bool is_it_empty_here(Cursor cursor, int length, int width, int height);
	/// <summary>
	/// Clears space on the map
	/// </summary>
	/// <param name="cursor">Cleaning reference point</param>
	/// <param name="length">Cleaning length</param>
	/// <param name="width">Cleaning width</param>
	void clear_place(Cursor cursor, int length, int width);
	/// <summary>
	/// Displays a map
	/// </summary>
	void map_out();
	/// <summary>
	/// Return number of free cells
	/// </summary>
	/// <returns>Number of free cells</returns>
	int free_cells();
	/// <summary>
	/// Returns warehouse map length
	/// </summary>
	/// <returns>Warehouse map length</returns>
	unsigned int get_length() { return this->length; }
	/// <summary>
	/// Returns warehouse map width
	/// </summary>
	/// <returns>Warehouse map width</returns>
	unsigned int get_width() { return this->width; }
	/// <summary>
	/// Returns warehouse map height
	/// </summary>
	/// <returns>Warehouse map height</returns>
	unsigned int get_height() { return this->height; }

private:
	void place_container(Cursor cursor, int length, int width);

	bool** map;
	int length, width, height;
};

