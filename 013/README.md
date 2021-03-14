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
class Users {
public:
    Users();
    Users(string);
    Users(int);
    Users(string, int);

    void print();

    // 소멸자
    ~Users();

private:
    int years;
    string name;
};
```


<Game_information.cpp>

```cpp
#include "Game_Information.h"

/* 생략 */

// 소멸자
Users::~Users() {

}
```

위의 코드처럼 소멸자를 추가할 수 있었습니다.

이번에는 소멸자가 언제 호출되는지를 확인 해보겠습니다.

<Game_information.cpp>

```cpp
#include "Game_Information.h"

/* 생략 */

// 소멸자
Users::~Users() {
    cout << "User명이 \"" << name << "\"인 player가 계정을 탈퇴했습니다." << endl;
}
```

<main.cpp>

```cpp
#include <iostream>
#include "Game_Information.h"
using namespace std;

int main() {

	cout << "LOL\n" << endl;

	cout << "Users Data\n" << endl;

	Users A("이준원", 2015);
	{
		Users B("Cpprhtn", 2021);
	}

	cout << "\n프로그램이 종료됩니다.\n" << endl;

}
```

출력결과

![013-1](https://user-images.githubusercontent.com/63298243/111069136-07651200-850f-11eb-9068-bcd0e926a4aa.PNG)


Game_information.cpp파일에서, 소멸자가 호출되면, 게임 계정을 탈퇴했다는 문구가 나오도록 수정해보았습니다.

Users A 스코프 안에 Users B를 생성했습니다.
그리고 B의 스코프가 끝나므로 B의 소멸자가 먼저 호출되게 됩니다.

A의 스코프는 아직 끝이난게 아니므로, "프로그램이 종료됩니다."라는 문구가 먼저 출력이 되며,

프로그램이 종료되며 A의 소멸자를 호출하게 됨을 알 수 있습니다.