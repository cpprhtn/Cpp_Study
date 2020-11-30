# pointer
반갑습니다. Cpprhtn입니다.

이번에는 `스마트 포인터`라는 것에 대해서 설명할 예정입니다.

기존의 C언어에서 할당과 해제 할때는 많은 오류와 데이터를 잡아먹는 상황이 자주 발생합니다.

이런 포인터 관련 오류를 최소화 하는 방법은 크게 3가지가 있습니다.

1. 표준 컨테이너 사용
표준 라이브러리나 유효성이 검증된 라이브러리를 사용하는 것입니다.
표준 라이브러리의 std::vector는 크기 조정 및 범위 검사를 포함한 동적 배열의 모든 기능을 제공하며
메모리를 자동으로 해제해줍니다.

2. 캡슐화
나중에 클래스에서 배우겠지만 캡슐화를 시켜 오류를 수정하는 방법이 있습니다.

3. 스마트 포인터를 사용
네 사실 이것이 이번 강의 주제입니다.
스마트 포인터를 거치면 기존의 타언어(C#, Java)처럼 메모리 해제라는 짐을 덜어줍니다.

## 스마트 포인터
이 스마트 포인터는 <memory>헤더에 정의되어 있습니다.

스마트 포인터를 왜 쓰는가?

- error handling path가 여럿이라도 자원 관리가 편합니다.
- 자원을 해제하는 주체가 명확하지 않을 경우에도 사용이 편리합니다.
- 여러 custom memory allocator를 이용할 경우에, 객체를 사용하는 주체가 어떤 할당자를 사용하여 해제해야하는지 알 필요가 없습니다.

#### auto_ptr
기존의 포인터가 있지만 C++03부터 auto_ptr이라는 스마트 포인터가 등장했습니다.

하지만 C++14부터 3가지의 타입이 추가되었고, 이제는 auto_ptr은 거의 사용하지 않습니다.

## shared_ptr
```C++
shared_ptr<Type> mySmartPtr (new Type);
```

선언 방식은 위와 같습니다. 

shared_ptr을 사용하기 위해서는 참조 카운트의 개념을 알아야 합니다. 

참조 카운트는 해당 메모리를 참조하는 포인터가 몇개인지 나타내는 값입니다. 

shared_ptr로 선언된 포인터가 가리키는 메모리 공간은 참조 카운트가 0이 되는 순간 메모리를 해제하는 것입니다.
```C++
#include <iostream>
#include <memory>
using namespace std;
 
int main()
{
    shared_ptr<int> s_ptr(new int);         // 참조 카운트 1
    *s_ptr = 10;
    cout << "참조 카운트 1" << endl;
    cout << *s_ptr << endl;
 
    shared_ptr<int> temp_1 = s_ptr;              // 참조 카운트 2
    *temp_1 += 1;                            // 11로 증가
 
    cout << "참조 카운트 2" << endl;
    cout << *s_ptr << endl;                 // 증가된 값인 11 출력
    cout << *temp_1 << endl;
 
    shared_ptr<int> temp_2 = temp_1;              // 참조 카운트 3
    cout << "참조 카운트 3" << endl;
    *temp_2 += 1;
 
    cout << *s_ptr << endl;                 // 증가된 값인 12 출력
    cout << *temp_1 << endl;
    cout << *temp_2 << endl;
 
    return 0;
}
```
> 참조 카운트 1
> 10
> 참조 카운트 2
> 11
> 11
> 참조 카운트 3
> 12
> 12
> 12