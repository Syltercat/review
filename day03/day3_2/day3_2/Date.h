#pragma once
#ifndef DATA_H
#define DATA_H

class Date {
public:
	Date(int = 1, int = 1, int = 1900);
	void print() const;	// private�� ���� ������ �ʵ��� �ϱ� ���� get�� ���õ� �Լ��� const ���
	~Date();

private:
	int month;
	int day;
	int year;
	int checkDay(int) const; // ���������� �� ��� �Լ��� private�� ����
};
#endif // !DATA_H
