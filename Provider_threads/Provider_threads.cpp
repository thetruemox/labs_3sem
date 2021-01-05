#include <iostream>
#include "Provider.h"
#include <thread>

using namespace std;

void recursive_provider(Provider& provider);

int main()
{
    Warehouse warehouse(20, 20, 20, 34);

    Provider provider(&warehouse);
    Provider provider2(&warehouse);
    Provider provider3(&warehouse);
    Provider provider4(&warehouse);
    Provider provider5(&warehouse);

    thread t([&]() {
           recursive_provider(provider);
        });
    thread t2([&]() {
        recursive_provider(provider2);
        });
    thread t3([&]() {
        recursive_provider(provider3);
        });
    thread t4([&]() {
        recursive_provider(provider4);
        });
    thread t5([&]() {
        recursive_provider(provider5);
        });
  
    bool work = true;

    thread out([&]() {
        do
        {
            cin >> work;
        } while (cin.good());
        });

    while (work)
     {
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << endl;
            //warehouse.out_all_boxes(cout);
            cout << endl;
            warehouse.map_out();
     }

    out.detach();
    t.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    t5.detach();

    return 0;
}

void recursive_provider(Provider& provider)
{
    this_thread::sleep_for(chrono::milliseconds(provider.rand_num(500, 3000)));

    if (provider.get_size() == 0)
    {
        provider.add_box();
    }
    else
    {
        if (provider.rand_num(1, 10) > 5)
        {
            provider.add_box();
        }
        else provider.delete_box();
    }

    recursive_provider(provider);
}
