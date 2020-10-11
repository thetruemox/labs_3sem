#include "pch.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cmath>
//#include "../Nikomed.h"

class Nikomed
{
public:
    Nikomed();
    Nikomed(float a, float l);
    //a - offset, 2l - length between two points of nikomed

    const float get_a();
    const float get_l();

    void set_a(float a);
    void set_l(float l);

    const int get_descartes_y(float x, float& res);
    const int get_polar_r(float angle, float& res);
    const int get_curve_r(float* arr_res);
    const int get_circle_area(float& res);
    const int get_inflection_x(float* arr_res);

private:
    float a, l;

};
Nikomed::Nikomed()
{
    set_a(0);
    set_l(1);
    std::cout << "l and a are set default (l = 1, a = 0)" << std::endl;
}
Nikomed::Nikomed(float a, float l)
{
    set_a(a);
    set_l(l);
}
const float Nikomed::get_a()
{
    return this->a;
}
void Nikomed::set_a(float a)
{
    this->a = a;
}
const float Nikomed::get_l()
{
    return this->l;
}
void Nikomed::set_l(float l)
{
    if (l > 0)
    {
        this->l = l;
    }
    else throw "l can`t be negative or zero";
}
const int Nikomed::get_descartes_y(float x, float& res)
{

    float acos_arg = (x - a) / l;
    float angle;

    if (acos_arg > 1 || acos_arg < -1)
    {
        return -1;
    }
    else
    {
        angle = acos(acos_arg);
        float y = a * tan(angle) + l * sin(angle);
        res = y;
        return 0;
    }
}
const int Nikomed::get_polar_r(float angle, float& res)
{
    if (cos(angle) == 0)
    {
        return -1;
    }
    else
    {
        res = a / cos(angle) + l;
        if (res < 0)
        {
            return -1;
        }
        return 0;
    }
}
const int Nikomed::get_curve_r(float* arr_res)
{
    if (arr_res == nullptr) return 0;

    arr_res[0] = pow((l + a), 2) / l;
    arr_res[1] = pow((l - a), 2) / l;

    if (l >= a && a != 0)
    {
        arr_res[2] = (l * sqrt(pow(l, 2) - pow(a, 2))) / (2 * a);
        return 3;
    }
    else return 2;
}
const int Nikomed::get_circle_area(float& res)
{
    if (l <= 0) return -1;
    if ((l <= a) || a == 0) return -1;

    float sqrt_arg = pow(l, 2) - pow(a, 2);
    float ln_arg = (l + sqrt(sqrt_arg)) / a;
    float acos_arg = a / l;

    res = a * sqrt(sqrt_arg) - 2 * a * l * log(ln_arg) + pow(l, 2) * acos(acos_arg);

    return 0;
}
const int Nikomed::get_inflection_x(float* arr_res)
{
    if (l <= 0 || arr_res == nullptr) return 0;

    if (a > l)
    {
        arr_res[0] = 2.35 * a;
        return 1;
    }
    else if (l == a)
    {
        arr_res[0] = a * sqrt(3);
        arr_res[1] = 0;
        arr_res[2] = -a * sqrt(3);
        return 3;
    }
    else if (a < l)
    {
        arr_res[0] = 1.38 * a;
        arr_res[1] = 0.57 * a;
        arr_res[2] = -1.9 * a;
        return 3;
    }
}


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
        nik = new Nikomed(2, 3);

        EXPECT_DOUBLE_EQ(2, nik->get_a());
        EXPECT_DOUBLE_EQ(3, nik->get_l());
    }
    
    TEST_F(NikomedTest, set_a_l)
    {
        nik->set_a(-23);
        EXPECT_DOUBLE_EQ(-23, nik->get_a());

        nik->set_l(20);
        EXPECT_DOUBLE_EQ(20, nik->get_l());
    }

    TEST_F(NikomedTest, set_wrong_l)
    {
        EXPECT_ANY_THROW(nik->set_l(-20));
    }

    TEST_F(NikomedTest, descartes_a_more_l)
    {
        nik->set_a(5);
        nik->set_l(1);
        float res;
        EXPECT_EQ(0, nik->get_descartes_y(5, res));
        EXPECT_EQ(-1, nik->get_descartes_y(1, res));
    }

    TEST_F(NikomedTest, descartes_a_equal_l)
    {
        nik->set_a(1);
        nik->set_l(1);
        float res;
        EXPECT_EQ(0, nik->get_descartes_y(2, res));
        EXPECT_EQ(-1, nik->get_descartes_y(5, res));
    }

    TEST_F(NikomedTest, descartes_a_less_l)
    {
        nik->set_a(1);
        nik->set_l(5);
        float res;
        EXPECT_EQ(0, nik->get_descartes_y(2, res));
        EXPECT_EQ(-1, nik->get_descartes_y(15, res));
    }

    TEST_F(NikomedTest, polar)
    {
        nik->set_a(1);
        nik->set_l(2);
        float res;
        EXPECT_EQ(0, nik->get_polar_r(20, res));
        EXPECT_EQ(-1, nik->get_polar_r(90, res));
    }
    
    TEST_F(NikomedTest, curve)
    {
        nik->set_a(1);
        nik->set_l(2);
        float* arr_res = new float[3];
        EXPECT_EQ(0, nik->get_curve_r(nullptr));
        EXPECT_EQ(3, nik->get_curve_r(arr_res));

        nik->set_a(2);
        nik->set_l(1);
        EXPECT_EQ(2, nik->get_curve_r(arr_res));

        delete[] arr_res;
    }
    
    TEST_F(NikomedTest, circle)
    {
        float res;

        nik->set_a(5);
        nik->set_l(2);
        EXPECT_EQ(-1, nik->get_circle_area(res));

        nik->set_a(2);
        nik->set_l(5);
        EXPECT_EQ(0, nik->get_circle_area(res));
    }

    TEST_F(NikomedTest, inflection)
    {
        float* arr_res = new float[3];

        nik->set_a(5);
        nik->set_l(2);
        EXPECT_EQ(1, nik->get_inflection_x(arr_res));

        nik->set_a(2);
        nik->set_l(5);
        EXPECT_EQ(3, nik->get_inflection_x(arr_res));

        delete[] arr_res;
    }

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}