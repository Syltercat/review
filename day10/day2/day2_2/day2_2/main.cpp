//constructor_destructor

#include <iostream>
#include "Time.h"
using namespace std;

int main() {
	Time t(16, 24, 55);
	t.printStandard();
	t.printUniversal();
}