# Overloading
반갑습니다. Cpprhtn입니다.

이번에는 오버로딩에 대해 알아보겠습니다.

오버로딩은 동일한 이름을 가진 함수를 여러 개 선언 & 정의하는 것입니다.

동일한 함수명을 가진다면 어떻게 구분하느냐?

아래 코드를 보면서 이해해봅시다.

<sum.cpp>

```cpp
#include <iostream>
using namespace std;

int sum(int x, int y){
    return x+y;
}

int sum(int x, int y, int z){
    return x+y+z;
}

int main(){

    cout << sum(1, 2) << endl;
    cout << sum(2, 3, 5) << endl;

    return 0;
}
```
> 3

> 10

위의 코드에서 `sum`이라는 함수를 2개 만들었습니다.

둘의 다른점은 함수 속의 매개변수의 리스트가 다른 것입니다.

여기서 매개변수의 리스트가 다른 경우는 크게 2가지 입니다.
1. 매개변수의 개수가 다름
2. 매개변수 개수는 같지만, 매개변수의 자료형이 다름


이를 이용해서 게임의 아이디, 나이, 혹은 둘 전부를 쓸 수 있도록 함수를 만들어 봅시다.

<Game_Information.h>

```cpp
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
```

<Game_Information.cpp>

```cpp
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
```

<main.cpp>

```cpp
#include <iostream>
#include "cat.h"
using namespace std;

int main(){

    cout << "LOL" << endl;

    info A;
    A.set(20, "Hide on bush");
    A.print();

    A.set(17);
    A.print();

    A.set("SKTT1 Faker");
    A.print();

    return 0;
}
```
> LOL

> 아이디: Hide on bush, 나이: 20

> 아이디: Hide on bush, 나이: 17

> 아이디: SKTT1 Faker, 나이: 17

이런식으로 만들어 보았습니다.

오버로딩은 생성자 개념에서 중요한 역할을 하기 때문에 잘 이해하고 넘어가면 좋겠습니다.