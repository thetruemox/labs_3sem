#pragma once
#include <string>

class Box
{
public:

	Box(); 
	Box(int l, int w, int h, float mass);
	Box(const Box& box);

	virtual ~Box() {}

	unsigned int get_ID();

	friend class Box_container;
	friend class Warehouse;

private:
	bool set_all(int length, int width, int height);

	unsigned int length, width, height;
	unsigned int ID;
	float mass;

	/*
	float price;
	unsigned int box_number;
	std::string customer_name;
	*/
};
