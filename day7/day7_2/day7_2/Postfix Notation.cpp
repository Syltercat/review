// Postfix Notation
/*
후위 연산: 연산자가 피연산자 뒤에 위치, 컴퓨터가 해석하기에 편리하다.
ex. AB+ 

괄호가 불필요하고 연산자의 우선 순위가 무의미
연산자는 왼편에서 오른편으로 연산자 기술 순서대로 계산

계산 방법
ex. ABC*+DE/-
=> A(B*C)+DE/-
=> AT1+DE/-
=> (A+T1)DE/-
=> T2DE/-
=> T2(D/E)-
=> T2T3-
=> T4

피연산자는 스택에 넣으면서(push) 지나가다가 연산자를 만나면 top부터 스택에서 꺼내서(pop) 연산
그렇게 연산해서 나온 결과는 다시 스택에 push
*/

// 중위 표기식 -> 후위 표기식의 변환
/*
중위 표기식은 일반적으로 사용하는 연산방식이다.
이를 후위 표기식으로 바꾸기 위해서는 식의 우선순위를 파악할 필요가 있다.

ex.
(A+B)*C/D 라는 중위 표기식이 있다면 우선 괄호를 사용하여 우선순위를 구분해야한다.
(((A+B)*C)/D) 이렇게 우선순위를 구분하고 난 후에는 연산자를 괄호 뒤로 빼준다.

=> (((A+B)*C)%D)
=> (((AB)+*C)%D)
=> ((AB+C)*%D)
=> AB+C*D%

위와 같이 후위 표기식으로 변경가능하다.
바뀐 표기식을 보면 피연산자는 순서대로 오퍼레이터는 우선순위의 순서대로 적혀있는 것을 확인할 수 있다.

그렇다면 이제 필요한 것은 우선순위를 구분할 수 있는 테이블을 만드는 것이다.

<우선순위 table>
[우선 순위]
1) 괄호
2) 단항연산자
3) 산술연산자
4) 비트 시프트 연산자
5) 관계 연산자
6) 동등성 연산자
7) 비트 and 연산자
8) 비트 xor 연산자
9) 비트 or 연산자
10) 논리 and 연산자
11) 논리 or 연산자
12) 조건 연산자
13) 할당 연산자


위와 같이 테이블을 만든 후 연산자마다 우선순위를 지정하여 사용해야 한다.

그러나 스택에서는 위의 우선순위와 반대이다. -> 먼저 들어온 연산자가 나중에 pop되기 때문에
											   우선순위가 낮은 연산자가 먼저 들어와야 위의 표와 같이 나중에 처리할 수 있다(= 스택에서의 우선순위가 높아진다.)

중위 연산에서 후위 연산 표기법으로 바꾸기 위해서는 피연산자를 스택에 넣는 것이 아니라 연산자를 스택에 넣어야 한다.
연산자를 계산하지 않고 피연산자 뒤로 넘겨줘야하기 때문이다.

*/

#include <iostream>
#include "ArrayStack.h"
using namespace std;

// 우선순위 테이블
int priority(char);

// 연속되면 안되는 연산자가 연속되는지
bool isConsecutive(char, char);

// 대문자인지 아닌지
bool isNotLetter(char);

// !, (, )를 제외한 특수 문자인지
bool isNotSpecialChar(char);

bool isAndOr(char);

