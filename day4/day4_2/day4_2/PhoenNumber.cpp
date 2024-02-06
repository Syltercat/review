#include <iomanip>			// setw() �Լ� ����� ���� include, setw(x)�� x��ŭ ������ Ȯ���� �� �ں��� ���� �� ��ŭ ����ϴ� �Լ�
#include "PhoneNumber.h"

using namespace std;

// ostream& output = ���� �ǿ�����, const PhoneNumber& number = ������ �ǿ�����
ostream& operator<<(ostream& output, const PhoneNumber& number) {
	output << "(" << number.areaCode << ")" << number.exchange << "-" << number.line;
	return output;
}

istream& operator>>(istream& input, PhoneNumber& number) {
	input.ignore();	// skip "("
	input >> setw(3) >> number.areaCode;
	input.ignore();			// skip ")"
	input >> setw(3) >> number.exchange;
	input.ignore();				// skip "-"
	input >> setw(4) >> number.line;
	return input;
}
