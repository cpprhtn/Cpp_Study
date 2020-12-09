#include <iostream>
#include "Location.h" //Location.h에서 Dot.h를 include했기에 선언할 필요 없음
using namespace std;

int main(){
    //Dot 클래스 사용
    Dot P;
    P.set(3, 4);
    cout << "P(" << P.getX() << ", " << P.getY() << ")" << endl;

    //Dot 클래스를 사용해 만든 Location 클래스 사용
    Location Two_dot;
    Two_dot.setQ(-1, 2);
    Two_dot.setR(-5, -5);
    Two_dot.print();

    return 0;
}