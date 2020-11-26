# pointer
반갑습니다. Cpprhtn입니다.

사실 포인터는 C++로 넘어오면서 레퍼런스와 혼동하여 쓰이기 쉽습니다.

그렇기에 둘의 차이를 확실하게 잡고 갈 생각입니다.



- 포인터 (Pointer)
포인터는 어떠한 값을 저장하는 게 아닌 메모리 주소를 저장하는 변수다.

### 포인터 선언

포인터 변수는 일반 변수처럼 선언되며, 자료형과 변수 이름 사이에 별표(*)가 붙는다.
> 자료형* 포인터 이름;
```C++
int* iPtr; // int형 포인터 
double* dPtr; // double형 포인터 
int* iPtr1, *iPtr2; // int형 두 개의 포인터 선언
//여러 포인터 변수를 선언하는 경우 별표가 각 변수에 포함되어야 함.
int* iPtr3, iPtr4;
//ptr3은 int형 포인터, ptr4는 단순한 int
```

### 포인터에 값 할당
포인터는 메모리 주소만 저장하므로, 포인터에 값을 할당할 때 그 값은 주소여야 한다. 
포인터로 하는 가장 흔한 작업은 다른 변수의 주소를 저장하는 것이다.

변수의 주소를 얻으려면 주소 연산자(&)를 사용한다.
> 포인터 = &변수;

```C++
int value = 5; int *ptr = &value; // 변수값의 주소로 ptr 초기화
```
ptr은 값으로 value 변수 값의 주소를 가지고 있다. 
그러므로 ptr을 value 변수를 '가리키는' 값이라고 할 수 있다.

```C++
#include <iostream> 
int main() 
{ 
    int value = 5; 
    int *ptr = &value; // 변수 값의 주소로 ptr 초기화 

    std::cout << &value << '\n'; // value 변수의 주소 출력 
    std::cout << ptr << '\n'; // ptr 변수 값 출력 

    return 0; 
}
```

포인터 변수의 자료형은 가리키는 변수의 자료형과 같아야 한다.
```C++
int iValue = 5; 
double dValue = 7.0; 
int *iPtr = &iValue; // O 
double *dPtr = &dValue; // O 
iPtr = &dValue; // X
dPtr = &iValue; // X
```

다음 사항도 올바르지 않다.
```C++
int *ptr = 5;
```
포인터가 주소만 보유할 수 있고 정수 리터럴 5에는 메모리 주소가 없기 때문이다. 
위 코드를 시도하면 컴파일러는 정수를 정수 포인터로 변환할 수 없으므로 오류가 발생한다.


C++에서는 포인터에 리터럴 메모리 주소를 직접 할당할 수 없다.
```C++
double *dPtr = 0x0012FF7C; // X
```



어떤 것을 가리키는 포인터 변수가 있다면, 역참조 연산자 *를 통해 포인터가 가리키는 주소의 값을 알 수 있다.
```C++
int value = 5; 
std::cout << &value; // value의 주소를 출력
std::cout << value; // value의 값을 출력

int *ptr = &value; // ptr은 value를 가리킴 
std::cout << ptr; // ptr이 가리키는 주소를 출력 (&value) 
std::cout << *ptr; // ptr을 역참조함. ptr이 가리키는 주소의 값을 출력 (value)
```

할당한 후에 포인터 값을 다른 값으로 재할당할 수 있다.
```C++
int value1 = 5; 
int value2 = 7; 
int *ptr; 

ptr = &value1; // value1의 주소를 가짐
std::cout << *ptr; // 5 출력

ptr = &value2; // value2의 주소를 가짐
std::cout << *ptr; // 7 출력
```

ptr은 &value 값과 같다.
*ptr은 value 값과 같다.

*ptr은 value와 같게 취급되므로 마치 변수값인 것처럼 갓을 할당할 수 있다.
```C++
int value = 5; 
int *ptr = &value; 
*ptr = 7; 
std::cout << value; // 7 출력
```