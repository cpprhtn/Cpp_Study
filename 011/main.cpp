#include <iostream>
#include "Game_Information.h"
using namespace std;

int main(){

    cout << "LOL" << endl;

    info A;

    A.print(); // 선언 후 바로 호출 (즉 기본 생성자 값 호출)

    A.set("Hide on bush", 20);
    A.print();

    A.set(17);
    A.print();

    A.set("SKTT1 Faker");
    A.print();

    return 0;
}