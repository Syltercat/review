// Stack

/*
push()와 pop()으로 동작
LIFO 형식이다. (Last In First out으로 마지막으로 들어간 입력이 가장 먼저 출력된다는 의미이다.)
top이라고 하는 한쪽 끝에서만 삽입과 삭제가 일어난다.

배열이나 list로 Stack을 만들 수 있다. (뒤에서 할 Queue의 경우에도 동일하다.)
그 중에서도 배열로 만드는 것이 간단하다.

Stack으로 풀 수 있는 문제는 다음과 같다.
1. Parentheses Matching (괄호 매칭)
2. Stock Span Problem (주가 스팬)
3. Postfix Notation (후위 표기법 연산)
4. Maze Problem (미로 문제)

우선 day6_1 에서는 Array로 Stack을 만들 것이고 그 후에 위의 문제를 하나씩 해결해 볼 것이다.
*/

#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main() {
	// int를 저장할 수 있는 stack 생성
	ArrayStack<int> mystack;
	cout << mystack.size() << endl;

	mystack.push(1);
	mystack.push(2);
	cout << mystack.top() << endl;
	
	mystack.pop();
	cout << mystack.top() << endl;
	cout << mystack.size() << endl;

	// 이 배열스택에서는 pop을 할 경우 데이터를 삭제하는 것이 아니라
	// t라는 인덱스를 움직여서 접근할 수 있는 값을 제한할 수 있기 때문에
	// 동적 할당된 스택의 원소들을 반환하는 delete를 사용하지는 않았다.
	// 이 동적 할당을 반환하는 부분은 소멸자를 불러오면서 진행되는데 아래와 같은 소멸자로 구현 가능하다.
	/*
	template <typename E> ArrayStack<E>::~ArrayStack() {
	  delete[] S;
	}
	*/

	return 0;
}