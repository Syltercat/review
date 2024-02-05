#pragma once
#include <string>
using namespace std;

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy {
public:
	CreateAndDestroy(int, string);
	~CreateAndDestroy();
private:
	int Id;
	string message;
};

#endif // !CREATE_H
