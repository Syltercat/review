#include <iostream>
#include "const_Initialization.h"
using namespace std;

Init::Init(int c, int i) : count(c), increment(i) {	//초기화

}

void Init::print()const {
	cout << "count: " << count << ", increment: " << increment << endl;
}

#pragma region 잘못된 초기화 예시, member initializer
/*
Init::Init(int c, int i) {
	count = c;
	increment = i;	// ERROR: const로 고정된 값을 초기화 할 때는 member initializer를 이용해야 함.
}

class::constructor():member initializer { } 의 형태로 사용
member initializer 생성자의 body 보다 먼저 실행된다.
,로 복수의 데이터 member를 초기화 할 수 있다.
*/
#pragma endregion