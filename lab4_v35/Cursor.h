#pragma once

class Cursor
{
public:
	Cursor();
	Cursor(unsigned int x, unsigned int y);


	Cursor& operator= (const Cursor& obj);
	unsigned int x_length;
	unsigned int y_width;
};

