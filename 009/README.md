# code division
반갑습니다. Cpprhtn입니다.

이번에는 코드 분할에 대해 설명하겠습니다.

클래스가 여러 개가 되거나 멤버가 많아지면 소스 코드 길이가 길어져서 코드를 보기 힘들어집니다.

또한 private인 멤버들은 메인 파일에서 숨겨야 은닉성을 부각시킬 수 있습니다.

여러 가지 이유로 코드를 여러 파일로 분할하게 됩니다.

주로 클래스에 대해서 분할을 합니다.

헤더파일에는 클래스의 선언을,

cpp파일에는 멤버 함수들의 정의가 들어가는 것이 일반적입니다.

헤더파일을 통해서 클래스의 멤버를 확인할 수 있고, 그 내용은 cpp파일안에 숨겨지므로 은닉성을 가질 수 있습니다.

이전 강에서 쓰였던 코드입니다.
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

위 코드를 총 3분할 할 것입니다.
<Array10.h>

```C++
class Array10{
public:
    void set_arr(int*);
    void reverse();
    int get(int);
private:
    int arr[MAX];
    void swap(int&, int&);
};
```

<Array10.cpp>

```C++
#include <iostream>
#include "Array10.h"
using namespace std;

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

<main.cpp>

```C++
#include <iostream>
#include "Array10.h"
using namespace std;

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
```


위처럼 코드 하나를 3분할 하였습니다.

.h 파일에는 클래스의 선언이, .cpp 파일에는 클래스 멤버함수의 정의가, main.cpp에는 main코드만 남게됩니다.

.cpp파일에 멤버함수가 정의되어있기 때문에 main파일에서 은닉성을 지킬 수 있게됩니다.


### 다른 클래스를 멤버 변수로하는 클래스 만들어보기

구조체 안에 또 다른 구조체가 존재할 수 있었습니다.

마찬가지로 클래스 안에도 타 클래스의 멤버 변수를 쓸 수 있습니다.

어떠한 점의 좌표를 출력하는 코드를 만들어봅시다.

<Dot.h>

```Cpp
class Dot{
private:
    int x, y;
public:
    void set(int, int);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
};
```

<Dot.cpp>

```Cpp
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
```

<Location.h>

```Cpp
#include "Dot.h"

class Location{
private:
    Dot Q, R;
public:
    void setQ(int, int);
    void setR(int, int);
    void print();
};
```

<Location.cpp>

```Cpp
#include <iostream>
#include "Location.h"
using namespace std;

void Location::setQ(int x1, int y1){
    A.setX(x1);
    A.setY(y1);
}

void Location::setR(int x1, int y1){
    B.setX(x1);
    B.setY(y1);
}

void Location::print(){
    cout << "A(" <<A.getX() << ", " <<A.getY() << ")" << endl;
    cout << "B(" <<B.getX() << ", " <<B.getY() << ")" << endl;
}
```

<main2.cpp>

```Cpp
#include <iostream>
#include "Location.h" //Location.h에서 Dot.h를 include했기에 선언할 필요 없음
using namespace std;

int main(){
    //Dot 클래스 사용
    Dot P;
    P.set(3, 4);
    cout << "P(" << P.getX() << ", " << P.getY() << ")" << endl;

    //Dot 클래스를 사용해 만든 Location 클래스 사용
    Location Two_dot;
    Two_dot.setQ(-1, 2);
    Two_dot.setR(-5, -5);
    Two_dot.print();

    return 0;
}
```
> P(3, 4)

> Q(-1, 2)

> R(-5, -5)

메인함수의 내용중 일부이다.
```Cpp
//Dot 클래스 사용
Dot P;
P.set(3, 4);
cout << "P(" << P.getX() << ", " << P.getY() << ")" << endl;
```
Dot 클래스에서 점 하나의 좌표를 저장할 수 있음을 알 수 있다.

이를 이용해서 P 점의 좌표를 출력하는 과정을 위 처럼 짤 수 있다.

메인함수의 내용중 일부이다.
```Cpp
//Dot 클래스를 사용해 만든 Location 클래스 사용
Location Two_dot;
Two_dot.setQ(-1, 2);
Two_dot.setR(-5, -5);
Two_dot.print();
```
이번에는 Location 클래스에서 점의 좌표를 저장하고, 출력하는 함수까지 만들었다.

이렇게 되면 위 코드처럼 내부적인 동작이 드러나지 않고 좌표의 세팅과 출력이 모두 이루어진다.

은닉성도 만족하고, main함수에서의 코드도 깔끔해지는것을 볼 수 있다.