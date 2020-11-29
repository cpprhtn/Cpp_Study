# class
반갑습니다. Cpprhtn입니다.

클래스 내부의 public, private, friend 중에 이번에는 private도 함께 사용해 보겠습니다.

private, 개인적인 의미로써, 외부에서의 접근이 제한됩니다.

아래 코드를 보면서 private도 이해해봅시다.

```C++
#include <iostream>
using namespace std; 

class New_Class{  
private:
    int i;
    double d;
};

int main(){

    New_Class A, B; //object

    A.i = 1; //Error
    A.d = 3.14; //Error
    B.i = 2; //Error
    B.d = 6.28; //Error

    cout << "object A: " << A.n << ", " << A.f << endl;
    cout << "object B: " << B.n << ", " << B.f << endl;
    return 0;
}
```
바로 이전 6강의 첫번째 코드를 가져와보았는데, class부분에서 public 대신 private가 선언된 것을 볼 수 있습니다.

그러나 이 코드를 실행해보면 멤버 변수에 접근하는 부분에서 에러가 뜹니다.

private 멤버 변수에 바로 접근을 할 수 없기 때문에 멤버 함수를 통해 접근할 필요가 있습니다.

```C++
#include <iostream>
using namespace std; 

class New_Class{  
private:
    int i;
    double d;

public:
    void set_i(int);
    void set_d(double);
    int get_i();
    int get_d();
};

int main(){

    New_Class A, B; //object

    A.set_i(1);
    A.set_d(3.14);
    B.set_i(2);
    B.set_d(6.28);

    cout << "A.i: " << A.get_i() << endl;
    cout << "B.d: " << B.get_d() << endl;

    return 0;
}

void New_Class::set_i(int x){
    i = x;
}

void New_Class::set_d(double y){
    d = y;
}

int New_Class::get_i(){
    return i;
}

int New_Class::get_d(){
    return d;
}
```
> A.i: 1

> B.d: 6

### 왜 private를 사용하는가

class의 private는 C++ 언어에서 매우 중요한 요소입니다.

객체 지향 언어의 특성중 하나인 은닉성에 큰 영향을 주기 때문입니다.

여기서 말하는 은닉성은 사용자가 프로그램을 사용하면서 필요한 최소한의 정보만 제공하고,

그러한 기능이 실행되는 과정이나 절차는 최대한 가려서 사용자가 알지 못하게 한다는 것입니다.

이를 캡슐화라고도 부릅니다.

이러한 은닉성을 지키기 위해서 public대신 private를 사용한다고 볼 수 있습니다.

아래는 배열을 역순으로 정렬(리버스) 해주는 코드를 짠 것입니다.
```C++
#include <iostream>
#define MAX 10
using namespace std;

class Array10{
public:
    void set_arr(int*);
    void reverse();
    int get(int);
private:
    int arr[MAX];
    void swap(int&, int&);
};

int main()
{
    Array10 A;
    int temp_arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    A.set_arr(temp_arr);
    for(int i=0; i<MAX; i++)
        cout << A.get(i) << " ";
        
    cout << endl;

    A.reverse();
    for(int i=0; i<MAX; i++)
        cout << A.get(i) << " ";

    cout << endl;

    return 0;
}

void Array10::set_arr(int *temp){
    for(int i=0; i<MAX; i++)
        arr[i] = temp[i];
}

void Array10::reverse(){
    for(int i=0; i<MAX/2; i++)
        swap(arr[i], arr[MAX-i-1]);
}

int Array10::get(int n){
    return arr[n];
}

void Array10::swap(int& a, int& b){ //레퍼런스 이용
    int temp = a;
    a = b;
    b = temp;
}
```

reverse() 함수 중에 private 멤버 함수인 swap() 함수가 쓰였습니다.

여기서 우리는 reverse() 함수가 뭔지는 알고, 사용은 하지만
그 과정에 쓰인 함수 swap() 에 대해서는 알 필요가 없어집니다.

그래서 은닉성에 따라 이 함수를 private으로 숨긴 것입니다.