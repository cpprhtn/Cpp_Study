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

포인터는 get() 멤버 함수로 얻을 수 있고, reset() 멤버 함수를 통해서 메모리 해제를 할수 있습니다.

스마트 포인터를 왜 쓰는가?

- error handling path가 여럿이라도 자원 관리가 편합니다.
- 자원을 해제하는 주체가 명확하지 않을 경우에도 사용이 편리합니다.
- 여러 custom memory allocator를 이용할 경우에, 객체를 사용하는 주체가 어떤 할당자를 사용하여 해제해야하는지 알 필요가 없습니다.

### 참조 카운트(reference count)?
참조 카운트: 해당 메모리를 참조하는 포인터가 몇개인지 나타내는 값을 의미

#### auto_ptr
기존의 포인터가 있지만 C++03부터 auto_ptr이라는 스마트 포인터가 등장했습니다.

하지만 C++14부터 3가지의 타입이 추가되었고, 이제는 auto_ptr은 거의 사용하지 않습니다.

## shared_ptr

```C++
std::shared_ptr<Type> s_ptr (new Type);
```
선언 방식은 위와 같습니다. 

std::shared_ptr 객체가 복사되어도 메모리 공간은 늘어나지 않습니다.

shared_ptr로 선언된 포인터가 가리키는 메모리 공간은 참조 카운트가 0이 되는 순간 메모리를 해제하는 것입니다.

shared_ptr 객체 하나가 소멸되더라도, 동일한 메모리 주소를 참조하고 있는 다른 shared_ptr 객체가 있으면 참조하고 있던 메모리 주소의 객체는 소멸되지 않습니다.

shared_ptr에서는 순환참조가 일어날 수 있습니다.

* 순환참조: 참조 카운트가 0이 되지 않아 메모리 해제가 되지 않는 상황
- 예시: A와 B가 서로에 대한 shared_ptr을 들고 있으면 참조 카운트가 0이 되지 않아 메모리가 해제되지 않는 경우


```C++
#include <iostream>
#include <memory>
using namespace std;
 
int main()
{
    shared_ptr<int> s_ptr(new int);         // 참조 카운트 1
    *s_ptr = 10;
    cout << "reference count: " << s_ptr.use_count() << endl;
    cout << *s_ptr << endl;
 
    shared_ptr<int> temp_1 = s_ptr;              // 참조 카운트 2
    *temp_1 += 1;                            // 11로 증가
 
    cout << "reference count: " << s_ptr.use_count() << endl;
    cout << *s_ptr << endl;                 // 증가된 값인 11 출력
    cout << *temp_1 << endl;
 
    shared_ptr<int> temp_2 = temp_1;              // 참조 카운트 3
    cout << "reference count: " << s_ptr.use_count() << endl;
    *temp_2 += 1;
 
    cout << *s_ptr << endl;                 // 증가된 값인 12 출력
    cout << *temp_1 << endl;
    cout << *temp_2 << endl;

    s_ptr.reset() //메모리 해제
   
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
main() 함수를 종료하게 되면 참조 카운트가 0이 되어서 자동으로 메모리 공간이 해제됩니다.
참조된 값에 따라 카운트는 늘어나고 참조된 값을 변형하면 그 값에 따라 모두 값이 변합니다.



## unique_ptr

```C++
std::unique_ptr<Type> u_ptr(new Type);
```
선언 방식은 위와 같습니다. 

unique_ptr은 참조한 데이터의 고유 소유권을 나타냅니다.

장점으론 기존 포인터에 비해 시간과 메모리에 대한 오버헤드가 없다는 것입니다.

unique_ptr이 shared_ptr과 다른 점은 참조 카운트가 1을 넘을 수 없는 것입니다.

또한 복사는 불가능한 대신에, `move()`를 이용하여 이동이 가능합니다.

```C++
std::unique_ptr<int> u_ptr(new int); // 참조 카운트 1
std::unique_ptr<int> temp_1 = u_ptr;   // 에러 발생
```
위 처럼 두 군데 이상의 포인터가 하나의 메모리 공간을 가리킨다면 컴파일 에러가 발생합니다.

* unique_ptr의 기능으로 사용자정의 Deleter를 제공하는 기능이 있습니다. (구글링/설명생략)

```C++
#include <iostream>
#include <memory>
using namespace std;

int main() 
{
    unique_ptr<int> u_ptr(new int);
    
    // auto temp = u_ptr; // 복사 X
    auto temp = move(u_ptr); // temp로 이동
    
    cout << u_ptr.get() << endl; // null_ptr가 되기 때문에 0 출력
    cout << temp.get() << endl;
    
    u_ptr.reset(); // 이미 이동되었기 때문에 동작 X
    temp.reset(); // 메모리 해제
    
    return 0;
}
```
> 0x0

> 0x7fee80c05830

포인터는 복사할 수 없지만, 포인터가 가리키는 객체는 복사할 수 있습니다.
```C++
#include <iostream>
#include <memory>
using namespace std;

int main() 
{
    unique_ptr<int> u_ptr(new int(5));
    
    auto temp = *u_ptr;
    auto& _refer = u_ptr;
    
    // 포인터 출력
    cout << u_ptr.get() << endl;
    cout << &temp << endl; 
    cout << _refer.get() << endl; 
    
    // 객체 출력
    cout << *u_ptr << endl;
    cout << temp << endl;
    cout << *_refer << endl;
    
    return 0;
}
```
> 0x7fa1d4c05830

> 0x7ffeed22c88c

> 0x7fa1d4c05830

> 5

> 5

> 5


## weak_ptr

```C++
std::weak_ptr<Type> w_ptr = s_ptr;
{
    // 참조한 객체 사용
}
// w_ptr 소멸
```
선언 방식은 위와 같습니다.

weak_ptr는 shared_ptr의 객체를 참조하지만, shared_ptr의 참조 카운트를 올리지 않는 것입니다.

std::weak_ptr은 포인터에 직접 접근을 할 수 없기 때문에 lock() 멤버 함수로 std::shared_ptr 객체를 생성한 다음 그 객체를 통해서 포인터에 접근해야 합니다.

이 weak::lock()을 통해서 shared_ptr의 순환참조 문제를 해결할 수 있습니다.

```C++
// shared 참조 카운트 -> s_cnt
// weak 참조 카운트 -> w_cnt
#include <iostream>
#include <memory>
using namespace std;
 
int main()
{
    shared_ptr<int> s_ptr(new int);
 
    // weak_ptr가 s_ptr으로부터 복사 생성 (참조)
    weak_ptr<int> w_ptr = s_ptr; // s_cnt = 1, w_cnt = 1
    {
        // w_ptr가 참조하고 있던 s_ptr를 weak_ptr::lock 메서드를 이용해 s_ptr_2가 참조
        shared_ptr<int> s_ptr_2 = w_ptr.lock(); // s_cnt = 2, w_cnt = 1
        if (s_ptr_2)
        {

        }
        // s_ptr_2 소멸
        // s_cnt = 1, w_cnt = 1
    }
    // w_ptr 소멸

    s_ptr.reset(); // s_ptr
 
    return 0;
}
```