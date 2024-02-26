// day1_4의 코드를 변형, 헤더파일, 함수파일 분리
#include "Mycar.h"
#include <iostream>

int main() {
    cout << "create car." << endl;
    Mycar car("mycar1");
    car.set_name("mycar");
    car.get_name();
    cout << "car_fuel set 200." << endl;
    car.set_fuel(200);
    cout << "accel." << endl;
    car.accel();
    car.accel();
    car.accel();
    car.state();
    cout << "break." << endl;
    car.car_break();
    car.state();
    cout << "create car2." << endl;
    Mycar car2("mycar2");
    car2.state();
}