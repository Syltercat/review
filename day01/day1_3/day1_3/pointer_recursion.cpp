// 포인터, 재귀
#include <iostream>
#include <stdio.h>
using namespace std;

// 배열 역출력 - 재귀 사용
void reverse(char* a) {
    if (*a == 0) return;
    else {
        reverse(a + 1);
        cout << *a;
    }
}

// 소문자 -> 대문자 - 포인터, while 사용
void change(char* a) {
    while (*a) {
        if (*a >= 'a' && *a <= 'z') {
            *a = *a - 32;
        }
        else {
            a++;
            continue;
        }
        }
}

int main() {
    char arr1[30] = "ex1 display";
    reverse(arr1);
    change(arr1);
    cout << arr1;
}