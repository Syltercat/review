// template ���
#include <stdio.h>
#include <iostream>
using namespace std;

// datatype�� ��� ���� �Լ� ����
template <class T>
T swapdata(T a, T b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << endl;
    cout << b << endl;
    return 0;
}

template <class T>
T distance(T a, T b) {
    T d;
    d = sqrt(pow(a, 2) + pow(b, 2));
    cout << d << endl;
    return 0;
}

// datatype ����ó��
template <>
char distance(char a, char b) {
    cout << "error\n";
    return 0;
}

int main() {
    distance(3, 4);
    swapdata(3, 4);
    distance('a', 'A');
    swapdata('a', 'A');
}