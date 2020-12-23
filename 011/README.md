# Constructor
반갑습니다. Cpprhtn입니다.

Constructor는 생성자를 말합니다.

생성자는 말 그대로 오브젝트가 생성될 때 실행되는 함수로, 1번만 실행됩니다.

주로 멤버 변수 초기화에 사용됩니다.

생성자의 특징 몇가지를 우선 정의하고 가겠습니다.

### 생성자의 특징

1. 생성자의 이름은 클래스명과 동일 (대소문자까지)
2. public 클래스에서 선언
3. 결과형 리턴값을가지지 않음

## 기본 생성자 (Default constructor)

우선은 기본 생성자에 대해 먼저 알아봅시다.

기본 생성자는 매개변수가 없는 생성자입니다.

생성자를 만들지 않으면 자동으로 빈 기본 생성자가 클래스에서 만들어집니다.

지난번에 만들어둔 Game_Information 클래스를 이용하여 생성자를 만들어봅시다.

<Game_Information.h>

```cpp
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
```
클래스 안에 기본 생성자가 생긴것을 볼 수 있습니다.
기본 생성자이므로 ID는 빈 문자열로, age는 0으로 초기화 해주도록 합시다. (다른값도 가능)

<Game_Information.cpp>

```cpp
.
.
.
info::info(){
    age = 0;
    ID = "";
}
.
.
.
```

이전 코드에서 위 코드를 추가해 주었습니다.

이렇게 기본 생성자 정의가 끝났다면 main함수에서 info 클래스를 선언할때 기본 생성자를 1번 부르게 되며, 우리가 설정한 값인 age = 0, ID = "" 형식으로 초기화가 될 것입니다.

<main.cpp>

```cpp
.
.
.
    info A;
    A.print(); // 선언 후 바로 호출 (즉 기본 생성자 값 호출)
.
.
.
```

> LOL

> 아이디: , 나이: 0

> 아이디: Hide on bush, 나이: 20

> 아이디: Hide on bush, 나이: 17

> 아이디: SKTT1 Faker, 나이: 17

초기화가 잘 되어있음을 볼 수 있습니다.


### 생성자를 다른 방법으로 정의

아까 생성자를 정의할 때 아래 코드처럼 정의를 했었습니다.

<Game_Information.cpp>

```cpp
.
.
.
info::info(){
    age = 0;
    ID = "";
}
.
.
.
```

이번에는 다른 방법으로 정의해보도록 합시다.

```cpp
.
.
.
// 사용 형태
// 클래스명::매개변수():멤버변수1(초기값),멤버변수2(초기값),멤버변수3(초기값)...멤버변수n(초기값) { 내용 }
info::info():age(0),name(""){
}
.
.
.
```

위처럼 정의를 한다면 { } 안에 정의할 필요없이 바로 각 멤버 변수에 초기값을 할당할 수 있습니다.


## 생성자 오버로딩

바로 이전강의에서 오버로딩을 했었습니다.

이전 강의에서는 따로 선언을 한 다음, 클래스의 멤버 함수를 통해 매개변수의 값을 지정해주어야 했습니다.

```cpp
info A;
A.set("Hide on bush", 20);
```

우리는 생성자 오버로딩을 통해서 간단하게 선언할 수 있도록 해봅시다.

C++에서 추가된 선언 방식인 괄호를 사용할 수 있도록 만들 것입니다.

```cpp
int i(10);
double j(2.72);
```

Game_Information에서 Users 클래스로 만들것입니다.

years는 계정 생성년도, name는 사용자명을 저장하는 변수가 되겠습니다.

<Game_Information.h>

```cpp
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
```

헤더파일의 Users 클래스를 보면 생성자가 오버로딩 되어있습니다.

Users라는 동일한 변수가 4개 선언되어있는걸 볼 수 있습니다.

<Game_Information.cpp>

```cpp
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
```

위의 코드를 보면 오버로딩된 생성자에 대해서 각각 초기화를 해주는 것을 볼 수 있습니다.

```cpp
int main()
{
    /*
    생성자 오버로딩
    */
    
    cout << "Users Data" << endl;

    Users A();
    A.print();

    Users B(2012);
    B.print();

    Users C("이준원");
    C.print();

    Users D("이준원",2015);
    D.print();
}
```

> 사용자명: 비공개, 생성년도: 2020

> 사용자명: 비공개, 생성년도: 2012

> 사용자명: 이준원, 생성년도: 2020

> 사용자명: 이준원, 생성년도: 2015

위처럼 각각의 생성자가 잘 불러진것을 확인할 수 있습니다.

