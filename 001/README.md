# 입출력
반갑습니다. Cpprhtn입니다.

C++형태의 입출력은 iostream 헤더를 불러와야하며, 이 헤더에는 std라는 namespace가 있습니다.   
(namespace는 다음강에서 다룹니다.)

iostream 헤더의 많은 기능중 입출력에 대해 먼저 알아봅시다.

cin은 입력, cout은 출력, endl은 개행을 의미하는 객체입니다.

이를 이용해서 두수의 합을 출력하는 프로그램을 짜 봅시다.

```C++
#include <iostream>

int main()
{
    int x, y;

    std::cout << "두 정수를 입력하세요 :";
    std::cin >> x >> y;
    int sum(x+y);
    std::cout << "두 수의 합은 " << sum << "입니다." << std::endl;
}
```
위 코드처럼 cout와 cin에서의 `<`, `>` 방향을 유의해서 외우시길 바랍니다.

큰 틀은 C언어와 변한 것이 없으며, scanf_s, printf대신 cin, cout를 쓰면 된다는 느낌입니다.

대신 C언어와의 차이점으로는, 형식지정자(%d, %f, ...)가 필요없다는 겁니다.

어떤 값이나 변수를 던져주면 그 자료형을 알아서 인식해서 알아서 입출력합니다.


### 소수점 출력
```C++
#include <iostream>


int main(){

    double f;

    std::cout << "소수를 입력하세요: ";
    std::cin >> f;
    std::cout << "입력한 값은 " << f << "입니다." << std::endl;

    return 0;
}
```
3.14를 입력했다면 3.14가 출력될 것입니다.
그러나 3.140처럼 특정 자릿수까지 출력을 하고싶다면 아래와 같이 고칠 수 있습니다.
```C++
#include <iostream>


int main(){

    double f;

    std::cout << "소수를 입력하세요: ";
    std::cin >> f;
    std::cout.setf(ios::fixed);
    std::cout.setf(ios::showpoint);
    std::cout.precision(3);
    std::cout << "입력한 값은 " << f << "입니다." << std::endl;

    return 0;
}
```
이렇게 했을경우 출력은 3.140이 됩니다.
출력되는 자릿수는 cout.precision()에 들어가는 숫자입니다.


### 실습
이를 바탕으로 3.14와 2.72의 수를 받아와 두 수의 곱을 출력하는 프로그램을 짜 주세요.
```C++
#include <iostream>

int main()
{

}
```