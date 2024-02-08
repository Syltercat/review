// Parenthneses Matching
/*
day6_1에서 작성했던 배열 스택을 이용하여 괄호 매칭 코드를 작성할 것이다.

문자열의 괄호를 차례로 조사하면서 open 괄호를 만나면 push, close 괄호를 만나면
괄호의 짝이 맞는지 확인 후 pop을 수행하는 형태로 작성할 것이다.

구현상에서 주의할 점
	stack이 비었는지 확인할 것
	괄호의 짝이 맞는지 비교할 것
	괄호의 짝이 맞지 않는 경우를 잡아낼 것

괄호가 짝이 맞지 않는 경우(false)
1. close 괄호를 만났으나 stack의 top의 괄호와 짝이 맞지 않는 경우
2. close 괄호를 만났으나 stack이 비어있는 경우
3. 문자열을 끝까지 조사했으나 stack에 괄호가 남은 경우

추가로 생각해볼 수 있는 것
	- close 괄호로 식이 시작하면 어떠한 과정을 거칠 필요없이 바로 false를 출력하여 수행 시간을 단축시킬 수 있다.
*/

#include <iostream>
#include "ArrayStack.h"

// map 사용 이유
/*
map은 key와 value의 쌍으로 이루어진 tree이다.
검색 기능도 가지고 있기 때문에 괄호 쌍을 key와 value로 두고 사용하기에 적합하다.
*/
#include <map>	


using namespace std;

int main() {
	ArrayStack<char> mystack;
	char arr[50];	// 식을 입력받을 배열
	int arr_size = sizeof(arr);
	
	// key = close 괄호, value = open 괄호라고 하자.
	// close를 기준으로 매칭되는 open 괄호를 찾는 것이기 때문에 key가 close가 되어야 한다.
	map <char, char> bucket = { {')','('}, {'}','{'},{']', '['} };

	cout << "식을 입력하세요.\n";
	cin >> arr;

	// 검사
	for (int i = 0; arr[i] != '\0'; i++) {
		// stack이 비었는데 close 괄호가 오는 경우 => false
		if (mystack.empty()) {
			if ((arr[i] == ')' || arr[i] == '}' || arr[i] == ']')) {
				cout << "틀린 괄호 매칭입니다.\n";
				return 0;
			}
		}
		// open 괄호를 만나는 경우 => push
		if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[') {
			mystack.push(arr[i]);
		}
		// close 괄호를 만나는 경우 => open 괄호에 맞춰서 pop
		if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']') {
			
			// close 괄호가 낭아있는데 스택이 빈 경우
			if (mystack.empty()) {
				// 짝에 맞는 open 괄호가 없기 때문에 false
				cout << "틀린 괄호 매칭입니다.\n";
				return 0;
			}

			// 스택에 원소가 남아있는 경우
			else {
				// 짝에 맞는 open 괄호가 아닌 경우
				if (bucket.find(arr[i])->second != mystack.top()) {
					cout << "틀린 괄호 매칭입니다.\n";
					return 0;
				}

				// +) key가 없는 경우를 대비한 end() 반복자 처리
				/*
				이 코드에서는 close 괄호만을 받을 경우를 조건문으로 한정했기 때문에 상관은 없으나
				원래 find를 사용할 때 key가 없는 경우를 대비해야 견고한 코드를 짤 수 있다.

				따라서 견고한 코드를 만들기 위해 end() 반복자가 아닌지 확인하기 위해 코드를 수정하면 아래와 같다.
				
				auto it = bucket.find(arr[i]);
				if (it != bucket.end() && it->second != mystack.top()) {
					cout << "틀린 괄호 매칭입니다.\n";
					return 0;
				}
				*/

				// 짝에 맞는 open 괄호인 경우
				else {
					mystack.pop();
				}
			}
		}
	}

	// 검사를 전부 끝낸 후 스택이 비었는지 검사
	if (mystack.empty()) {
		cout << "올바른 괄호 매칭입니다.\n";
		return 1;
	}
	else {
		cout << "틀린 괄호 매칭입니다.\n";
		return 0;
	}
}
