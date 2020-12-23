#include <iostream>
using namespace std;
#include <memory>
#include <list>
#include <vector>

#include "Warehouse.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void foo()
{
    Warehouse house(3, 3, 1, 28);
    
    house.put_box_manual(new Box(), *new Cursor(0,0));
    house.map_out();
    cout << endl;

    house.put_box_auto(new Box());
    house.map_out();
    cout << endl;

    house.move_box(1, *new Cursor(2, 2));
    house.map_out();
    cout << endl;

    house.move_box(0, *new Cursor(1, 2));
    house.map_out();
    cout << endl;

    house.delete_box(1);
    house.delete_box(0);

    house.out_all_boxes(cout);

    house.map_out();
    cout << endl;
}

int main()
{ 
    foo();
    
    _CrtDumpMemoryLeaks();
    return 0;
}

