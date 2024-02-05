// 생성자 소멸자
/*
객체의 생성과 소멸시 내부적으로 생성자와 소멸자는 자동 호출된다.

일반적으로 생성자의 호출 순서의 역순으로 소멸자가 호출된다.

객체가 전역 변수이면 main 함수 이전부터 생성되어 프로그램 수행 내내 살아있다가
main 함수가 종료된 후에 소멸자를 호출하여 소멸된다.

객체가 자동 지역 변수인 경우 객체를 정의할 때 생성자를 호출하여 생성된다.
그 후 객체가 포함된 scope를 벗어날 때 소멸자를 호출하여 소멸한다.

정적 지역 변수의 경우 단 한번 생성되어 프로그램 수행 내내 살아있다.
생성자는 객체가 처음 생성될 때 단 한번 호출되며 main 함수가 종료되면 소멸자를 호출하여 소멸한다.

*/

#include <iostream>
#include "Createanddestroy.h"

using namespace std;

void create(void);
CreateAndDestroy first(1, "(global before main)");				// 1. 전역변수

int main() {
	cout << "\nMain Function: Execution Begins" << endl;
	CreateAndDestroy second(2, "(local automatic in main)");	// 2. 자동 지역 변수
	static CreateAndDestroy third(3, "(local static in main)");	// 3. 정적 지역 변수

	create();													// 5. 자동 지역 변수, 6. 정적 지역변수, 7. 자동 지역 변수

	cout << "\Main Funtion: Excution Resumes" << endl;
	CreateAndDestroy fourth(4, "(local automatic in main)");	// 4. 자동 지역 변수
	cout << "\nMain Function: Excution Ends" << endl;
	return 0;
}

void create(void) {
	cout << "\Create Funtion: Excution Begins" << endl;
	CreateAndDestroy fifth(5, "(local( automatic in create)");
	static CreateAndDestroy sixth(6, "(local static in create)");
	CreateAndDestroy seventh(7, "(local automatic in create)");
	cout << "\nCreate Funtion: Excution Ends" << endl;
}

/*
생성자(n) 소멸자(~n) 호출 순서
1 -> (main 함수) -> 2 -> 3 -> (create 함수) -> 5 -> 6 -> 7 -> ~7 -> ~5 -> (create 함수 종료) -> 4 -> ~4 -> ~2 -> ~6 -> ~3 -> ~1

동적 변수가 먼저 사라지고 그 후 정적 변수가 사라지는 것에 유의
*/