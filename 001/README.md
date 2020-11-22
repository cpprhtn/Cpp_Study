## C++에서 추가된 기능

> C언어에서 가능했던 거의 모든 코드들을 C++에서도 사용이 가능합니다

1. 변수를 생성할때, 초기화하는 방법 추가
```C++
//C ver
int k = 1; 
float a = 3.14, b = 2.7;
 
//C++ ver
int k(1); 
float a(3.14), b(2.7);
```

2. bool type의 변수 사용가능

3. 형변환 방법 추가
```C++
#include <stdio.h>
int main()
{
    double d = 3.14;

    //C ver
    int n = (int)d;

    //C++ ver
    int n = static_cast<int>(d);

    return 0;
}