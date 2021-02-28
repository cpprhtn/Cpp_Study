# Constructor
반갑습니다. Cpprhtn입니다.

저번 강의에서는 기본 생성자와 생성자의 오버로딩에 대해 다루었습니다.

이번에는 복사 생성자와 복사 대입 연산자에 대한 설명을 하겠습니다.

클래스에서 객체를 복사하는 방법은 두가지가 있습니다.

1. 객체 생성시 복사 생성자를 이용하는 복사

2. 복사 대입연산자를 이용하는 복사

하나하나 알아봅시다.

## 복사 생성자 (Copy constructor)

우선 첫번째 방법인 복사 생성자입니다.

복사 생성자는 일반 생성자와 비슷하나, 안의 매개변수 리스트가 자신의 자료형 오브젝트 하나가 들어갑니다.

```cpp
add_class A(1, 2);
```

두 숫자를 더해주는 클래스 A가 하나 있다고 가정합시다.

B라는 클래스는 A클래스와 똑같이 만들고 싶다고 한다면 아래처럼 쓸 수 있습니다.

```cpp
// 새로 생성
add_class B(1, 2);

// 복사 생성자 이용
add_class B(A);
```

지금은 위의 두가지 코드가 별로 차이가 안난다고 느낄 수도 있습니다.

그렇다면 아래와 같은 클래스가 있다고 바꿔봅시다.

```cpp
clac_class A(1, 2, 3, 4, "+");

// 새로 생성
clac_class B(1, 2, 3, 4, "+");

// 복사 생성자 이용
clac_class B(A);
```

생성자의 매개변수 리스트가 늘어났습니다.

새로 생성한 B클래스가 A클래스와 동일한지 확인하려면 매개변수 리스트 모두를 비교해봐야 합니다.

그러나 복사 생성자를 이용했을 경우에는 우리는 바로 A클래스를 복사한것을 알 수 있습니다.

훨신 가독성이 뛰어나진 것을 느낄 수 있습니다.

또한 복사 생성자를 `=`을 이용하여 사용할 수도 있습니다.

```cpp
clac_class A(1, 2, 3, 4, "+");

// 복사 생성자 이용 2
clac_class B = A;
```

복사 생성자를 사용하여 코드를 짜 봅시다.

<main.cpp>

```cpp
int main(){

    cout << "9강에서 사용한 Location class" << endl;
    Location Two_dot;
    Two_dot.setQ(-1, 2);
    Two_dot.setR(-5, -5);
    Two_dot.print();

    cout << "복사 생성자를 통한 복사" << endl;
    Location copy_dot(Two_dot);
    copy_dot.print();

    cout << "복사 생성자를 통한 복사 2" << endl;
    Location copy_dot2 = Two_dot;
    copy_dot2.print();

    return 0;
}
```

> 9강에서 사용한 Location class

> Q(-1, 2)

> R(-5, -5)

> 복사 생성자를 통한 복사

> Q(-1, 2)

> R(-5, -5)

> 복사 생성자를 통한 복사 2

> Q(-1, 2)

> R(-5, -5)


위 코드에서 아래와 같은 부분을 볼 수 있습니다.

```cpp
cout << "복사 생성자를 통한 복사" << endl;
Location copy_dot(Two_dot);
copy_dot.print();

cout << "복사 생성자를 통한 복사 2" << endl;
Location copy_dot2 = Two_dot;
copy_dot2.print();
```

Two_dot라는 클래스 변수를 그대로 복사하여 copy_dot, copy_dot2라는 클래스 변수를 생성했습니다.

이런식으로 복사 생성자를 사용할 수 있습니다.



## 복사 대입 연산자 (Copy assignment operator)

생성시기에 대입연산자 '=' 를 이용해서 대입을 하면 복사 생성자가 호출이 되고 

생성후 대입연산자 '=' 를 이용해서 대입을 하게되면 복사 대입연산자가 호출이 됩니다.

```cpp
// 복사 생성자 
Users A("Hide on bush", 20);

Users B1(p1);  // 방법 1

Users B2 = A;  // 방법 2


// 복사 대입 연산자
Users A("Hide on bush", 20);

Users B(22, "Kong");

B = A;
```