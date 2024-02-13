// Span
/*
n일수 만큼의 일련의 주식 시세표가 주어졌을 경우 특정일의 주가보다 작거나
같은 주가가 가장 길게 연속되는 날의 수

index	0	1	2	3	4
value	1	3	4	2	1
span	1	2	3	2	5

/////////////////////////////////////////////
for loop를 통해서도 해결할 수 있다.

Algorithm Span_for(P)
	Input array P[n]
	Output array S[n], S[i]는 j=i-k+1, ..., i에 대해 P[j] =< P[i]이고, k<=i+1인 가장 큰 k이다.
	for i=0 to n-1 do
		k=1
		done <- false
		repeat
			if P[i-k] =< p[i]
				k = k+1
			else
				done <- true
		until (k>i) or done
		S[i] = k
	return S

=> for문을 사용하여 해결할 경우 시간 복잡도가 O(n^2)이다.
   외부 반복은 0 ~ n-1, 내부 반복은 최악의 경우(오름차순 정렬) i번 반복되는데 i는 n에 종속하므로
   대략 n*n의 시간인 O(n^2)이 시간 복잡도가 된다.

/////////////////////////////////////////////

그러나 스택을 이용하면 linear-time에 풀 수 있다. O(n)

Algorithm Span_Stack(P)
	Input P[n], empty stack D
	Output S[n], S[i]는 j=i-k+1, ..., i에 대해 P[j] =< P[i]이고, k<=i+1인 가장 큰 k이다.
	for i=0 to n-1 do
		done <- false
		while not(D.isEmpty() or done)do
			if P[D.top()] =< P[i] then
				D.pop()
			else 
				done <- true
		if D.isEmpty()then
			h = -1
		else
			h = D.top()
		S[i] <- i-h
		D.push
	return S

	P는 모든 원소를 순회하면서 P[D.top()]를 비교하여 
	P[i]보다 큰값을 가진 원소의 인덱스를 저장한다.
	스택이 비거나 P[i]보다 크거나 같은 값을 가진 원소를 찾을 때까지 pop

*/

// 구현상 특징
/*
1) 첫날의 stock span은 무조건 1
2) 배열에서 자신의 인덱스보다 앞선 값 중 본인보다 크면서 
   가장 가까운 index에 도달하기 전까지의 배열 수를 센 것이 stock span <- 결과값
*/

#include <iostream>
#include "ArrayStack.h"
#pragma warning(disable:4996)

using namespace std;

int main() {
	ArrayStack<int> mystack;
	int arr[50];	// 그래프 값 배열 (일별 원소를 집어넣을 배열)
	int arr_size;	// 사용자가 지정할 그래프 크기 -> 일 수
	int result[50];	// stock span 결과를 저장할 배열

	cout << "day size: ";
	cin >> arr_size;	// 사용자로부터 그래프 크기를 입력 받는다.
	
	cout << "value: ";
	for (int i = 0; i < arr_size; i++) {	// 일자별 값을 받는다. (그래프의 원소를 받음)
		cin >> arr[i];
	}
	
	// 맨 처음 값은 판단할 필요없이 stock span = 1 이다.
	result[0] = 1;
	// 그래프의 맨 처음 값은 자신이 최대값이기 때문에 처음 index인 0을 push
	mystack.push(0);

	for (int i = 1; i < arr_size; i++) {
		// 스택이 비어있지 않을 경우 그래프를 돌면서 스택의 top 원소와 비교했을 때
		// 그래프의 값이 더 작다면 top의 값을 pop으로 빼낸다.
		// 그 후 변경된 top값을 다시 비교해야하기 때문에 while로 조건을 만족하지 않을 때까지 반복한다.
		while (!mystack.empty() && arr[mystack.top()] <= arr[i]) {
			mystack.pop();
		}

		// 배열에서 본인보다 앞선 값 중 자신과 같거나 크지 않은 것을 stock span이라고 하는 것을 이용한다.
		// 위의 while이 끝나면 arr[i]보다큰 값이 top이 되기 때문에 위의 설명을 아래 코드로 구현 가능하다.
		if (!mystack.empty()) {
			result[i] = i - mystack.top();
		}
		// 현재 값이 나온 값 중 가장 큰 값이기 때문에 현재 index에 +1한 값을 저장
		else {
			result[i] = i + 1;
		}
		// 다음 값의 stock span을 계산하기 위해 현재 index를 push 한다.
		mystack.push(i);
	}

	// 마지막으로  result를 출력한다. (0일 = 첫 번째 날)
	for (int i = 0; i < arr_size; i++) {
		cout << i << "일, " << "value: " << arr[i] << ", span: " << result[i] << endl;
	}
	
}