#include <iostream>
using namespace std;
#include <memory>
#include <list>
#include <vector>

#include "Warehouse.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//Копируй объекты

void foo()
{
    Warehouse house(1, 1, 10, 28);

   
    house.put_box(new Fragile_box(1, 1, 1, 10, 10));
    house.put_box(new Fragile_box(1, 1, 1, 10, 10));
    house.map_out();
}

int main()
{ 
    foo();
    /*
    Warehouse house(2, 2, 10, 28);

    for (int i = 0; i < 100; i++)
    {
        if (house.put_box(new Fragile_box(1, 1, 1, 10, 10))) cout << i << " ";
    }

    cout << endl << endl;
    house.map_out();
    */

    _CrtDumpMemoryLeaks();
    return 0;
}

