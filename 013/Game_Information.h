#pragma once

#include <iostream>
#include <string>
using namespace std;

class Users {
public:
    Users();
    Users(string);
    Users(int);
    Users(string, int);

    void print();

    // 소멸자
    ~Users();

private:
    int years;
    string name;
};