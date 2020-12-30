#include <iostream>
#include "Dot.h"
using namespace std;

void Dot::set(int x1, int y1){
    x = x1;
    y = y1;
}

void Dot::setX(int x1){
    x = x1;
}

void Dot::setY(int y1){
    y = y1;
}

int Dot::getX(){
    return x;
}

int Dot::getY(){
    return y;
}