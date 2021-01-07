#include <iostream>
#include "Provider.h"
#include <thread>

using namespace std;

void recursive_provider(Provider* provider);

int main()
{
    Warehouse warehouse(20, 20, 20, 34);

    vector<Provider*> providers;
    vector<thread> threads;


    int size = 10;

    for (int i = 0; i < size; i++)
    {
        providers.push_back(new Provider(&warehouse));
    }

    for (auto n : providers) {
       
        threads.push_back(thread([&]() {
            recursive_provider(n);
            }));
    }


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
            warehouse.out_all_boxes(cout);
            cout << endl;
            warehouse.map_out();
     }
    out.detach();

    for (auto& thr : threads) {
        thr.detach();
    }

    
  

    return 0;
}

void recursive_provider(Provider* provider)
{
    this_thread::sleep_for(chrono::milliseconds(provider->rand_num(500, 3000)));

    if (provider->get_size() == 0)
    {
        provider->add_box();
    }
    else
    {
        if (provider->rand_num(1, 10) > 5)
        {
            provider->add_box();
        }
        else provider->delete_box();
    }

    recursive_provider(provider);
}
