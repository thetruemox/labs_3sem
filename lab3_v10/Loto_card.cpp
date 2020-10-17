#include "Loto_card.h"

Loto_card::Loto_card()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cells[i][j] = new Cell;
		}	
	}
}

Loto_card::~Loto_card()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			delete cells[i][j];
		}
	}
}

void Loto_card::generate_numbers()
{

}
