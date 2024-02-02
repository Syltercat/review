#include <iostream>
#include <string>
#include "Mycar.h"
using namespace std;

Mycar::Mycar(string name) {
	set_name(name);
}

void Mycar::set_name(string name) {
	car_name = name;
}

string Mycar::get_name() {
	return car_name;
}

void Mycar::accel() {
	if (car_fuel <= 0) {
		speed = 0;
		car_fuel = 0;
	}
	else {
		if (speed < max_speed - 20) {
			speed = speed + 20;
			car_fuel = car_fuel - (car_fuel * 0.02);
		}
		else {
			speed = max_speed;
			car_fuel = car_fuel - (car_fuel * 0.02);
		}
	}
	cout << "speed: " << speed << endl;
}

void Mycar::car_break() {
	if (speed > 10) {
		speed = speed - 10;
	}
	else {
		speed = 0;
	}
}

void Mycar::set_fuel(double f) {
	car_fuel = f;
}

double Mycar::get_fuel() {
	return car_fuel;
}

int Mycar::get_speed() {
	return speed;
}

void Mycar::state() {
	cout << "current_car_state" << endl;
	cout << "car_name: " << get_name() << endl;
	cout << "car_fuel: " << get_fuel() << endl;
	cout << "current_speed: " << get_speed() << endl;
}