// operator overloading 심화 - array에 적용

/*
c++ 배열의 단점
1. 배열의 범위를 체크하지 않는다.
2. == 연산자로 두 배열을 비교할 수 없다. 
   (a와 b 배열은 각각 배열의 값이 아닌 배열의 주소를 나타내기 때문에 ==로 비교하면 무조건 거짓으로 나온다.)
3. 대입 연산자로 다른 배열로 대입될 수 없다.
   (배열 이름은 const pointer(변하지 않는 할당받은 메모리 주소)이기 때문에 다른 값으로 바꿀 수 없다.)
4. 배열이 함수로 전달될 경우 배열의 크기도 인수로 전달 되어야 한다.

이를 개선하기 위해 연산자 오버로딩을 할 것이다.

1. 범위 체크가 가능하게 할 것
2. 한 배열을 다른 배열에 대입할 수 있도록 한다.
3. 별도의 인수로 배열의 크기를 넘길 필요가 없도록 한다.
4. 배열 전체를 <<와 >>를 이용하여 입출력할 수 있도록 한다.
5. ==와 !=를 통한 배열 비교가 가능하도록 한다.

Array class 복사 생성자 주의
- 반드시 defualt 복사 생성자를 사용하지 말고, 새롭게 복사 생성자를 만들어 Array(const Array&);처럼 참조(&)를 사용해햐 한다.
  &를 사용하지 않으면 인수는 값으로 전달되어 매개변수 객체가 생성되고
  다시 매개변수 객체 생성을 위해 복사 생성자를 호출하며 또 다시 값으로 전달되어 복사 생성자를 호출하는 무한 루프를 돈다.
  (passed by value가 원본의 변경 없이 값을 복사해서 전달하기 때문에 이 값을 복사하는 과정에서 다시 복사 생성자를 불러오기 때문에 무한 루프를 도는 것이다.)
*/

#include <iostream>
#include "Array.h"

using namespace std;

int main() {
	Array a1(7);
	Array a2;

	cout << "a1 size: " << a1.getsize() << endl;
	cout << "a2 size: " << a2.getsize() << endl;

	cout << "enter a1 and a2 17 int: \n";
	cin >> a1 >> a2;

	cout << "a1: \n" << a1 << "a2: \n" << a2;

	if (a1 != a2) {
		cout << "not equal.\n";
	}

	Array a3(a1);
	cout << "a3 size: " << a3.getsize() << endl;

	a1 = a2;
	cout << "a1: \n" << a1 << "a2: \n" << a2;

	if (a1 == a2) {
		cout << "equal.\n";
	}

	cout << "a1[5]: " << a1[5] << endl;
	a1[5] = 1000;
	cout << "a1[5]: " << a1[5] << endl;

}