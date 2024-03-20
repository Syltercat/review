#pragma once
#include <iostream>

using namespace std;

class Mycar {
public:
	Mycar(string); //»ý¼ºÀÚ
	void set_name(string);
	string get_name();
	void accel();
	void car_break();
	void set_fuel(double);
	double get_fuel();
	int get_speed();
	void state();

private:
	string car_name;
	double car_fuel = 100;
	int max_speed = 200;
	int speed = 0;
};