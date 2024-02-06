#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>
using namespace std;

class PhoneNumber {
	// ** <<와 >> 연산자는 전역 함수로 선언되어야 하기 때문에 friend 관계로 작성한다.
	
	// cout << a << b;면 a와 b가 연속적으로 출력되기 때문에 이를 구현하기 위해(메서드 체이닝)
	// ostream& 의 return type을 가진다.
	friend ostream& operator<<(ostream&, const PhoneNumber&);
	friend istream& operator>>(istream&, PhoneNumber&);

private:
	string areaCode;
	string exchange;
	string line;
};

#endif // !PHONENUMBER_H
