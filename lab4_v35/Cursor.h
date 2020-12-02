#pragma once

class Cursor
{
public:
	Cursor();
	Cursor(int x, int y);


	Cursor& operator= (const Cursor& obj);
	int x_length;
	int y_width;
};

