#include "Game_Information.h"

Users::Users() :name("비공개"), years(2020) {

}

Users::Users(string names) : name(names), years(2020) {

}

Users::Users(int n) : name("비공개"), years(n) {

}

Users::Users(string names, int n) : name(names), years(n) {

}

void Users::print() {
    cout << "사용자명: " << name << ", 생성년도: " << years << endl;
}

// 소멸자
Users::~Users() {
    cout << "User명이 \"" << name << "\"인 player가 계정을 탈퇴했습니다." << endl;
}