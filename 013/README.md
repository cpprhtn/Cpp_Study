# Destructor
반갑습니다. Cpprhtn입니다.

저번 강의에서는 생성자에 대해 다루었습니다.

이번에는 소멸자에 대한 설명을 하겠습니다.

- 소멸자는 오브젝트가 사라질때 호출됩니다.
	- 여기서 오브젝트가 사라지는 경우는 크게 2가지입니다.
		- 프로그램이 끝났을 때.
		- 해당 scope를 벗어났을 때.

일반적으로 소멸자를 만들지 않으면, 컴파일러가 자동으로 만들어줍니다.

메모리 누수를 문법적으로 해결하는게 소멸자의 역할입니다.

소멸자를 선언하는 방법은 클래스명 앞에 ~(물결표시)를 붙여주는것입니다. (기본생성자 앞에 ~붙이는 것과 같다.)

이전에 만들었던 코드에서 한번 사용해보겠습니다.

<Game_information.h>
```cpp
class info{
public:
    info();
    void set(string);
    void set(int);
    void set(string, int);

    ~info(); // 소멸자

    void print();

private:
    int age;
    string ID;
};
```


<Game_information.cpp>

```cpp
#include "Game_Information.h"


info::info(){
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

// 소멸자
void info::~info() { 

}

void info::print(){
    cout << "아이디: " << ID << ", 나이: " << age << endl;
}
```

