#include "Game_Information.h"

info::info(){   // 기본 생성자 정의
    age = 0;
    ID = "";
}

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