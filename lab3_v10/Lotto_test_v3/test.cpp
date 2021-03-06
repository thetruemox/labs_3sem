#include "pch.h"
#define NUM_OF_TESTS 100
#define DEFAULT_LINES_NUMBER 3

TEST(constructors, base) 
{
	Lotto_card lotto;

	EXPECT_EQ(DEFAULT_LINES_NUMBER, lotto.get_height());

	int t_num;
	int power = 10;
	while (lotto.get_height() >= power) power *= 10;
	for (int i = 0; i < lotto.get_height(); i++)
	{
		for (int j = 0; j < lotto.get_width(); j++)
		{
			t_num = lotto.get_number(i, j);
			if (t_num != 0)
			{
				EXPECT_TRUE(t_num <= (j+1)*power && t_num >= j*power);
			}
		}
	}

}

TEST(constructors, int_height)
{
	Lotto_card* lotto = nullptr;

	for (int i = 0; i < NUM_OF_TESTS; i++)
	{
		lotto = new Lotto_card(i);
		EXPECT_FALSE(lotto == nullptr);
		EXPECT_EQ(i, lotto->get_height());

		int t_num;
		int power = 10;
		while (lotto->get_height() >= power) power *= 10;
		for (int i = 0; i < lotto->get_height(); i++)
		{
			for (int j = 0; j < lotto->get_width(); j++)
			{
				t_num = lotto->get_number(i, j);
				if (t_num != 0)
				{
					EXPECT_TRUE(t_num <= (j + 1) * power && t_num >= j * power);
				}
			}
		}

		delete lotto;
		lotto = nullptr;
	}
}

TEST(constructors, copy)
{
	Lotto_card* temp = nullptr;;
	Lotto_card* lotto = nullptr;;
	for (int i = 0; i < NUM_OF_TESTS; i++)
	{
		temp = new Lotto_card(i);
		EXPECT_FALSE(temp == nullptr);

		lotto = new Lotto_card(*temp);
		EXPECT_FALSE(lotto == nullptr);

		EXPECT_EQ(temp->get_height(), lotto->get_height());

		for (int i = 0; i < lotto->get_height(); i++)
		{
			for (int j = 0; j < lotto->get_width(); j++)
			{
				EXPECT_EQ(lotto->is_cell_busy(i,j), temp->is_cell_busy(i, j));
			}
		}

		int t_num;
		int power = 10;
		while (lotto->get_height() >= power) power *= 10;
		for (int i = 0; i < lotto->get_height(); i++)
		{
			for (int j = 0; j < lotto->get_width(); j++)
			{
				t_num = lotto->get_number(i, j);
				if (t_num != 0)
				{
					EXPECT_TRUE(t_num <= (j + 1) * power && t_num >= j * power);
				}
			}
		}

		delete temp;
		delete lotto;
		lotto = nullptr;
		temp = nullptr;
	}

}

Lotto_card foo(int size);

TEST(constructors, move)
{
	Lotto_card* lotto = nullptr;

	for (int i = 0; i < NUM_OF_TESTS; i++)
	{
		lotto = new Lotto_card(foo(i));
		EXPECT_FALSE(lotto == nullptr);
		
		int t_num;
		int power = 10;
		while (lotto->get_height() >= power) power *= 10;
		for (int i = 0; i < lotto->get_height(); i++)
		{
			for (int j = 0; j < lotto->get_width(); j++)
			{
				t_num = lotto->get_number(i, j);
				if (t_num != 0)
				{
					EXPECT_TRUE(t_num <= (j + 1) * power && t_num >= j * power);
				}
			}
		}

		delete lotto;
		lotto = nullptr;
	}
}

Lotto_card foo(int size)
{
	Lotto_card temp(size);
	return temp;
}

TEST(methods, zero_nums_remained)
{
	Lotto_card* lotto = new Lotto_card;
	
	int power = 10 * lotto->get_width();
	while (lotto->get_height() >= power) power *= 10;

	for (int i = 0; i < power; i++)
	{
		EXPECT_NO_THROW(lotto->put_keg(i));
	}

	std::vector<int>* array = new std::vector<int>;
	std::vector<int>* temp_nullptr = array;

	lotto->get_remained_numbers(array);

	EXPECT_EQ(temp_nullptr, array);
	delete lotto;
}

TEST(methods, clear_busy_lines)
{
	Lotto_card* lotto = new Lotto_card;
	std::vector<int>* array = new std::vector<int>;
	lotto->get_remained_numbers(array);

	int it = 0;
	int expected_height = lotto->get_height();

	for (int i = 0; i < lotto->get_height(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			lotto->put_keg(array->at(it));
			it++;
		}
		lotto->check_for_busy_lines();

		expected_height--;

		EXPECT_EQ(lotto->get_height(), expected_height);
	}

	delete lotto;
}

TEST(methods, put_keg)
{
	Lotto_card lotto;
	int t_num;

	int it = 0;
	int* num_arr = new int[5 * lotto.get_height()];

	 for (int i = 0; i < lotto.get_height(); i++)
	 {
		 for (int j = 0; j < lotto.get_width(); j++)
		 {
			 t_num = lotto.get_number(i, j);
			 if (t_num != 0)
			 {
				 num_arr[it] = t_num;
				 it++;
			 }
		 }
	 }


	int power = 10 * lotto.get_width();
	while (lotto.get_height() >= power) power *= 10;

	for (int i = 0; i < power; i++)
	{
		EXPECT_NO_THROW(lotto.put_keg(i));
	}


	power = 10;
	while (lotto.get_height() >= power) power *= 10;
	for (int i = 0; i < lotto.get_height(); i++)
	{
		for (int j = 0; j < lotto.get_width(); j++)
		{
			t_num = lotto.get_number(i, j);
			if (t_num != 0)
			{
				EXPECT_TRUE(t_num <= (j + 1) * power && t_num >= j * power);
			}
		}
	}

	it = 0;
	for (int i = 0; i < lotto.get_height(); i++)
	{
		for (int j = 0; j < lotto.get_width(); j++)
		{
			t_num = lotto.get_number(i, j);
			if (t_num != 0)
			{
				EXPECT_EQ(num_arr[it], t_num);
				it++;
			}
		}
	}

	delete[] num_arr;
}