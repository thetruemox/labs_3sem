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
TEST(Base_constructor, Cursor)
{
	Cursor cursor;
	EXPECT_EQ(cursor.x_length, 0);
	EXPECT_EQ(cursor.y_width, 0);
}
TEST(Base_constructor, Warehouse)
{
	Warehouse warehouse;
	EXPECT_EQ(warehouse.get_length(), BASE_SIZE);
	EXPECT_EQ(warehouse.get_width(), BASE_SIZE);
	EXPECT_EQ(warehouse.get_height(), BASE_SIZE);
	EXPECT_EQ(warehouse.get_temperature(), BASE_SIZE);
	EXPECT_EQ(warehouse.get_size(), 0);
}
TEST(Base_constructor, Warehouse_map)
{
	Warehouse_map map;
	EXPECT_EQ(map.get_length(), BASE_SIZE);
	EXPECT_EQ(map.get_width(), BASE_SIZE);
	EXPECT_EQ(map.get_height(), BASE_SIZE);
}

TEST(Set, Box)
{
	Box box;

	for (int i = -100; i < 0; i++)
	{
		EXPECT_EQ(box.set_all(i,i,i), false);
	}
	for (int i = 1; i < 100; i++)
	{
		EXPECT_EQ(box.set_all(i, i, i), true);
	}
}

TEST(Set, Cool_box)
{
	Cool_box box;

	for (int i = -100; i < 100; i++)
	{
		EXPECT_NO_THROW(box.set_temperature(i));
		EXPECT_EQ(box.get_temperature(), i);
	}
}

TEST(Set, Fragile_box)
{
	Fragile_box box;

	for (int i = -100; i < 0; i++)
	{
		EXPECT_THROW(box.set_pressure(i), const char*);
		EXPECT_THROW(box.set_max_pressure(i), const char*);
	}
	for (int i = 0; i < 100; i++)
	{
		EXPECT_NO_THROW(box.set_pressure(i));
		EXPECT_NO_THROW(box.set_max_pressure(i));
	}
}

TEST(Methods, Box_container)
{
	Box_container container;

	for (int i = 0; i < 2; i++)
	{
		EXPECT_EQ(container.put_box_auto(new Box), true);
		EXPECT_EQ(container.size(), 1);
		EXPECT_NO_THROW(container.delete_box(0));
	}
}

TEST(Put_box, Warehouse)
{
	int size = 10;

	Warehouse warehouse(size, size, 1, size);

	for (int i = 0; i < size*size; i++)
	{
		EXPECT_EQ(warehouse.put_box_auto(new Box), true);
	}
	EXPECT_EQ(warehouse.put_box_auto(new Box), false);
}

TEST(Delete_box, Warehouse)
{
	int size = 10;

	Warehouse warehouse(size, size, 1, size);

	for (int i = 0; i < size*size; i++)
	{
		EXPECT_EQ(warehouse.put_box_auto(new Box), true);
	}
	
	for (int i = 0; i < size*size; i++)
	{	
		EXPECT_EQ(warehouse.delete_box(i), true);
	}

	EXPECT_EQ(warehouse.get_size(), 0);
}

TEST(Move_box, Warehouse)
{
	int size = 10;
	Cursor cursor;

	Warehouse warehouse(size, size, 1, size);
	warehouse.put_box_auto(new Box);

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cursor.x_length = i;
			cursor.y_width = j;
			EXPECT_EQ(warehouse.move_box(0, cursor), true);
		}
	}
}