#pragma once
#ifndef INIT_H
#define INIT_H
class Init {
public:
	Init(int c = 0, int i = 1);
	void addInit() {
		count += increment;
	}
	void print()const;
private:
	int count;
	const int increment;
};
#endif // !INIT_H
