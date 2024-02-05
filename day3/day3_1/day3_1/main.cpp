#include <iostream>
#include "const_Initialization.h"

using namespace std;

int main() {
	Init value(10, 5);
	value.print();

	for (int i = 1; i <= 3; i++) {
		value.addInit();
		value.print();
	}
	return 0;
}