#include <iostream>
using namespace std;

// Stack이 다 찼을 경우와 비었을 경우 예외 처리를 하기 위한 class
class StackEmpty {
public:
	StackEmpty(const string& err) { }
};

class StackFull {
public:
	StackFull(const string& err) { }
};

// template으로 함수를 선언할 경우 형태를 주의해서 작성해야 함.
// 일반적으로 template을 사용하면 헤더에서 인라인 구현하는 것이 일반적이다.

template <typename T>
class ArrayStack {
	enum { DEF_CAPACITY = 100};	// 기본 stack 용량
public:
	ArrayStack(int cap = DEF_CAPACITY);		// 스택 생성자
	int size() const;						// 스택 크기
	bool empty() const;						// 스택이 비었는지 판단
	const T& top() const throw(StackEmpty);	// 스택의 top 원소를 가져오는 함수, stack에 아무것도 없으면 StackEmpty로 에러 처리
	void push(const T&) throw(StackFull);	// 스택의 원소를 push하는 함수, 스택이 꽉 차있으면 StackFull로 에러 처리
	void pop() throw(StackEmpty);			// 스택의 원소를 pop하는 함수, 스택이 비어있으면 StackEmpty로 에러 처리 

private:
	T* S;			// 스택의 주소 -> S[i] 같은 형식으로 스택의 원소를 불러올 수 있게 함.
	int capacity;	// 스택 용량 
	int t;			// top 원소의 index
};

// 배열로 스택을 만들기 때문에 S를 T타입의 크기 cap 배열로 초기화
// top의 index의 경우 -1로 하는 것이 헷갈리지 않음 (값이 존재하면 index 0 부터인데 초기엔 값이 없으므로 0보다 작은 -1)
template <typename T> ArrayStack<T>::ArrayStack(int cap)
	: S(new T[cap]), capacity(cap), t(-1) {

}

// index + 1 = size 이기 때문
template <typename T> int ArrayStack<T>::size() const {
	return (t + 1);
}

// t가 0보다 작으면 비어있으므로 true, 0보다 크면 원소가 들어온 것이므로 false
template <typename T> bool ArrayStack<T>::empty()const {
	return (t < 0);
}

// top 원소 확인
template <typename T> const T& ArrayStack<T>::top() const {
	// stack이 비어있는 경우
	if (empty()) {
		// 빈 스택의 예외처리로 message 던짐
		throw StackEmpty("Top of empty Stack\n");
	}
	// 비어있지 않다면 반환
	return S[t];
}

// push 함수
template <typename T> void::ArrayStack<T>::push(const T& e) {
	// 스택이 가득 찼다면
	if (size() == capacity) {
		// 스택이 가득 찼을 경우의 예외처리로 message 던짐
		throw StackFull("Push to full Stack\n");
	}
	// 스택에 공간이 남아있다면
	else {
		// *주의
		// top을 한 번 증가시킨 후 그 위치에 e 원소 삽입
		// 만일 후위 연산자를 사용하여 S[t++]로 작성할 경우 
		// e가 증가되지 않은 이전 top 값에 삽입되어 이전 top위치의 값이 소실된다.
		// 그 후 top의 위치 t가 증가하여 t는 top이 아닌 그 위의 쓰레기 값의 위치를 가르키게 된다.
		S[++t] = e;
	}
}

// pop 함수
template <typename T> void ArrayStack<T>::pop() {
	// 스택이 비었을 경우
	if (empty()) {
		// 뺄 원소가 없으므로 예외처리
		throw StackEmpty("Pop to empty Stack\n");
	}

	// 이 부분에서는 후위 연산자도 사용 가능. 이후에 t를 사용하는 연산이 없기 때문이다.
	--t;
}