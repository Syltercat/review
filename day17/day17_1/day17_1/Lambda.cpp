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
    캡쳐 시점은 객체가 처음 생성될때이다.
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
    cout << l2() << endl;                   // 110 => I1 실행 후라 105로 출력되어야 하는거 아님?
    cout << "main  x  : " << x << endl;     // 5
}

위 코드의 I1에서는 람다에서 외부 변수 x의 값을 5로 잘 변경시켜주었다.
그러나, I2에서는 x = x+100이 105가 아니라 110인 것을 확인할 수 있다.

=> 뒤의 소괄호 부분의 차이 때문에 그렇다. (인자 부분의 차이)
람다는 기본적으로 const로 변소 값을 읽어오는 곳이 있다. 이 부분이 Captrue에서 초기화된 변수와, 람다 함수 정의 후 몸통 뒤에 호출인자인 소괄호 '()' qnqnsdlek.
I2 = [&, x(const로 정의) = x + 10](){ }((const로 정의))

const로 선언된 변수는 컴파일 후 메모리로 올라가는데 이때 Data 영역에 들어가게된다.
따라서 cosnt로 선언된 변수는 실행 중에 바뀔 수 없다. (mutable 제외)


위에 있는 함수 몸통 뒤의 소괄호 '()' 부분은 람다의 실행을 의미함과 동시에 매개변수를 전달하는 역할을 한다.

auto l1 = [](int x) -> int{
    x++;
    return x;
}(5);

////////////////////////
l1의 출력 값 :
6
////////////////////////


////////////////////////
int z;

cin >> z;

auto l2 = [](int y) -> int{
    y++;
    return y;
}(z);

int num1 = l2; // ok
int num2 = l2(30); //error

////////////////////////

I1 람다함수 출력값은 몇번을 호출하든 6의 결과 값이 나온다.
I2 부분은 z라는 사용자 변수를 입력 받도록 되어있는데, I2 함수가 실행된 후 z의 값을 다시 변경해주어도
I2의 결과 값은 11이 나온다. ()부분이 const로 선언되어 한번 정의되면 변하지 않기 때문이다.

하지만 함수 몸통 뒤에 ()가 없다면 매개변수로 어떤 값이 들어올지 모르기 때문에
프로그램이 실행되면 함수의 정의만 이뤄질 뿐 실질적인 실행은 함수 호출인 I1(), I2()로 이뤄지게 된다.
때문에 ()를 붙이ㅣ 않은 람다 함수를 호출하면 람다함수 전체를 실행한다.

결론: 결과값이 110이 나온 이유는 람다 함수가 정의될 때 이미 const 선언에 의해 x값을 갖고 시작하기 때문이다.
      실질적으로 x값이 바뀌는 부분은 I1() 함수를 호출할 때이고, 다음 I2()를 호출해도 초기값은 실행하기에 
      앞서 미리 정의되었음으로 변경된 5가아닌 초기값 10을 가져온다.


?클래스의 멤버 변수도 캡쳐 가능한가?

class gorp {
  vector<int> values;
  int m_;

 public:
  gorp(int mod) : m_(mod) {}
  gorp& put(int v) {
    values.push_back(v);
    return *this;
  }
  int extras() {
    int count = 0;
    for_each(values.begin(), values.end(),
             [=, &count](int v) { count += v % m_; });
    return count;
  }
};

gorp g(4);
g.put(3).put(7).put(8);
cout << "extras: " << g.extras();

extras() 함수를 실행하면 람다가 각 원소를 4로 나눈 나머지들의 합을 구해주는데
m_를 capture할 수 있는 이유는 람다가 암묵적으로 class의 this를 캡쳐했기 때문에 m_에 접근 가능한 것이다.


?그럼 아까 mutable에서만 값 변경이 가능하다고 했는데 아래의 경우는 왜 값 변경이 가능한가?

struct foo {
  foo() : i(0) {}
  void amazing() {
    [=] { i = 8; }();
  }
  int i;
};

