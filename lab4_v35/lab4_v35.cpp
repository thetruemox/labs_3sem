#include <iostream>
using namespace std;
#include <memory>
#include <list>
#include <vector>

#include "Warehouse.h"

//Копируй объекты

int main()
{ 
    Warehouse house(10, 10, 10, 28);

    house.put_box(new Fragile_cool_box(9,9,9,10,20,30));
    house.put_box(new Fragile_cool_box(9, 9, 9, 10, 20, 30));

    cout << endl << endl;

    house.map_out();

    return 0;
}

