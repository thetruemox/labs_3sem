#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
#define NUM_OF_TESTS 100

class LottoTest : public ::testing::Test
{
protected:
    Lotto_card* lotto;
    void SetUp() override 
    {
        lotto = new Lotto_card;
    }
    void TearDown() override 
    {
        delete lotto;
    }
};

TEST(Lotto_card_test, zero_nums_remained) 
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

TEST(Lotto_card_test, clear_busy_lines)
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