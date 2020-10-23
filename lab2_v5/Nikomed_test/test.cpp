#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
#define NUM_OF_TESTS 100

    class NikomedTest : public ::testing::Test
    {
    protected:
        Nikomed* nik;
        void SetUp() override {
            nik = new Nikomed;
        }
        void TearDown() override {
            delete nik;
        }
    };
    

    TEST_F(NikomedTest, base_constr)
    {
        EXPECT_DOUBLE_EQ(0, nik->get_a());
        EXPECT_DOUBLE_EQ(1, nik->get_l());
    }
    
    TEST_F(NikomedTest, custom_constr)
    {
        for (int i = 1; i < NUM_OF_TESTS; i++)
        {
            Nikomed nik(i, i);

            EXPECT_DOUBLE_EQ(i, nik.get_a());
            EXPECT_DOUBLE_EQ(i, nik.get_l());
        }        
    }
    
    TEST_F(NikomedTest, set_a_l)
    {
        for (int i = -NUM_OF_TESTS/2; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i);
            EXPECT_DOUBLE_EQ(i, nik->get_a());
        }
       
        for (int i = 1; i < NUM_OF_TESTS; i++)
        {
            nik->set_l(i);
            EXPECT_DOUBLE_EQ(i, nik->get_l());
        }
       
    }

    TEST_F(NikomedTest, set_wrong_l)
    {
        for (int i = -NUM_OF_TESTS; i < 0; i++)
        {
            EXPECT_THROW(nik->set_l(i), char*);
        }
        
    }

    TEST_F(NikomedTest, descartes_a_more_l)
    {
        float res;

        for (int i = 1; i < NUM_OF_TESTS/2; i++)
        {
            nik->set_a(i + NUM_OF_TESTS / 2);
            nik->set_l(i);
            EXPECT_EQ(0, nik->get_descartes_y(i + NUM_OF_TESTS/2, res));
            EXPECT_EQ(-1, nik->get_descartes_y(i, res));
        }
        
    }

    TEST_F(NikomedTest, descartes_a_equal_l)
    {
        float res;

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i);
            nik->set_l(i);
            EXPECT_EQ(0, nik->get_descartes_y(i, res));
            EXPECT_EQ(-1, nik->get_descartes_y(i + NUM_OF_TESTS / 2, res));
        }
    }

    TEST_F(NikomedTest, descartes_a_less_l)
    {
        float res;

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i);
            nik->set_l(i + NUM_OF_TESTS / 2);
            EXPECT_EQ(0, nik->get_descartes_y(i, res));
            EXPECT_EQ(-1, nik->get_descartes_y(i + NUM_OF_TESTS, res));
        }
    }

    TEST_F(NikomedTest, polar)
    {
        float res;

        for (int i = 1; i < NUM_OF_TESTS; i++)
        {
            nik->set_a(i);
            nik->set_l(i);
            
            EXPECT_EQ(0, nik->get_polar_r(20, res));
            EXPECT_EQ(-1, nik->get_polar_r(90, res));
        }
        
    }
    
    TEST_F(NikomedTest, curve)
    {
        float* arr_res = new float[3];

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i);
            nik->set_l(i + NUM_OF_TESTS / 2);

            EXPECT_EQ(0, nik->get_curve_r(nullptr, 3));
            EXPECT_EQ(3, nik->get_curve_r(arr_res, 3));
        }

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i + NUM_OF_TESTS / 2);
            nik->set_l(i);

            EXPECT_EQ(0, nik->get_curve_r(nullptr, 3));
            EXPECT_EQ(2, nik->get_curve_r(arr_res, 3));
        }
        delete[] arr_res;
    }
    
    TEST_F(NikomedTest, circle)
    {
        float res;

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i);
            nik->set_l(i + NUM_OF_TESTS / 2);  
            EXPECT_EQ(0, nik->get_circle_area(res));
        }

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i + NUM_OF_TESTS / 2);
            nik->set_l(i);
            EXPECT_EQ(-1, nik->get_circle_area(res));
        }
    }

    TEST_F(NikomedTest, inflection)
    {
        float* arr_res = new float[3];

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i);
            nik->set_l(i + NUM_OF_TESTS / 2);
            EXPECT_EQ(3, nik->get_inflection_x(arr_res, 3));
        }

        for (int i = 1; i < NUM_OF_TESTS / 2; i++)
        {
            nik->set_a(i + NUM_OF_TESTS / 2);
            nik->set_l(i);
            EXPECT_EQ(1, nik->get_inflection_x(arr_res, 3));
        }

        delete[] arr_res;
    }
    

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}