int main() {
	ArrayStack<char> mystack;
	string s;
	cout << "&& ||는 두 개의 연속된 문자를 인식할 수 없기 때문에 한 번만 입력해주세요\n";
	cin >> s;

	// 괄호와 !를 제외한 연산자가 먼저 입력됐을 경우나 대문자 이외의 값이 입력되었을 경우 잘못된 중위 표기식이므로 error1 출력
	if ((s[0] != '!') && (s[0] != '(') && isNotLetter(s[0])) {
		cout << "error 1\n";
	}

	else {
		// 입력받은 식을 for문으로 돌아봄
		for (int i = 0; i < s.length(); i++) {
			// 연산자가 연속으로 나오는 경우에도 중위 표기식이 아니므로
			// 연속으로 나와도 괜찮은 연산자를 제외한 부분을 error2로 출력
			if (i < s.length() - 1 && isConsecutive(s[i], s[i+1])) {
				cout << "error2\n";
				break;
			}

			// 피연산자인 경우 -> 그냥 출력
			else if (!isNotLetter(s[i])) {
				cout << s[i];
			}

			// open 괄호일 경우 -> push
			else if (s[i] == '(') {
				mystack.push('(');
			}

			// close 괄호인 경우 -> 짝이 맞는 괄호를 찾을 때까지 pop
			else if (s[i] == ')') {
				while (mystack.top() != '(') {
					cout << mystack.top();
					// pop할 때 &를 &&로 |을 ||로 다시 변경하는 작업 (한 번 더 출력)
					if (isAndOr(mystack.top())) {
						cout << mystack.top();
					}
					mystack.pop();
				}
				if (!mystack.empty() && mystack.top() == '(') {
					mystack.pop();
				}
			}

			// 연산자인 경우
			else {
				// stack이 비어있지 않으면서 top의 연산자 우선순위가 현재 연산자의 우선순위보다 낮다면
				// top에 있는 operator를 출력하고 pop한다.
				// 스택에서 우선순위가 높다는 것은 연산 우선순위가 낮은 것이므로 스택에 있는 연산자를 먼저 사용하고 현재 연산자를 스택에 집어넣는 것이다.  
				// 주의) 여기서 open 괄호를 만났을 경우에 while문에서 제외를 안해주면 open 괄호가 pop될 수 있어서 후에 들어올 close 괄호가 짝을 찾지 못해
				//       오류가 발생할 수 있다.
				while (!mystack.empty() && mystack.top() != '(' && priority(mystack.top()) <= priority(s[i])) {
					cout << mystack.top();
					// pop할 때 &를 &&로 |을 ||로 다시 변경하는 작업 (한 번 더 출력)
					if (isAndOr(mystack.top())) {
						cout << mystack.top();
					}
					mystack.pop();
				}

				// 스택이 비었거나 top 연산자의 우선순위가 현재 연산자의 우선순위보다 높다면
				// top에 있는 연산자를 현재 연산자로 변경하기 위해 push한다. 
				mystack.push(s[i]);
			}
		}

		// 식을 전부 조사했음에도 스택이 비어있지 않다면 스택에 남은 연산자를 전부 pop한다.
		while (!mystack.empty()) {
			cout << mystack.top();
			// pop할 때 &를 &&로 |을 ||로 다시 변경하는 작업 (한 번 더 출력)
			if (isAndOr(mystack.top())) {
				cout << mystack.top();
			}
			mystack.pop();
		}
	}
	cout << "\n";
	return 0;
}


// 우선 순위 할당 (c = 연산자)
// 이 코드에서는 괄호, not, and, or, 비교연산, 사칙연산만 우선 순위를 나눴다.
int priority(char c) {
	switch (c)
	{
		// 괄호는 우선순위가 제일 높으므로 스택에서는 우선순위를 제일 낮춘다.
	case '(':
		return 0;

		// not 연산은 2순위이므로 괄호 다음으로 순위가 낮다.
	case '!':
		return 1;

	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 3;

	case '<':
	case '>':
		return 4;

		// and, or 연산이 제일 순위가 낮으므로 스택에서는 우선순위가 제일 높다.
		// and, or 연산의 경우 &와 | 기호가 연속 두 번 나오기 때문에 char 형태가 아니라
		// 한 번만 인식하는 것으로 변경하였다.
	case '&':
	case '|':
		return 5;

	default:
		break;
	}
}

// 대문자가 아니면 참
bool isNotLetter(char c) {
	return c < 'A' || c >'Z';
}

// !, (, )를 제외한 특수 문자이면 참
bool isNotSpecialChar(char c) {
	return c != '!' && c != ')' && c != '(';
}

// 연속된 연산자인지
bool isConsecutive(char current, char next) {
	// 연속되면 안되는 경우를 참으로 함
	return (isNotLetter(current) && isNotLetter(next)) && (isNotSpecialChar(current) && isNotSpecialChar(next));
}

bool isAndOr(char c) {
	return c == '&' || c == '|';
}