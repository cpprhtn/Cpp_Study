# reference
반갑습니다. Cppbhtn입니다.

C++에서 등장했으며, 포인터와 비슷하게 생긴 `레퍼런스`라는 것을 알아봅시다.

이것 역시 포인터처럼 주소값을 가지는데, 유사하면서도 많은 차이점이 있다.

### 레퍼런스 선언
> &변수명 = 다른변수


반드시 처음에 초기화해야 하며(다른 변수를 가리키게 함)
그 이후는 자신이 가리키는 변수를 바꿀 수 없다.

NULL값으로 레퍼런스를 초기화할 수 없다.

레퍼런스가 어떤 변수에 새로운 이름을 부여한다고 생각하면 된다.

```C++
#include <cstdio>

int main()
{   
    int a = 1;
    int &b = a;

    printf("%d %d\n", a, b); // 1 1
    printf("%p %p\n", &a, &b); // 006AD1F8 006AD1F8

    int c(3);
    &b = c; // Error
    int &d = '\0' // Error

    return 0;
}
```
위에선 a라는 변수에 b이라는 새로운 이름을 부여한 것을 볼 수 있다.


### 레퍼런스와 포인터의 차이점

레퍼런스는 반드시 처음에 초기화해야 하며, 다시는 가리키는 주소를 못 바꾸고, 배열을 만들 수 없다.

포인터는 값 자체에 접근하려면 *를 붙여야 하지만 레퍼런스는 그러지 않아도 된다.



### 예상해보기
아래 코드의 결과를 예상해봅시다.
```C++
#include <cstdio>

int main()
{
    int n = 1;
    int &m = n;

    printf("%d %d\n", n, m);

    n = 7;
    printf("%d %d\n", n, m);

    m = 9;
    printf("%d %d\n", n, m);

    return 0;
}
```


아래 코드를 보면서 C언어의 포인터보다 레퍼런스를 사용하면 가독성이 높아지는 것을 알 수 있습니다.
```C
#include <stdio.h>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int x = 1, y = 2;

    swap(&x, &y);
    printf("%d %d\n",x, y);

    return 0;
}
```

```C++
#include <cstdio>

void swap(int &p, int &q)
{
    int temp;
    temp = p;
    p = q;
    q = temp;
}

int main()
{
    int x(1), y(2);

    swap(x, y);
    printf("%d %d\n",x, y);

    return 0;
}
```


아래와 같이 400byte 크기의 구조체가 있다고 합시다.
이때 sum()이라는 함수에서 매개변수로 이 구조체를 호출한다면
호출할때마다 400byte크기의 값이 복사될 것이다.

이 문제를 해결하기 위해서 포인터를 사용한다면 두번째 예제처럼 코드를 바꿀 수 있습니다.
이때는 매개변수만 포인터로 바뀌었지만, 매개변수의 주소값만 넘겨주므로 포인터의 크기인 4byte만 사용하게 됩니다.

세번째 코드에서는 레퍼런스를 사용하여 구현한 것입니다.
레퍼런스 역시 4byte를 사용하지만, 포인터보다 가독성이 더 높은 것을 알 수 있습니다.

```C
#include <stdio.h>

typedef struct arr100
{
    int arr[100];
}Arr100;

int sum(Arr100 temp)
{
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += temp.arr[i];
    }

    return sum;
}

int main()
{
    Arr A;
    int Sum = sum(A);

    return 0;
}
```


```C
#include <stdio.h>

typedef struct arr100
{
    int arr[100];
}Arr100;

int sum(Arr100 *temp)
{
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += temp -> arr[i];
    }

    return sum;
}

int main()
{
    Arr A;
    int Sum = sum(&A);

    return 0;
}
```

```C++
#include <cstdio>

typedef struct arr100
{
    int arr[100];
}Arr100;

int sum(Arr100 &temp)
{
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += temp.arr[i];
    }

    return sum;
}

int main()
{
    Arr A;
    int Sum = sum(A);

    return 0;
}
```