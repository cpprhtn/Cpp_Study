#include <iostream>
#include "Array10.h"
using namespace std;

void Array10::set_arr(int *temp){
    for(int i=0; i<MAX; i++)
        arr[i] = temp[i];
}

void Array10::reverse(){
    for(int i=0; i<MAX/2; i++)
        swap(arr[i], arr[MAX-i-1]);
}

int Array10::get(int n){
    return arr[n];
}

void Array10::swap(int& a, int& b){ //레퍼런스 이용
    int temp = a;
    a = b;
    b = temp;
}