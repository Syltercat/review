#include <iostream>
#include <ctime>
using namespace std;
#define N 200

template <typename T>
struct Node {
public:
	Node() {			// ������ �ʱ�ȭ
		key = 0;
	}
	Node(int _key, T _data) {	// ���� ������
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

	// ��� ã��
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

	// ����, ����, ���
	void insert(int, T);
	T remove();
	void display();
private:
	Node<T> node[N];
	int size;			// heap ���� ����
};

int main() {
	MaxHeap<int> priorityQueue;

	// ����
	priorityQueue.insert(10, 10);
	priorityQueue.insert(5, 5);
	priorityQueue.insert(3, 3);
	priorityQueue.insert(7, 7);
	priorityQueue.insert(30, 30);
	priorityQueue.insert(9, 9);
	priorityQueue.insert(8, 8);

	priorityQueue.display();
	
	// ����
	priorityQueue.remove();
	priorityQueue.display();
	priorityQueue.remove();
	priorityQueue.display();

	return 0;

}

// template ���ǿ� ���� �и��� �� ���� ����
template <typename T>
void MaxHeap<T>::insert(int key, T data) {
	if (isFull()) {
		cout << "full\n";
		return;
	}
	int index = ++size;		// ������ ����� ���� ��ġ���� ����

	// ��Ʈ���� �Ž��� �ö󰡸� �θ� ���� ��
	while (index != 1 && key > getparent(index).getkey()) {
		node[index] = getparent(index);
		index /= 2;
	}

	// �θ��庸�� ���� ��� �� ��ġ�� ������ ����
	node[index].setkey(key);
	node[index].setdata(data);
}

template <typename T>
T MaxHeap<T>::remove() {
	if (isEmpty()) {
		cout << "Empty\n";
		exit(EXIT_FAILURE);	 // ���л��¸� ��ȯ
	}

	Node<T> itemNode = node[1];			// root node (������ ���)
	Node<T> lastNode = node[size--];	// ��Ʈ�� ������ ���
	int index = 1;

	// root���� �������� �ڽĳ��� ��
	/*
	root ��尡 ������ ���ڸ��� ��������Ʈ���� ������ ��带 ������ ��
	������ ���� �ڽ� ��带 ���Ͽ� ���ĳ�� �� ū ���� ��ȯ�Ѵ�.
	�� �̻� �ڽĳ��� ��ȯ�� �ʿ䰡 ���� ������ �ݺ��Ѵ�.
	*/
	while (index <= size) {
		if (index * 2 > size) {		// leaf����� ���
			break;
		}
		// �ڽ� ��尡 �ϳ��� ���
		else if (index * 2 == size) {
			if (lastNode.getkey() < getleftchild(index).getkey()) {
				node[index] = getleftchild(index);
				index *= 2;
			}
			else {
				break;
			}
		}
		// �ڽ� ��尡 �� ���� ���
		else {
			int leftchildkey = getleftchild(index).getkey();
			int rightchildkey = getrightchild(index).getkey();
			
			// �� ū �ڽĳ��� ��ȯ
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