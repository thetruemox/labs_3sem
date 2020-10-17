#pragma once
#include "Cell.h"
#define WIDTH 9
#define HEIGHT 3

class Loto_card
{
public:
	Loto_card();
	~Loto_card();

	Cell* cells[HEIGHT][WIDTH];
private:
	const int height = HEIGHT;
	const int width = WIDTH;

	void generate_numbers();

};


