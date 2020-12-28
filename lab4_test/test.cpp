#include "pch.h"

#define BASE_SIZE 1
TEST(Base_constructor, Box) 
{
	Box box;
	EXPECT_EQ(box.get_length(), BASE_SIZE);
	EXPECT_EQ(box.get_width(), BASE_SIZE);
	EXPECT_EQ(box.get_height(), BASE_SIZE);
	EXPECT_EQ(box.get_mass(), BASE_SIZE);
}

TEST(Base_constructor, Cool_box)
{
	Cool_box box;
	EXPECT_EQ(box.get_length(), BASE_SIZE);
	EXPECT_EQ(box.get_width(), BASE_SIZE);
	EXPECT_EQ(box.get_height(), BASE_SIZE);
	EXPECT_EQ(box.get_mass(), BASE_SIZE);
	EXPECT_EQ(box.get_temperature(), BASE_SIZE);
}

TEST(Base_constructor, Fragile_box)
{
	Fragile_box box;
	EXPECT_EQ(box.get_length(), BASE_SIZE);
	EXPECT_EQ(box.get_width(), BASE_SIZE);
	EXPECT_EQ(box.get_height(), BASE_SIZE);
	EXPECT_EQ(box.get_mass(), BASE_SIZE);
	EXPECT_EQ(box.get_max_pressure(), BASE_SIZE);
	EXPECT_EQ(box.get_pressure(), 0);
}

TEST(Base_constructor, Fragile_cool_box)
{
	Fragile_cool_box box;
	EXPECT_EQ(box.get_length(), BASE_SIZE);
	EXPECT_EQ(box.get_width(), BASE_SIZE);
	EXPECT_EQ(box.get_height(), BASE_SIZE);
	EXPECT_EQ(box.get_mass(), BASE_SIZE);
	EXPECT_EQ(box.get_temperature(), BASE_SIZE);
	EXPECT_EQ(box.get_max_pressure(), BASE_SIZE);
	EXPECT_EQ(box.get_pressure(), 0);
}
TEST(Base_constructor, Box_container)
{
	Box_container container;
	EXPECT_EQ(container.get_base_length(), BASE_SIZE);
	EXPECT_EQ(container.get_base_width(), BASE_SIZE);
	EXPECT_EQ(container.get_max_height(), BASE_SIZE);
	EXPECT_EQ(container.get_temp_height(), 0);

}