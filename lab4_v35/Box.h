#pragma once
#include <string>

class Box
{
public:
	Box();
	Box(int l, int w, int h);

	//getters
	int get_box_number() const;
	float get_price() const;
	float get_mass() const;
	void get_customer_name(std::string & name) const;
	
	int get_length() const;
	int get_width() const;
	int get_height() const;
	
	//setters
	void set_box_number(int num);
	void set_price(float price);
	void set_mass(float mass);
	void set_customer_name(std::string name);

protected:
	int length, width, height;
	unsigned int box_number;
	float price;
	float mass;
	std::string customer_name;
};
