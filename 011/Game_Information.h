#include <iostream>
#include <string>
using namespace std;

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