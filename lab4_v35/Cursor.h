#pragma once

/**
 * @brief A helper class that acts as a pointer to a warehouse map
 */
class Cursor
{
public:
	/// <summary>
	/// Base constructor
	/// </summary>
	Cursor();
	/// <summary>
	/// Constructor that initializes all cursor parameters
	/// </summary>
	/// <param name="x">Cursor x</param>
	/// <param name="y">Cursor y</param>
	Cursor(unsigned int x, unsigned int y);


	Cursor& operator= (const Cursor& obj);
	unsigned int x_length;
	unsigned int y_width;
};

