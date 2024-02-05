// friend 
/*
Class scope �ܺο� ���ǵǾ class�� ���(public, private)�� ������ �� �ֵ��� ��.
�ַ� ������ �����ε��� ���� ���
friendship�� �Ϲ����̰� ���̵��� �ʱ� ������ A->B friend���� B->A�� friend�� �ƴϰ�,
A->B->C���� A->C�� �ȵȴ�.
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
	friend void setx(Count&, int); // �̷��� friend��� ��� �ؾ���. �׷��� class ����� �ƹ������� �ص� ��� ����.

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