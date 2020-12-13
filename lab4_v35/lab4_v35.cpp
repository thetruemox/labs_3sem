#include <iostream>
using namespace std;
#include <memory>
#include <list>
#include <vector>

#include "Warehouse.h"

int main()
{ 
    Warehouse house(50, 50, 1000, 228);

    for (int i = 1; i < 100; i++)
    {
        cout << house.put_box(new Cool_box(i,i,i,1,100)) << " ";
    }
    cout << endl << endl;

    house.map_out();

    return 0;
}

