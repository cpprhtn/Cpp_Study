#include "Game_Information.h"

void info::set(int n){
    age = n;
}

void info::set(string name){
    ID = name;
}

void info::set(string name, int n){
    age = n;
    ID = name;
}

void info::print(){
    cout << "아이디: " << ID << ", 나이: " << age << endl;
}