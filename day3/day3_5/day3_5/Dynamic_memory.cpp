// 동적 메모리 할당
/*
동적으로 메모리를 할당하고 해제할 수 있는 기능
new와 delete 연산자로 이루어짐
heap에 저장

new 연산자
ex) int *a = new int;
포인터를 반환한다. (c언어의 malloc())

delete 연산자
ex) delete a;
동적 할당된 객체를 소멸시킨다.
그 후 객체에 대한 메모리 공간을 해제한다. (c언어의 free와 유사)

new는 동적 배열도 할당 가능하다.
*/

#include <iostream>
using namespace std;

#pragma region Time.h
class Time {
public:
	Time(int = 0, int = 0, int = 0);
	void setTime(int, int, int);
	void sethour(int);
	void setmin(int);
	void setsec(int);
	int gethour()const;
	int getmin()const;
	int getsec()const;
	void print() const;
	~Time();
private:
	int hour;
	int min;
	int sec;
	static int count;	// 몇번째 객체인지 표현
};
#pragma endregion

#pragma region Time.cpp
int Time::count = 0;	//static 여기서 초기화

Time::Time(int a, int b, int c) {
	setTime(a, b, c);
	count++;
	cout << count << "번째 Time class 생성" << endl;
}

void Time::sethour(int h) {
	if (h >= 0 && h <= 24) {
		hour = h;
	}
	else {
		hour = 1;
		cout << "invalid hour\n";
	}
}

void Time::setmin(int m) {
	if (m >= 0 && m <= 59) {
		min = m;
	}
	else {
		min = 1;
		cout << "invalid min\n";
	}
}

void Time::setsec(int s) {
	if (s >= 0 && s <= 59) {
		sec = s;
	}
	else {
		sec = 1;
		cout << "invalid sec\n";
	}
}


void Time::setTime(int h, int m, int s) {
	sethour(h);
	setmin(m);
	setsec(s);
}

int Time::gethour()const {
	return hour;
}

int Time::getmin()const {
	return min;
}

int Time::getsec()const {
	return sec;
}

void Time::print()const {
	cout << gethour() << " : " << getmin() << " : " << getsec() << " : ";
}

Time::~Time() {
	cout << count << "번째 Time class 소멸" << endl;
	count--;
}
#pragma endregion

#pragma region main.cpp
int main() {
	// initialize 2 Time class with Dynamic allocate
	Time* Time1 = new Time;
	Time* Time2 = new Time;

	//initialize Array type Time class with Dynamic allocate
	Time* Time3 = new Time[3];

	//delete Array type Time class
	delete[] Time3;		// 주의 동적 배열 delete할 때는 []까지 써주기
	
	//delete 2 Time class
	delete Time1;
	delete Time2;
}
#pragma endregion