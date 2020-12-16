#include <iostream>
using namespace std;

int sum(int x, int y){
    return x+y;
}

int sum(int x, int y, int z){
    return x+y+z;
}

int main(){

    cout << sum(1, 2) << endl;
    cout << sum(2, 3, 5) << endl;

    return 0;
}