#pragma once
#include "Cursor.h"
#include <memory>
#include <vector>

#include "Box.h"
#include "Cool_box.h"
#include "Fragile_box.h"
#include "Fragile_cool_box.h"


class Box_container 
{
public:
	
	Box_container();
	Box_container(Cursor cursor, Box* box);
	
	int size();
	bool put_box(Box* box);

private:
	Cursor placed_cursor;

	int base_length;
	int base_width;
	int temp_height;

	std::vector<Box*> box_rack;
};


