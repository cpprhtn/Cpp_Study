#include <iostream>
#include "Game_Information.h"
using namespace std;

int main(){

    cout << "LOL" << endl;

    info A;
    A.set("Hide on bush", 20);
    A.print();

    A.set(17);
    A.print();

    A.set("SKTT1 Faker");
    A.print();

    return 0;
}