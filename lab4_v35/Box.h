#pragma once
#include <string>

class Box
{
public:

	Box(); 
	Box(int l, int w, int h, float mass);
	Box(const Box& box);

	virtual ~Box() {}

	bool set_all(int length, int width, int height);

	friend class Box_container;
	friend class Warehouse;

private:

	unsigned int length, width, height;
	float mass;

	/*
	float price;
	unsigned int box_number;
	std::string customer_name;
	*/

};
