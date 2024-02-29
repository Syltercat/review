#pragma once
#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std;

typedef string Elem;	// element type 재정의
class DNode {
	friend class DLL;
private:
	Elem elem;		// element
	DNode* prev;	// 이전 node
	DNode* next;	// 다음 node
};

class DLL {
public:
	DLL();							// 생성자
	~DLL();							// 소멸자
	bool empty()const;				// Double Linked List가 비었는지 확인
	const Elem& front() const;		// 맨 앞 노드의 elemnet
	const Elem& back() const;		// 맨 뒷 노드의 element
	void addFront(const Elem&);		// 맨 앞에 노드 추가
	void addBack(const Elem&);		// 맨 뒤에 노드 추가
	void removeFront();				// 맨 앞의 노드 삭제
	void removeBack();				// 맨 뒤의 노드 삭제

// DLL 특성상 헤더와 꼬리에는 원소값이 들어있지 않다.
private:
	DNode* header;					// list 맨 앞
	DNode* trailer;					// list 맨 뒤
protected:
	void add(DNode*, const Elem&);	// v앞에 새로운 노드 삽입
	void remove(DNode*);			// 노드 삭제
};

#endif // !DLL_H
