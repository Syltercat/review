#include <iostream>
#include "Createanddestroy.h"
using namespace std;

CreateAndDestroy::CreateAndDestroy(int a, string b) {
	Id = a;
	message = b;

	cout << "object ID: " << Id << "  constructor runs	" << message << endl;
}

CreateAndDestroy::~CreateAndDestroy() {
	cout << ((Id == 1 || Id == 6) ? "\n" : "");
	cout << "object Id: " << Id << "  destructor runs	" << message << endl;
}