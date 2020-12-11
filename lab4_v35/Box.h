#pragma once
#include <string>

class Box
{
public:

	Box(); 
	Box(int l, int w, int h);
	virtual ~Box() {}

	void set_all(int length, int width, int height);

	unsigned int length, width, height;
	unsigned int box_number;
	float price;
	float mass;
	std::string customer_name;
	

};
