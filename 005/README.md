# string
반갑습니다. Cppbhtn입니다.

이번에는 string에 대해 알아보겠습니다.

string 자료형역시 C++로 넘어오면서 만들어진 자료형 중에 하나입니다.

C언어에서 문자열은 char arr[]; 형태였습니다.

그러나 C++에서는 cin을 통해 배열을 입력받기 난해하므로 

string헤더를 통해서 string이라는 type를 만든 것입니다.

우선 string 문자열을 통해 자기소개하는 코드를 짜봅시다.
```C++
#include <iostream>
#include <string>

int main(){

    std::string str;

    std::cout << "문자열을 입력하세요: ";
    std::cin >> str;
    std::cout << "입력한 문자열은 " << str << "입니다." << std::endl;

    return 0;
}
```
> 문자열을 입력하세요: cpprhtn
> 입력한 문자열은 cpprhtn입니다.

위와같이 출력됨을 볼 수 있습니다.

이번에는 문자열을 합쳐보도록 하겠습니다.
C에서는 strcat(a, b) 등의 형태로 문자열을 합쳤던 것을 생각하며 아래 코드를 봅시다.
```C++
#include <iostream>
#include <string>

int main(){

    std::string str1, str2, str3;

    std::cout << "단어 2개를 입력하세요: ";
    std::cin >> str1 >> str2;
    str3 = str1 + str2;
    std::cout << "합쳐진 단어는 " << str3 << "입니다." << std::endl;

    return 0;
}
```
> 단어 2개를 입력하세요: cpp rhtn
> 합쳐진 단어는 cpprhtn입니다.

위처럼 string에서는 + 연산자로 문자열을 합칠 수 있습니다.


또한 아래와 같이 string은 배열처럼 접근할 수도 있습니다.
```C++
#include <iostream>
#include <string>

int main(){

    std::string str = "cpprhtn";

    std::cout << "입력한 문자열은 " << str << "입니다." << std::endl;
    std::cout << str[0] << std::endl << str[1] << std::endl << str[2];

    return 0;
}
```



C에서처럼 C++에서도 `getline`을 이용하여 한줄 전체를 입력받을 수 있습니다.
```C++
#include <iostream>
#include <string>

int main(){

    std::string str;

    std::cout << "문자열을 입력하세요: ";
    std::getline(std::cin, str);
    std::cout << str << std::endl;

return 0;
}
```
>> 문자열을 입력하세요: I love cpp
>> I love cpp


마지막으로는 문자열 길이를 확인해보도록 하겠습니다.

```C++
#include <iostream>
#include <string>

int main(){

    std::string str;

    std::cout << "문자열을 입력하세요: ";
    std::getline(cin, str);
    std::cout << str << std::endl;
    std::cout << "문자열 길이: " << str.length() << std::endl;

    return 0;
}
```
> 문자열을 입력하세요: I love cpp
> 문자열 길이: 10