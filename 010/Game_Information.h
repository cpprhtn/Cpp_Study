#include <iostream>
#include <string>
using namespace std;

class info{
public:
    // set 함수에서 오버로딩 된 것을 볼 수 있다.
    void set(string);
    void set(int);
    void set(string, int);

    void print();
private:
    int age;
    string ID;
};