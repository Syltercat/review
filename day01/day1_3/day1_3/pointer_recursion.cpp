// ������, ���
#include <iostream>
#include <stdio.h>
using namespace std;

// �迭 ����� - ��� ���
void reverse(char* a) {
    if (*a == 0) return;
    else {
        reverse(a + 1);
        cout << *a;
    }
}

// �ҹ��� -> �빮�� - ������, while ���
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