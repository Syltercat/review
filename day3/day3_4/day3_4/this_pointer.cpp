//this pointer
/*
객체 내에서 자기 자신을 가리키는 포인터

모든 객체는 this 포인터를 통해 자신의 주소에 접근이 가능하지만
this 포인터가 객체 자신의 일부는 아니다. (member value, class value 둘 다 아님)
this 포인터는 암시적으로도 명시적으로도 사용 가능하다.

Assignment operator overloading에서는 this 포인터가 반드시 필요하다.
1. 자기 대입 확인을 위해 필요
MyClass& MyClass::operator=(const MyClass& rhs) {
    if (this == &rhs) // 자기 자신에게 할당되는지 확인
        return *this; // 자기 자신을 반환하여 아무런 작업도 수행하지 않음
    // 대입 연산 수행
}

2.메서드 체이닝 지원
Class& Class::operator=(const Class& other) {
    if (this != &other) {
        // 대입 로직
    }
    return *this; // 현재 객체의 참조를 반환
}

+) 여러 메서드를 체인처럼 연결한 것이 메서드 체이닝인데 아래와 같이 연결이 가능하다.
obj.setA(a);
obj.setB(b);
obj.setC(c); 이 코드를 아래와 같이 변환 가능

obj.setA(a).setB(b).setC(c);

그런데 여기서 set은 객체 자신을 반환해야 한다.
C++에서는 다음과 같이 구성한다.
class MyClass {
public:
    MyClass& setA(TypeA a) {
        // A 설정
        return *this;
    }
    MyClass& setB(TypeB b) {
        // B 설정
        return *this;
    }
    MyClass& setC(TypeC c) {
        // C 설정
        return *this;
    }
};

Assignment operator overloading에서의 this pointer를 사용한
메서드 체이닝은 다음 코드의 작성을 가능하게 한다.

a = b = c;

여기서는 b=c가 먼저 수행되고 그 결과를 a에 대입한다. 

3. 객체 상태 변경
대입 연산자(=)를 오버로딩하는 주목적은 한 객체의 상태를 다른 객체로 복사하는 과정을
사용자 정의하는 것인데 이에 this pointer가 핵심적인 역할을 한다.

연산자 오버로딩에 대한 자세한 내용은 따로 다룰 것이다.
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