// 복합(has-a) 관계
//class가 다른 class의 객체를 멤버로 가지는 관계

#include <iostream>
#include "Employee.h"	// Employee 만 include
using namespace std;

int main() {
	Date birth(7, 24, 1994);
	Date hire(3, 12, 2020);
	Employee manager("A", "B", birth, hire);	// 여기

	cout << endl;
	manager.print();

	cout << endl;
	manager.print();

	cout << "\nTest Data constructor with invalid values\n";
	Date lastd(14, 52, 1994);
	cout << endl;
	return 0;
}

/*
코드를 실행시켜보면 AB를 한 번 생성했는데 Date의 생성자가 생일과 고용일에 맞게 두 번 실행된 후 Employee 생성자가 한 번 실행되었다.
그러나  Employee 소멸자는 짝에 맞춰 잘 실행된 반면, Date의 경우에는 생일과 고용일마다 각각 두 번의 소멸자가 실행된 것을 확인할 수 있었다.
이는 defalut 생성자가 한 번 실행되었기 때문이다.
main.cpp의 11번 줄에서 birth와 hire를 인자로 받아오면서 default 복사 생성자가 불려졌기 때문에
처음에 출력된 Date 소멸자는 이 default 생성자에 대하여 실행된 것이고
그 후의 소멸자는 처음 Date의 생성자로 인해 불려온 것이다.
따라서 Date 소멸자는 두 번 불려진다.
*/