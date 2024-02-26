#pragma once
/*
ifndef: 중복 include 방지하기 위해 뒤의 키워드가 정의되지 않았음을 확인한 후
		이미 정의되어 있다면 endif까지 코드를 무시하고 넘어감

define: 클래스 정의
pragma once: 심볼이 중복 정의되는 것도 방지
*/

#ifndef TIME_H
#define TIME_H

class Time {
public:
	Time(int, int, int);	//constructor
	void setTime(int, int, int);
	void setHour(int);
	void setMin(int);
	void setSec(int);
	int getHour();
	int getMin();
	int getSec();
	void printUniversal();
	void printStandard();
	~Time();	//destructor
private:
	int hour;
	int min;
	int sec;
};

#endif // !TIME_H


