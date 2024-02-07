//예외처리

// if-else 같은 로직 예외처리는 한계가 있다.

//try & chatch
/*
- try & chatch
	try(
		// 예외 발생 예상 부분
	}
	catch (처리되어야 하는 예외의 종류){
		// 예외를 처리하는 코드
	}

 => 사용
	try {
		if(예외 상황1)
			throw ex1;	// 예외 상황1 발생했으니 예외 전달
			...
		if(예외 상황2)
			throw ex2;
			...
	}
	catch (exception1 ex1) {
		// 예외 상황1을 처리하는 코드
	}
	catch (exception2 ex2) {
		// 예외 상황2을 처리하는 코드
	}

*/

#include <iostream>
using namespace std;

int divide(int a, int b);

int main() {
	int a = 0, b = 0;
	cout << "a, b insert: ";
	cin >> a >> b;

	try {
		cout << "a/b = " << divide(a, b) << endl;
	}
	catch (int ex) {
		cout << "입력한 값이 " << ex << endl;
		cout << "Error: 잘못된 입력\n";
	}
	// 여러 개의 catch 사용이 가능하다.
	return 0;
}

int divide(int a, int b) {
	if (b == 0)
		throw b;	// 예외 조건에 부합하는 경우 throw를 통해 예외 전달 catch로 전달
		//여기에 조건을 추가하면 하나의 try로 여러 개의 catch를 만들 수 있다.

	return a / b;
}