foo f;
f.amazing();
cout << "f.i : " << f.i;    // 8

i를 capture해서 8 대입이 안되는 것 처럼 보이지만
사실 i를 capture한게 아니라 this를 capture한거라 this.i를 통해 mutable 없이도 값을 바꿀 수 있다.
왜냐하면, 상수인 this를 변경한게 아니라 this.i를 변경한 것이기 때문이다.

< 캡쳐 범위 >
capture되는 객체들은 모두 람다가 정의된 위치에서 접근 가능해야만 한다.

int i = 8;
{
  int j = 2;
  auto f = [=] { cout << i / j; };  // i, j에 모두 접근 가능
  f();
}                                   // 4 출력
////////////////////////////////////////

int i = 8;
auto f = [i]() {
  int j = 2;
  auto m = [=] { cout << i / j; };  
  m();
};
f();                                // 4 출력

바깥의 람다에서 i를 캡쳐하여서 바깥 람다 몸통안에서 i를 사용할 수 있게 된다.
/////////////////////////////////////////

int i = 8;
auto f = [=]() {
  int j = 2;
  auto m = [&] { i /= j; };
  m();
  cout << "inner: " << i;
};

f();
cout << " outer: " << i;                                  // 컴파일 오류

바깥의 람다는 i를 값으로 캡쳐하여서 i에 const 속성이 붙는다.
그러나 내부 람다(m)은 i를 레퍼런스로 캡쳐해서 값을 변경하려고 했다.
이를 해결하려면 mutable 속성을 붙여주면 된다.

int i = 8;
auto f = [i]() mutable {
  int j = 2;
  auto m = [&, j]() mutable { i /= j; };
  m();
  cout << "inner: " << i;           // inner: 4
};
f();
cout << " outer: " << i;            // outer: 8

=> i 자체가 값으로 입력되어서 outer i의 값은 바뀌지 않은 채 8로 남아있고,
   값으로 받은 i가 m에 의해 2로 나눠져 4가 된다.

마지막으로 Capture 부분은 생략이 가능하다. 
*/  

// 주의
/*
람다에서 [&]나 [this]의 사용은 위험하다. 람다 표현식의 스코프 내에 앞으로 어떤 변수가 추가되더라도
그것까지 다 캡쳐할 수 있는 권한을 갖겠다는 뜻이기 때문에 &는 필요한 것만 캡쳐하는 것이 좋다.
*/

// 2) ()
/*
매개변수를 의미한다.
해당 함수로 전달하고 싶은 매개변수가 있다면 선언하면 된다.
해당 변수는 일반 변수로 선언된다.

int main() {

    int num = 10;

    auto l1 = [](int a, int b) {
        a++;
        b--;

        return a + b;
    };

    auto l2 = [](int a, int b) {
        a++;
        b--;

        return a + b;
    }(num, 2);

    cout << l1(10, 5) << endl;  // 15
    cout << l2 << endl;         // 12

    return 0;
}

I1 람다함수는 호출 될때마다 매개변수 값이 달라질 수 있으므로 함수를 처음부터 끝까지 실행하게 된다.
I2의 경우 매개변수로 들어오는 값이 이미 const로 전달되어 정해져있기 때문에 어디서 몇번을 호출하든 결과가 12로 바뀌지 않는다.

마지막으로 Params 부분역시 생략 가능
*/

// 3) ->
/*
return 부분은 람다 함수의 반환 값(return)의 type을 지정해주는 역할이다.


int main() {

    double num = 10;

    auto l1 = [](double a, int b) ->int {

        return a + b;
    };

    auto l2 = [](int a, int b)->auto {      // return을 auto로 줄 수 있다.
        a++;
        b--;

        return a + b;
    }(num, 5);

    int(*fc_1)() = []() -> int {            // 함수 포인터 형식에 맞게 return type을 결정해 줄수 있으며, 한눈에 return type을 확인하기 좋다.
        return 100;
    };

    int(*fc_2)() = [](){                    // return type은 생략 가능하다.
        return 10000;
    };
    cout << l1(10.1, 5) << endl;        // 15 
    cout << 12 << endl;                 // 12
    cout << fc_1() << endl;             // 100
    cout << fc_2() << endl;             // 10000

    return 0;
}

원래 반환값은 double이 되어야하는데 return type을 int로 실행해서 정수가 출력된다.
*/

