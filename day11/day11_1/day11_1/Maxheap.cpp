#include <iostream>
#include <ctime>
using namespace std;
#define N 200

template <typename T>
struct Node {
public:
	Node() {			// 생성자 초기화
		key = 0;
	}
	Node(int _key, T _data) {	// 복사 생성자
		key = _key;
		data = _data;
	}
	~Node(){}

	int getkey() const {
		return key;
	}
	void setkey(int _key) {
		key = _key;
	}
	T getdata() const {
		return data;
	}
	void setdata(T _data) {
		data = _data;
	}
private:
	int key;
	T data;
};

template <typename T>
class MaxHeap {
public:
	MaxHeap() {
		size = 0;
	}
	~MaxHeap(){}

	// 노드 찾기
	Node<T>& getparent(int index) {
		return node[index / 2];
	}
	Node<T>& getleftchild(int index) {
		return node[index * 2];
	}
	Node<T>& getrightchild(int index) {
		return node[index * 2 + 1];
	}

	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == N - 1;
	}

	// 삽입, 삭제, 출력
	void insert(int, T);
	T remove();
	void display();
private:
	Node<T> node[N];
	int size;			// heap 원소 개수
};

int main() {
	MaxHeap<int> priorityQueue;

	// 삽입
	priorityQueue.insert(10, 10);
	priorityQueue.insert(5, 5);
	priorityQueue.insert(3, 3);
	priorityQueue.insert(7, 7);
	priorityQueue.insert(30, 30);
	priorityQueue.insert(9, 9);
	priorityQueue.insert(8, 8);

	priorityQueue.display();
	
	// 삭제
	priorityQueue.remove();
	priorityQueue.display();
	priorityQueue.remove();
	priorityQueue.display();

	return 0;

}

// template 정의와 선언문 분리할 때 형태 주의
template <typename T>
void MaxHeap<T>::insert(int key, T data) {
	if (isFull()) {
		cout << "full\n";
		return;
	}
	int index = ++size;		// 마지막 노드의 다음 위치에서 시작

	// 힙트리를 거슬러 올라가며 부모 노드와 비교
	while (index != 1 && key > getparent(index).getkey()) {
		node[index] = getparent(index);
		index /= 2;
	}

	// 부모노드보다 작을 경우 그 위치에 데이터 삽입
	node[index].setkey(key);
	node[index].setdata(data);
}

template <typename T>
T MaxHeap<T>::remove() {
	if (isEmpty()) {
		cout << "Empty\n";
		exit(EXIT_FAILURE);	 // 실패상태를 반환
	}

	Node<T> itemNode = node[1];			// root node (삭제할 노드)
	Node<T> lastNode = node[size--];	// 힙트리 마지막 노드
	int index = 1;

	// root부터 내려가며 자식노드와 비교
	/*
	root 노드가 삭제된 빈자리에 완전이진트리의 마지막 노드를 가져온 후
	가져온 노드와 자식 노드를 비교하여 ㅈ식노드 중 큰 값과 교환한다.
	더 이상 자식노드와 교환할 필요가 없을 때까지 반복한다.
	*/
	while (index <= size) {
		if (index * 2 > size) {		// leaf노드인 경우
			break;
		}
		// 자식 노드가 하나인 경우
		else if (index * 2 == size) {
			if (lastNode.getkey() < getleftchild(index).getkey()) {
				node[index] = getleftchild(index);
				index *= 2;
			}
			else {
				break;
			}
		}
		// 자식 노드가 두 개인 경우
		else {
			int leftchildkey = getleftchild(index).getkey();
			int rightchildkey = getrightchild(index).getkey();
			
			// 더 큰 자식노드와 교환
			if (lastNode.getkey() < leftchildkey || lastNode.getkey() < rightchildkey) {
				node[index] = leftchildkey > rightchildkey ? getleftchild(index) : getrightchild(index);
				index = leftchildkey > rightchildkey ? index * 2 : index * 2 + 1;
			}
			else {
				break;
			}
		}
	}
	node[index] = lastNode;
	return itemNode.getdata();
}

template <typename T>
void MaxHeap<T>::display() {
	int level = 1;
	for (int i = 1; i <= size; i++) {
		if (i == level) {
			cout << endl;
			level *= 2;
		}
		cout << node[i].getdata() << "(" << node[i].getkey() << ")";
	}
	cout << endl << "------------------------------------------" << endl;
}