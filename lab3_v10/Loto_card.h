#pragma once
#include "Cell.h"
#define HEIGHT 3

class Lotto_card
{
public:
	Lotto_card();
	~Lotto_card();
	Cell* cells[HEIGHT][9];

	void generate_numbers();
	void card_output(); //доделать красивый вывод (пока что красиво для height < 10)
	void put_keg(int keg);

private:
	static const int height = HEIGHT;
	static const int width = 9;

	bool check_nums(int num, int* arr, int size);
	int generate_r_num(int h_i, int w_j, int* uq_nums_arr, int &it_nums);
	

};


