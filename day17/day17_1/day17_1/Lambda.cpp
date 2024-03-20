#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ���ٽ�(Lambda)
/*
������ boost��� ���̺귯������ �����ϴ� �Լ������� modern c++�� �Ѿ���鼭 �� ����� �⺻������ �����ϰ� �Ǿ���.

< ���� ������ �ʿ��� ���� >
�Լ� ��ü�� �Լ� �������� �������� ������ �ֱ� �����̴�.
- �Լ� ������: �Լ��� �ּҰ��� ���� �� �ִ� ������ ����, callback�� ���� �Լ� �����͸� ����Ѵ�. (�ڵ忡 �������� �ο��� �� �ְ�, �ڵ��� ���̸� ���� �� �־ ���)
- �Լ� ��ü: ��ü�� �����Ͽ� �Լ�ó�� ����ϴ� ��, ������ ȿ������ ���� ����Ѵ�. (�ٸ� inline�� ������ ����ũ�Ⱑ �þ�ٴ� ���� �ڵ� ���̰� �ʹ� ����� �� �ִٴ� ������ �ִ�.)

�Լ� ��ü�ʹ� �ٸ��� class�� ������ �ʿ䰡 ������(�ڵ� ���̰� �پ���.)
inlineȭ�� �Ұ����� �Լ� �����Ϳʹ� �ٸ��� inlineȭ�� �����ϴ�.
(��, ��Ȯ�� ��õǾ� �ִ� ���� �Լ��� �ζ���ȭ�� �����ϴ�.)

�� �˾ƾ��ϴ� ���� ���ٴ� �̸��� ������ ������ ��ü��� ���̴�.
*/

// ���ٽ��� ������� ���� �ڵ�

// ���� ������ ��� ���� ����ϴ� �ڵ��� �⺻ ������ �Ʒ��� ����.
//int main() {
//	vector<int> cardinal(5);
//	cardinal.push_back(1);
//	cardinal.push_back(2);
//	cardinal.push_back(3);
//	cardinal.push_back(4);
//	cardinal.push_back(5);
//	vector<int>::const_iterator iter = cardinal.begin();
//	vector<int>::const_iterator iter_end = cardinal.end();
//	int total_elements = 1;
//	while (iter != iter_end) {
//		total_elements *= *iter;
//		++iter;
//	}
//}

// �ٸ� ������δ� Functor�� �̿��Ͽ� �ڵ带 ���� �� �ִ�.
//template <typename T>
//struct product {
//	product(T& storage) : value(storage) {}
//	template <typename V>
//	void operator()(V& v) {
//		value *= v;
//	}
//	T& value;
//};
//
//int main(){
//	vector<int> cardinal(5);
//	cardinal.push_back(1);
//	cardinal.push_back(2);
//	cardinal.push_back(3);
//	cardinal.push_back(4);
//	cardinal.push_back(5);
//	int total_elements = 1;
//	for_each(cardinal.begin(), cardinal.end(), product<int>(total_elements));
//}

// ���ٽ��� ����� �ڵ�

//int main() {
//	vector<int> cardinal(5);
//	cardinal.push_back(1);
//	cardinal.push_back(2);
//	cardinal.push_back(3);
//	cardinal.push_back(4);
//	cardinal.push_back(5);
//	int total_elements = 1;
//	for_each(cardinal.begin(), cardinal.end(), [&total_elements](int i) {total_elements *= i; });
//}

// ª�� �����ϸ� while���̳� Functor���� �ڵ� ���� ����ϰ� �ۼ� �����ϴ�.

// ���� ����
/*
���ٴ� 4���� �κ����� �����Ǿ� �ִ�.
[������] (����) ->��ȯŸ�� {�Լ��� ����}
[introducer] (parameters) ->return type {statement}
*/

// 1) []
/*
[]: �����ڷ�, �� �ȿ� � �ܺ� ������ �� ������ ���� �Լ��� �̸� ĸ���ؼ� �� ������ ���� ���ο��� ����� �� �ְ�����.

< Capture >
* [=]: ��� �ܺ� ���� ����
* [&]: ��� �ܺ� ���� ����
* [this]: �ش� Ŭ������ ���� ���� ����
* [*this]: �ش� Ŭ������ ���� ���� ����
* [=, &x, &y] or [&, x, y]: �ܺ��� ��� �������� ��/���۷����� ��������, x�� y�� ���۷���/������ �����´�.
* [x, &y, &z]: ������ �������� ������ �ٿ� ���� �����´�.


(1) [=]
- �⺻������ capture ������ '='���� �ܺ� ������ �������� const���·� �б⸸ �����ϴ�.

int main(){
   int x = 10;
   auto l2 = [=, x = x + 1](){
       cout << "l2�Լ��� x�� �ּ� �� : " << &x << endl;
       return x * x;
   };
   cout << "l2 = " << l2() << endl;     // 121
   cout << "x = " << x << endl;         // 10
   cout << "main�Լ��� x �ּ� �� : " << &x << endl;
   // �� �� x�� �ּҰ��� �ٸ�
}

�� �ڵ忡�� ���� x�� ����Ű�� ���� �ٸ���
ù ��° x: ���ٿ��� ���� ���ǵ� ����
�� ��° x: �ܺ� ����(main�� x ����)
�� ��°, �� ��° x: ���ٿ��� ���� ���ǵ� ���� (ù ��°�� ����)

�̷������� x�� ���� ����� ������ �ܺκ����� �� ��° x�� �����Լ� ���ο����� ���̻� ����� �Ұ��ϴ�.

�� �ڵ�� 2���� ����� �� �� �ִ�.
1. ���ٿ��� ����� ������ ���α׷��� ���� ������ ������ ������� �ʴ´�.
2. �ܺ� ������ ���� ���� �̸����� �ʱ�ȭ �Ѵٸ� �ش� �ܺ� ������ ���� ���ο��� ������ �ʴ´�.

����, Capture ��Ͽ��� �ʱ�ȭ�� ������ const�� ����Ǿ� ������ �Ұ��ϴ�.

(2) [&]
�ܺ��� ���� ���� ���·� �޾ƿ��� ������ '='�����ڿʹ� �ٸ��� �ܺ� ���� ���� ������ �� �ִ�.

int main() {
    int x = 10;

    auto l1 = [&](){
        // �ܺ� ������ x���� 5�� �������ش�.
        x = 5;
        return x;
    };

    auto l2 = [&, x = x + 100](){
        return x;
    };

    cout << l1() << endl;                   // 5
    cout << "main  x  : " << x << endl;     // 5
    cout << l2() << endl;                   // 110
    cout << "main  x  : " << x << endl;     // 5
}

�� �ڵ��� I1������ ���ٿ��� �ܺ� ���� x�� ���� 5�� �� ��������־���.
�׷���, I2������ x = x+100�� 105�� �ƴ϶� 110�� ���� Ȯ���� �� �ִ�.

=> ���� �Ұ�ȣ �κ��� ���� ������ �׷���. (���� �κ��� ����)

*/

// 2) ()