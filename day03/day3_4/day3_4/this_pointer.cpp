//this pointer
/*
��ü ������ �ڱ� �ڽ��� ����Ű�� ������

��� ��ü�� this �����͸� ���� �ڽ��� �ּҿ� ������ ����������
this �����Ͱ� ��ü �ڽ��� �Ϻδ� �ƴϴ�. (member value, class value �� �� �ƴ�)
this �����ʹ� �Ͻ������ε� ��������ε� ��� �����ϴ�.

Assignment operator overloading������ this �����Ͱ� �ݵ�� �ʿ��ϴ�.
1. �ڱ� ���� Ȯ���� ���� �ʿ�
MyClass& MyClass::operator=(const MyClass& rhs) {
    if (this == &rhs) // �ڱ� �ڽſ��� �Ҵ�Ǵ��� Ȯ��
        return *this; // �ڱ� �ڽ��� ��ȯ�Ͽ� �ƹ��� �۾��� �������� ����
    // ���� ���� ����
}

2.�޼��� ü�̴� ����
Class& Class::operator=(const Class& other) {
    if (this != &other) {
        // ���� ����
    }
    return *this; // ���� ��ü�� ������ ��ȯ
}

+) ���� �޼��带 ü��ó�� ������ ���� �޼��� ü�̴��ε� �Ʒ��� ���� ������ �����ϴ�.
obj.setA(a);
obj.setB(b);
obj.setC(c); �� �ڵ带 �Ʒ��� ���� ��ȯ ����

obj.setA(a).setB(b).setC(c);

�׷��� ���⼭ set�� ��ü �ڽ��� ��ȯ�ؾ� �Ѵ�.
C++������ ������ ���� �����Ѵ�.
class MyClass {
public:
    MyClass& setA(TypeA a) {
        // A ����
        return *this;
    }
    MyClass& setB(TypeB b) {
        // B ����
        return *this;
    }
    MyClass& setC(TypeC c) {
        // C ����
        return *this;
    }
};

Assignment operator overloading������ this pointer�� �����
�޼��� ü�̴��� ���� �ڵ��� �ۼ��� �����ϰ� �Ѵ�.

a = b = c;

���⼭�� b=c�� ���� ����ǰ� �� ����� a�� �����Ѵ�. 

3. ��ü ���� ����
���� ������(=)�� �����ε��ϴ� �ָ����� �� ��ü�� ���¸� �ٸ� ��ü�� �����ϴ� ������
����� �����ϴ� ���ε� �̿� this pointer�� �ٽ����� ������ �Ѵ�.

������ �����ε��� ���� �ڼ��� ������ ���� �ٷ� ���̴�.
*/

#include <iostream>
using namespace std;

class Test {
public:
    Test(int = 0);
    void print()const;
private:
    int x;
};

Test::Test(int value): x(value) {

}

void Test::print()const {
    // (*this). = this->
    cout << "       x = " << x;
    cout << endl << "this->x = " << this->x;
    cout << endl << "(*this).x = " << (*this).x;
}

int main() {
    Test t(12);
    t.print();
    return 0;
}