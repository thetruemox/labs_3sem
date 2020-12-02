#pragma once
#include "Box.h"
#include "Cursor.h"
#include <memory>
#include <vector>


class Box_container
{
public:
	//float get_temperature() const;
	//float get_pressure() const;

	Box_container(Cursor cursor, int length, int width);

private:

	Cursor placed_cursor;

	int length;
	int width;
	int temp_height;

	std::vector<std::shared_ptr<Box>> box_stacks;
};