// 객체를 capture하면 어떨까?
/*
생성, 소멸, 복사 생성을 출력하도록 만든 객체
struct trace {
  trace() : i(0) { cout << "construct\n"; }
  trace(trace const&) { cout << "copy construct\n"; }
  ~trace() { cout << "destroy\n"; }
  trace& operator=(trace&) {
    cout << "assign\n";
    return *this;
  }
  int i;
};

1)
trace t;
int i = 8;

auto f = [=]() { return i / 2; };

=> f에서 t를 사용하지 않았으므로 t를 캡쳐하지 않아 출력은 다음과 같다.
construct
destroy
//////////////////////////////////

2)
trace t;
int i = 8;

auto m1 = [=]() { int i = t.i; };

cout << " --- make copy --- " << endl;

auto m2 = m1;

=> m1을 생성하면서 람다가 t를 캡쳐했으므로 t의 복사 생성자가 호출된다. (값으로 받았기 때문)
   <레퍼런스로 받았다면 복사생성자가 호출되지 않았을 것이다.>
   그리고 아래의 auto m2 = m1; 에서 복사 생성이 일어나는데 이때 복사 생성자가 값으로 캡쳐된 객체들을
   똑같이 복사 생성해주게되어 t의 복사 생성자가 호출된다. 출력은 아래와 같다.
construct
copy construct
 --- make copy ---
copy construct
destroy
destroy
destroy
*/

// 람다의 전달 및 저장
/*
방법 1)
template <typename T>
void foo(T f) {}
auto f = [] {};

방법 2) 함수 포인터 이용
typedef int (*f_type)(int);
f_type f = [](int i) -> int { return i + 20; };
cout << f(8);

=> 함수 포인터를 이용하는 경우 람다가 캡쳐하는 것이 없어야 한다.

* 방법 3) std::function
std::function<int(std::string const &)> f;
f = [](std::string const &s) -> int { return s.size(); };
int size = f("http://itguru.tistory.com");

cout << size << endl;

=> std::function 방법은 어떤 객체나 함수등을 모두 보관할 수 있는 만능 저장소이다.
   또한 std::function<반환 타입(인자)>와 같은 형태로 쓰며, 캡쳐가 있어도 상관없다.

* std::function을 사용하면 아래 딜레마를 해결할 수 있다.
딜레마: auto f1을 한 시점에서 f1이 명확히 구현되어야 컴파일러에서 타입을 추정할 수 있는데,
        f1을 구현하려면 f2를 먼저 구현해야하고, f2를 구현하려면 다시 f1을 구현해야하는 순환적인 논리 딜레마가 존재

=> function을 이용하여 f1을 선언만 한 뒤, f2를 구현하고 다시 f1을 구현한다.

std::function<int(int)> f1;
std::function<int(int)> f2 = [&](int i) -> int {
  cout << i << " ";
  if (i > 5) {
    return f1(i - 2);
  }
};
f1 = [&](int i) -> int {
  cout << i << " ";
  return f2(++i);
};
f1(10);

* std::function으로 재귀 호출 함수도 구현 가능하다.
std::function<int(int)> fact;
fact = [&fact](int n) -> int {
  if (n == 0) {
    return 1;
  } else {
    return (n * fact(n - 1));
  }
};
cout << "factorial(4) : " << fact(4) << endl;

=> 처음 캡쳐 부분에서 캡쳐하는 대상이 명확히 정해지지 않은 상태이므로 컴파일러가 타입을 추정할 수 없게 되는데,
   function을 이용하면 구현 가능하다.
*/

// 아래 링크에서 람다식을 학습하였다.
/*
https://hwan-shell.tistory.com/84

https://modoocode.com/196
*/