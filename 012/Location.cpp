#include <iostream>
#include "Location.h"
using namespace std;

void Location::setQ(int x1, int y1){
    Q.setX(x1);
    Q.setY(y1);
}

void Location::setR(int x1, int y1){
    R.setX(x1);
    R.setY(y1);
}

void Location::print(){
    cout << "Q(" <<Q.getX() << ", " <<Q.getY() << ")" << endl;
    cout << "R(" <<R.getX() << ", " <<R.getY() << ")" << endl;
}