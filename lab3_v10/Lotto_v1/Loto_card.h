#pragma once
#include "Cell.h"
#include <vector>
#define HEIGHT 3

class Lotto_card
{
public:
	Lotto_card();

	Cell* cells[HEIGHT][9];

	int get_width() const;
	int get_height() const;

	void card_output() const; //пока что красивый вывод только при height < 10
	void put_keg(int keg);
	int how_many_busy() const;
	bool is_cell_busy(int i, int j) const;
	void check_for_busy_lines();
	std::vector<int>* get_remained_numbers() const;

private:
	int height;
	const int width = 9;
	void generate_numbers();
	bool check_unique_nums(int num, int* arr, int size) const;
	int generate_rand_num(int h_i, int w_j, int* uq_nums_arr, int &it_nums);
	void delete_busy_line(int height_i); 
};


