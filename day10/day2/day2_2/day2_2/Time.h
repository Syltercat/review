#pragma once
/*
ifndef: �ߺ� include �����ϱ� ���� ���� Ű���尡 ���ǵ��� �ʾ����� Ȯ���� ��
		�̹� ���ǵǾ� �ִٸ� endif���� �ڵ带 �����ϰ� �Ѿ

define: Ŭ���� ����
pragma once: �ɺ��� �ߺ� ���ǵǴ� �͵� ����
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


