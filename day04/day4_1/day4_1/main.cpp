// static
/*
static data member
- 클래스의 모든 객체가 공유하는 변수의 복사본, "Class-wide" 정보
- 클래스의 특정한 객체 속성이 아니라 클래스 자체의 속성
- 전역 변수처럼 보일 수 있으나 class scope를 가짐

static member function
- static인 class member data와 function만 접근 가능
- this pointer를 갖지 않는다.
- static data member와 독립적으로 존재한다. (class의 객체가 존재하지 않아도, static 멤버 함수를 호출 할 수 있다.)
*/

#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
	Employee* e1ptr = new Employee("su", "ha");
	Employee* e2ptr = new Employee("A", "Bob");

	cout << "Number of Employee: " << e1ptr->getCount() << endl;
	// e2ptr->getCount() 도 가능
	
	cout << "1: " << e1ptr->getFirstName() << " " << e1ptr->getLastName() << endl;
	cout << "2: " << e2ptr->getFirstName() << " " << e2ptr->getLastName() << endl;

	delete e1ptr;
	e1ptr = 0;	 // 0 = null, e1ptr = pointer, 주소를 null값으로 함
	delete e2ptr;
	e2ptr = 0;

	cout << "count: " << Employee::getCount() << endl; // 여기서는 e1ptr이 null값이 되었으므로 Employee로 불러와야함.
	return 0;
}

#pragma region static 미사용
/*
count를 static 변수로 선언하지 않는다면 class 객체를 만들고 삭제할 때마다 count가 따로 생성되고 소멸되어서
제대로 count를 셀 수 없는 문제가 발생한다.
따라서 class 객체 모두에 적용되는 변수를 사용하고 싶다면 static을 붙여주어야 한다.
*/
#pragma endregion