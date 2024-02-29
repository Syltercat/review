// class 생성
/*
car class 생성
car 이름 변경 가능
엑셀과 브레이크 기능(+20, -10)
연료는 엑셀을 밟을 경우 0.02%씩 감소
연료가 0이 되면 앞으로 가지 않음
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