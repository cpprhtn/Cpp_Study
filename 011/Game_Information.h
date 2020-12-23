#include <iostream>
#include <string>
using namespace std;

// 기본 생성자
class info{
public:
    info(); // 기본 생성자
    void set(string);
    void set(int);
    void set(string, int);

    void print();

private:
    int age;
    string ID;
};


// 생성자 오버로딩
class Users{
public:
    Users();
    Users(string);
    Users(int);
    Users(string, int);

    void print();

private:
    int years;
    string name;
};