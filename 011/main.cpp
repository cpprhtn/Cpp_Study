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


    /*
    생성자 오버로딩
    */
    
    cout << "Users Data" << endl;

    Users A();
    A.print();

    Users B(2012);
    B.print();

    Users C("이준원");
    C.print();

    Users D("이준원",2015);
    D.print();
}