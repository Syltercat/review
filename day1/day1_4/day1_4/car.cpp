// class ����
/*
car class ����
car �̸� ���� ����
������ �극��ũ ���(+20, -10)
����� ������ ���� ��� 0.02%�� ����
���ᰡ 0�� �Ǹ� ������ ���� ����
*/
#include <iostream>
#include <stdio.h>
using namespace std;

class MyCar {
public:
    void set_name(string name) {
        car_name = name;
    }
    void dispaly_name() {
        cout << car_name << endl;
    }
    void accel() {
        if (car_fuel > 0) {
            if (speed < max_speed - 20) {
                speed = speed + 20;
                car_fuel = car_fuel-(car_fuel * 0.02);
            }
            else speed = 200;
            cout << speed << endl;
        }
        else {
            speed = 0;
            cout << speed << endl;
        }
    }
    void break_car() {
        if (speed > 10) {
            speed = speed - 10;
        }
        else speed = 0;
        cout << speed << endl;
    }
    void set_fuel(int fuel) {
        car_fuel = fuel;
    }
    void current_car() {
        cout << car_name << endl;
        cout << car_fuel << endl;
        cout << speed << endl;
    }
private:
    string car_name;
    int max_speed = 200;
    double car_fuel = 100;
    int speed = 100;
};

int main() {
    MyCar car;
    car.set_name("mycar");
    car.dispaly_name();
    car.set_fuel(200);
    car.accel();
    car.accel();
    car.accel();
    car.current_car();
    car.break_car();
    car.current_car();
}