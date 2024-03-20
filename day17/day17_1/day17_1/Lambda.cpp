#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 람다식(Lambda)
/*
원래는 boost라는 라이브러리에서 제공하는 함수였으나 modern c++로 넘어오면서 이 기능을 기본적으로 제공하게 되었다.

< 람다 문법이 필요한 이유 >
함수 객체와 함수 포인터의 장점만을 가지고 있기 때문이다.
- 함수 포인터: 함수의 주소값을 지닐 수 있는 포인터 변수, callback을 위해 함수 포인터를 사용한다. (코드에 유연성을 부여할 수 있고, 코드의 길이를 줄일 수 있어서 사용)
- 함수 객체: 객체를 선언하여 함수처럼 사용하는 것, 범용상과 효율성을 위해 사용한다. (다만 inline의 단점인 실행크기가 늘어난다는 점과 코드 길이가 너무 길어질 수 있다는 단점이 있다.)

함수 객체와는 다르게 class를 선언할 필요가 없으며(코드 길이가 줄어든다.)
inline화가 불가능한 함수 포인터와는 다르게 inline화가 가능하다.
(단, 정확히 명시되어 있는 람다 함수만 인라인화가 가능하다.)

꼭 알아야하는 것은 람다는 이름은 없지만 고유한 객체라는 것이다.
*/

// 람다식을 사용하지 않은 코드

// 벡터 원소의 모든 곱을 계산하는 코드의 기본 구성은 아래와 같다.
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

// 다른 방법으로는 Functor를 이용하여 코드를 만들 수 있다.
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

// 람다식을 사용한 코드

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

// 짧고 간결하며 while문이나 Functor같은 코드 없이 깔끔하게 작성 가능하다.

// 람다 구성
/*
람다는 4개의 부분으로 구성되어 있다.
[개시자] (인자) ->반환타입 {함수의 몸통}
[introducer] (parameters) ->return type {statement}
*/

// 1) []
/*
[]: 개시자로, 그 안에 어떤 외부 변수를 써 넣으면 람다 함수가 이를 캡쳐해서 이 변수를 람다 내부에서 사용할 수 있게핟나.

< Capture >
* [=]: 모든 외부 변수 복사
* [&]: 모든 외부 변수 참조
* [this]: 해당 클래스의 변수 참조 가능
* [*this]: 해당 클래스의 변수 복사 가능
* [=, &x, &y] or [&, x, y]: 외부의 모든 변수들을 값/레퍼런스로 가져오되, x와 y만 레퍼런스/값으로 가져온다.
* [x, &y, &z]: 지정한 변수들을 지정한 바에 따라 가져온다.


(1) [=]
- 기본적으로 capture 연산자 '='으로 외부 변수를 가져오면 const형태로 읽기만 가능하다.

int main(){
   int x = 10;
   auto l2 = [=, x = x + 1](){
       cout << "l2함수의 x의 주소 값 : " << &x << endl;
       return x * x;
   };
   cout << "l2 = " << l2() << endl;     // 121
   cout << "x = " << x << endl;         // 10
   cout << "main함수의 x 주소 값 : " << &x << endl;
   // 위 두 x의 주소값도 다름
}

위 코드에서 각자 x가 가리키는 것이 다른데
첫 번째 x: 람다에서 새로 정의된 변수
두 번째 x: 외부 변수(main의 x 변수)
세 번째, 네 번째 x: 람다에서 개로 정의된 변수 (첫 번째와 같음)

이런식으로 x가 새로 생기기 때문에 외부변수인 두 번째 x는 람다함수 내부에서는 더이상 사용이 불가하다.

위 코드로 2가지 사실을 알 수 있다.
1. 람다에서 선언된 변수는 프로그램이 끝날 때까지 변수가 사라지지 않는다.
2. 외부 변수와 같은 변수 이름으로 초기화 한다면 해당 외부 변수는 람다 내부에서 사용되지 않는다.

또한, Capture 블록에서 초기화된 변수는 const로 선언되어 변경이 불가하다.

(2) [&]
외부의 값을 참조 형태로 받아오기 때문에 '='연산자와는 다르게 외부 변수 값을 변경할 수 있다.

int main() {
    int x = 10;

    auto l1 = [&](){
        // 외부 변수인 x값을 5로 변경해준다.
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

위 코드의 I1에서는 람다에서 외부 변수 x의 값을 5로 잘 변경시켜주었다.
그러나, I2에서는 x = x+100이 105가 아니라 110인 것을 확인할 수 있다.

=> 뒤의 소괄호 부분의 차이 때문에 그렇다. (인자 부분의 차이)

*/

// 2) ()