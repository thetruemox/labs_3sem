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
	Box_container(const Box_container& container);
	Box_container(Cursor cursor, Box* box, unsigned int max_height);
	
	~Box_container();

	unsigned int size();
	
	bool put_box_auto(Box* box);
	void delete_box(int index);

	friend class Warehouse;
private:
	//Либо перегрузи конструкторы и операторы присваивания либо закрой
	//Для warehouse тоже

	Cursor placed_cursor;

	unsigned int base_length, base_width, temp_height, max_height;

	std::vector<Box*> box_rack;

	bool check_pressure(float mass) const;
	void add_pressure(float mass);

	void put_box_push_back(unsigned int x, unsigned int y, unsigned int z, Box* box);
};


