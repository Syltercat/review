// 반복문 연습, 계산기
#include <iostream>
#include <stdio.h>
using namespace std;

int F(int n) {
    int x;
    if (n == 1) return 1;
    else return n * F(n - 1);
}

void Myf(int n) {
    if (n == 0)
        cout << "bad.";
    else if (n == 1)
        cout << "soso.";
    else cout << "good.";
}

void Myc() {
    cout << " 0 종료." << endl;
    cout << " 1 사칙연산" << endl;
    cout << " 2 factorial" << endl;

    int mode = -1;
    while (1) {
        cout << "Mode: ";
        cin >> mode;
        if (mode == 0) {
            cout << "bye.\n";
            break;
        }
        else if (mode == 1) {
            int a = 0;
            int b = 0;
            cout << "insert a and b." << endl;
            cout << "a: ";
            cin >> a;
            cout << "\n b: ";
            cin >> b;
            int c = 0;
            int x = 0;
            cout << "select operator number.\n";
            cout << "1. +  2. -  3. *  4. /\n";
            cin >> c;
            if (c == 1) {
                x = a + b;
                cout << "output: " << x << endl;
            }
            else if (c == 2) {
                x = a - b;
                cout << "output: " << x << endl;
            }
            else if (c == 3) {
                x = a * b;
                cout << "output: " << x << endl;
            }
            else if (c == 4) {
                x = a / b;
                cout << "output: " << x << endl;
            }
            else {
                cout << "error.\n";
            }
        }
        else if (mode == 2) {
            int d = 0;
            cout << "insert d.\n";
            cin >> d;
            int x = 0;
            x = F(d);
            cout << "output: " << x << endl;
        }
    }
}


int main() {
    int score = 2;
    if (score == 0) {
        cout << "bad.";
    }
    else if (score == 1) {
        cout << "soso";
    }
    else cout << "good";

    Myf(score);

    Myc();
}
