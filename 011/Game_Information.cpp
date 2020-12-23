#include "Game_Information.h"

// 기본 생성자
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


// 생성자 오버로딩
Users::Users():name("비공개"),years(2020){

}

Users::Users(string names):name(names),years(2020){

}

Users::Users(int n):name("비공개"),years(n){

}

Users::Users(string names, int n):name(names),years(n){

}

void Users::print(){
    cout << "사용자명: " << name << ", 생성년도: " << years << endl;
}