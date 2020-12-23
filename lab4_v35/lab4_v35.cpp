#include <iostream>
using namespace std;
#include <memory>
#include <list>
#include <vector>

#include "Warehouse.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main()
{ 
    Warehouse house(2, 2, 10, 28);

    for (int i = 0; i < 100; i++)
    {
        if (house.put_box(new Fragile_box(1, 1, 1, 10, 10))) cout << i << " ";
    }
   
    cout << endl << endl;
    house.map_out();
    cout << endl;

    //house.put_box(new Fragile_box(1, 1, 1, 10, 10));

    house.out_all_boxes(cout);

    _CrtDumpMemoryLeaks();
    return 0;
}

