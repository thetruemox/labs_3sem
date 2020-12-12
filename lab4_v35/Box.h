#pragma once
#include <string>

class Box
{
public:

	Box(); 
	Box(int l, int w, int h, float mass);
	virtual ~Box() {}

	void set_all(int length, int width, int height);

	unsigned int length, width, height;
	float mass;

	/*
	float price;
	unsigned int box_number;
	std::string customer_name;
	*/

};
