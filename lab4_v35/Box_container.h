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
	void put_box_in_stack(Box& box);

private:

	Box_container();

	Cursor placed_cursor;

	int length;
	int width;
	int temp_height;

	std::vector<Box> box_stacks;
};


