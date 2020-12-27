#include <iostream>
#include "My_vector.h"
using namespace std;

int main()
{
    My_vector<int> arr;
    
    int m = 12;
    arr.push_back(m);
    m = 22;
    arr.push_back(m);
    m = 31;
    arr.push_back(m);

    arr.pop_back();

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}

