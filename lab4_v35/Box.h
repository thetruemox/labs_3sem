#pragma once
#include <string>

/**
 * @brief Main type of boxes
 */
class Box
{
public:

	Box(); 
	Box(int l, int w, int h, float mass);
	Box(const Box& box);

	virtual ~Box() {}

	///Return box ID in the warehouse
	unsigned int get_ID();

	bool set_all(int length, int width, int height);
	void set_ID(int ID) { this->ID = ID; }

	unsigned int get_length() { return this->length; }
	unsigned int get_width() { return this->width; }
	unsigned int get_height() { return this->height; }
	float get_mass() { return this->mass; }

private:
	unsigned int length, width, height;
	unsigned int ID;
	float mass;
};
