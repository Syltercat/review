#include <iomanip>			// setw() 함수 사용을 위해 include, setw(x)는 x만큼 공간을 확보한 후 뒤부터 문자 수 만큼 출력하는 함수
#include "PhoneNumber.h"

using namespace std;

// ostream& output = 왼쪽 피연산자, const PhoneNumber& number = 오른쪽 피연산자
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
