#include <iostream>
#include "Location.h"
using namespace std;

int main(){

    cout << "9강에서 사용한 Location class" << endl;
    Location Two_dot;
    Two_dot.setQ(-1, 2);
    Two_dot.setR(-5, -5);
    Two_dot.print();

    cout << "복사 생성자를 통한 복사" << endl;
    Location copy_dot(Two_dot);
    copy_dot.print();

    cout << "복사 생성자를 통한 복사 2" << endl;
    Location copy_dot2 = Two_dot;
    copy_dot2.print(); 

    return 0;
}