#include <iostream>
#include "Array10.h"
using namespace std;

int main()
{
    Array10 A;
    int temp_arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    A.set_arr(temp_arr);
    for(int i=0; i<MAX; i++)
        cout << A.get(i) << " ";
        
    cout << endl;

    A.reverse();
    for(int i=0; i<MAX; i++)
        cout << A.get(i) << " ";

    cout << endl;

    return 0;
}