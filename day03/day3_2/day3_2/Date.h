#pragma once
#ifndef DATA_H
#define DATA_H

class Date {
public:
	Date(int = 1, int = 1, int = 1900);
	void print() const;	// private의 값이 변하지 않도록 하기 위해 get과 관련된 함수는 const 사용
	~Date();

private:
	int month;
	int day;
	int year;
	int checkDay(int) const; // 내부적으로 쓸 멤버 함수라서 private에 선언
};
#endif // !DATA_H
