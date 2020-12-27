#pragma once
#include <string>

/**
 * @brief Main type of boxes
 */
class Box
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Box(); 
	/// <summary>
	/// Constructor that initializes all box parameters
	/// </summary>
	/// <param name="l">Box length</param>
	/// <param name="w">Box width</param>
	/// <param name="h">Box height</param>
	/// <param name="mass">Box mass</param>
	Box(int l, int w, int h, float mass);
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="box">Copy box</param>
	Box(const Box& box);

	virtual ~Box() {}

	/// <summary>
	/// Return box ID in the warehouse
	/// </summary>
	/// <returns>Box ID in the warehouse</returns>
	unsigned int get_ID();
	
	/// <summary>
	/// Set box`s length, width and height 
	/// </summary>
	/// <param name="length">Box length</param>
	/// <param name="width">Box width</param>
	/// <param name="height">Box height</param>
	/// <returns>True if parameters are set and false if not</returns>
	bool set_all(int length, int width, int height);
	/// <summary>
	/// Set box`s ID
	/// </summary>
	/// <param name="ID">Box ID</param>
	void set_ID(int ID) { this->ID = ID; }

	/// <summary>
	/// Return box length
	/// </summary>
	/// <returns>Return box length</returns>
	unsigned int get_length() { return this->length; }
	/// <summary>
	/// Return box width
	/// </summary>
	/// <returns>Box width</returns>
	unsigned int get_width() { return this->width; }
	/// <summary>
	/// Return box height
	/// </summary>
	/// <returns>Box height</returns>
	unsigned int get_height() { return this->height; }
	/// <summary>
	/// Return box mass
	/// </summary>
	/// <returns>Box mass</returns>
	float get_mass() { return this->mass; }

private:
	unsigned int length, width, height;
	unsigned int ID;
	float mass;
};
