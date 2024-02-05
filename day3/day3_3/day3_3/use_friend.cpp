// friend 
/*
Class scope 외부에 정의되어도 class의 멤버(public, private)에 접근할 수 있도록 함.
주로 연산자 오버로딩을 위해 사용
friendship은 일방적이고 전이되지 않기 때문에 A->B friend여도 B->A는 friend가 아니고,
A->B->C여도 A->C는 안된다.
*/

#pragma region non_friend
/*
#include <iostream>
using namespace std;

class Count {
public:
	Count() : x(0) {}
	void print()const {
		cout << x << endl;
	}
private:
	int x;
};

void cannotSetx(count& c, int val) {
	c.x = val;
}

int main() {
	Count counter;
	cannotSetx(counter, 3);
	return 0;
}
*/
#pragma endregion

#pragma region friend
#include <iostream>
using namespace std;

class Count {
	friend void setx(Count&, int); // 이렇게 friend라고 명시 해야함. 그러나 class 내라면 아무곳에나 해도 상관 없음.

public:
	Count() : x(0) {}
	void print()const {
		cout << x << endl;
	}
private:
	int x;
};

void setx(Count&c, int val) {
	c.x = val;
}

int main() {
	Count counter;
	cout << "counter.x: ";
	counter.print();
	setx(counter, 3);
	cout << "counter.x after setx: ";
	counter.print();
	return 0;
}
#pragma endregion