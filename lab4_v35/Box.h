#pragma once
#include <string>
#include "Fragile_box.h"
#include "Cool_box.h"
#include "Fragile_cool_box.h"

enum Type
{
	COOL,
	FRAGILE,
	FRAGILE_COOL
};

class Box
{
public:
	
	Box(int l, int w, int h);
	
	//getters
	int get_box_number() const;
	float get_price() const;
	float get_mass() const;
	void get_customer_name(std::string & name) const;
	
	int get_length() const;
	int get_width() const;
	int get_height() const;
	Type get_type() const;
	
	//setters
	void set_all(int length, int width, int height);
	void set_length(int length);
	void set_width(int width);
	void set_height(int height);

	void set_box_number(int num);
	void set_price(float price);
	void set_mass(float mass);
	void set_customer_name(std::string name);

private:
	Box();

protected:

	Type type;
	unsigned int length, width, height;
	unsigned int box_number;
	float price;
	float mass;
	std::string customer_name;
};
