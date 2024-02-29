// doubly linked list ±¸Çö

#include <iostream>
#include "DLL.h"
using namespace std;

int main() {
	DLL myDLL1;
	cout << myDLL1.empty() << endl;
	myDLL1.addFront("A");
	myDLL1.addBack("B");
	myDLL1.addFront("C");
	myDLL1.addBack("D");
	cout << myDLL1.front() << endl;
	cout << myDLL1.back() << endl;

	myDLL1.removeFront();
	myDLL1.removeBack();
	cout << myDLL1.front() << endl;
	cout << myDLL1.back() << endl;

}