# namespace
반갑습니다. Cpprhtn입니다.

```C++
#include<iostream>
int main() 
{ 
    std::cout <<"Hello, World!!"<< std::endl;
}
```

일반적인 IDE에서 새 파일을 만들면 위와 같은 코드를 볼 수 있을 것입니다.


위 코드를 먼저 분석해봅시다.

```C++
#include <iostream> // iostream은 입출력을 위한 헤더파일입니다.

int main() //시작함수(진입점)
{

    std::cout << "Hello World!\n" << std::endl;

    //std::cout = 출력함수
    //std::endl = 개행함수 '\n'
}
```

여기에 각 함수앞에 std:: 형태가 붙어있는것을 볼 수 있습니다.
std는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 namespace 입니다.

다른사람의 코드를 가져와 같이 사용하다보면 겹치는 함수가 많이 생기는데
이를 구분하기 위해 namespace라는 이름공간(직역)을 만든것입니다.

예를 들면 동명이인과 같습니다.
한 학교내에 이름이 같을수록 앞에 추가적인 특징등을 붙여 쓰는 경우가 많습니다.
이를 코드화 하면 아래와 같습니다.

```C++
#include<iostream>
int main()
{
    _class_1::cpprhtn(); //1반의 cpprhtn
    _class_2::cpprhtn(); //2반의 cpprhtn
    //서로 다른사람을 호출한 것
}
```
위 처럼 구별을 위해 `namespace`를 사용합니다.


## using namespace std
일반적으로 혼자 코드를 짜서 함수가 겹치지 않는 상황일때도 std를 붙여주다보면 std를 수십개, 수백개를 써 주어야 하는 상황이 생길 수도 있습니다.
using namespace std; 라는 문장을 통해서 std를 생략할 수 있습니다.
아래와 같이 사용합니다.

```C++
#include<iostream>
using namespace std;
int main() 
{
    cout << "Hello, World!!"<< endl;
}
```



C++ 표준 라이브러리는 엄청 많은 함수들이 존재하고 있습니다. 자칫 잘못하다가 이름을 겹치게 사용한다면, 고치느라 시간을 많이 잡아먹을 것입니다. 
게다가 std 에는 매번 수 많은 함수들이 새롭게 추가되고 있기 때문에 C++ 버전이 바뀔 때 마다 기존에 잘 작동하던 코드가 이름 충돌로 인해 동작하지 않게되는 문제가 발생할 수 있습니다.

따라서 using namespace std; 보다, std:: 를 직접 앞에 붙여서 std 의 이름공간의 함수이다 라고 명시해주는 것이 좋습니다. 