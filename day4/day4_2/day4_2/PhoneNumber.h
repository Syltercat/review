#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>
using namespace std;

class PhoneNumber {
	// ** <<�� >> �����ڴ� ���� �Լ��� ����Ǿ�� �ϱ� ������ friend ����� �ۼ��Ѵ�.
	
	// cout << a << b;�� a�� b�� ���������� ��µǱ� ������ �̸� �����ϱ� ����(�޼��� ü�̴�)
	// ostream& �� return type�� ������.
	friend ostream& operator<<(ostream&, const PhoneNumber&);
	friend istream& operator>>(istream&, PhoneNumber&);

private:
	string areaCode;
	string exchange;
	string line;
};

#endif // !PHONENUMBER_H
