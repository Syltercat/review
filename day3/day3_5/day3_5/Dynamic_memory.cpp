// ���� �޸� �Ҵ�
/*
�������� �޸𸮸� �Ҵ��ϰ� ������ �� �ִ� ���
new�� delete �����ڷ� �̷����
heap�� ����

new ������
ex) int *a = new int;
�����͸� ��ȯ�Ѵ�. (c����� malloc())

delete ������
ex) delete a;
���� �Ҵ�� ��ü�� �Ҹ��Ų��.
�� �� ��ü�� ���� �޸� ������ �����Ѵ�. (c����� free�� ����)

new�� ���� �迭�� �Ҵ� �����ϴ�.
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
	static int count;	// ���° ��ü���� ǥ��
};
#pragma endregion

#pragma region Time.cpp
int Time::count = 0;	//static ���⼭ �ʱ�ȭ

Time::Time(int a, int b, int c) {
	setTime(a, b, c);
	count++;
	cout << count << "��° Time class ����" << endl;
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
	cout << count << "��° Time class �Ҹ�" << endl;
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
	delete[] Time3;		// ���� ���� �迭 delete�� ���� []���� ���ֱ�
	
	//delete 2 Time class
	delete Time1;
	delete Time2;
}
#pragma endregion