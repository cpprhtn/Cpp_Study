# dynamic allocating
반갑습니다. Cpprhtn입니다.

저번 강의에서는 생성자와 소멸자에 대해 다루었습니다.

이번에는 동적 할당에 대한 설명을 하겠습니다.

### 동적 할당(dynamic allocation)

[동적 메모리 할당 - 위키백과](https://ko.wikipedia.org/wiki/%EB%8F%99%EC%A0%81_%EB%A9%94%EB%AA%A8%EB%A6%AC_%ED%95%A0%EB%8B%B9) 참고

동적 할당은 실행 시간 동안 사용할 메모리 공간을 할당하는 것을 의미합니다

C언어에서는 malloc(), free()함수를 사용했었습니다.

C++에서도 malloc(), free()함수를 사용하여 메모리의 동적 할당 및 해제를 할 수 있습니다.

하지만 C++에서는 메모리의 동적 할당 및 해제를 위한 더욱 효과적인 방법을 new와 delete 연산자를 통해 제공합니다.

 new와 delete 연산자는 내부적으로 malloc()과 free()와 유사한 함수를 사용하여 메모리 맵상의 힙영역으로부터 저장공간을 할당합니다.