// List
/*
<�迭�� ����Ʈ�� ����>
array
	- ������ ũ��
	- ������ ������
	- ���� ����ȿ����
	- �ð� ���⵵ O(1)

list
	- ũ�� ���� ����
	- ������ �����
	- ���� ���� ȿ����
	- O(N)
*/

// singly linked list
/*
<singly linked list>
node = [element | link]
[head | link] -> [element | link] -> [element | tail] ����

Node ����ü (class�� ���� ��)
struct Node {
	Object& element;
	Node* next;

	Node(const Object& e = Object(), Node* n = NULL) // defalut
	:element(e), next(n); { }
};
typedef Node* NodePtr; // Node type�� NodePtr ������ ���� ����

���� ����ü�� �̿��ؼ� singly linked list ����
template <typename Object>
class LinkedList {
protect:
	//... insert Node here
public:
	insert();
	remove();
	...
private:
	NodePtr head, tail;
	int count;
	...
}

<singly linked list ������ ����>
[head | link] -> [element | link] -> [element | tail] ������ ��� ��ġ�� �����͸� ������ �������� ���� �ڵ� �帧�� �ٸ�

1. insert_at_head
	1) Node* n1 = new Node (element, head)
	2) head = n1;	// head�� node1�� ����
	3) count++;
	=> �� node�� �Ҵ��ϰ� ���� �־��� �� ���� ���� ��� tail�� ���� list�� head�� �־��ش�.

2. insert_at_tail
	1) Node* n1 = new Node (element, NULL) // ���� ������ ��尡 �Ǳ� ������ link ���� ���� �ʿ䰡 ����.
	2) tail -> next = n2; // ���� list�� ���� �޺κ��� n2�� �Ѵ�.
	3) tail = n2; // ������ n2�� �Ѵ�. (tail �缳��)
	4) count++;
	
<singly linked list ������ ����>
���԰� ���������� ��� �κ��� ������ ���ΰ��� ���� ���� �帧�� �ٸ���.

1. delete_at_head
	1) Node* temp = head -> next;	// head�� ������� head ������ ���� ������ ã�� �� �����Ƿ� 
									// �켱 head ������ ��忡 �̸��� �ٿ��� head ���̵� ã�� �� �ֵ��� ��.
	2) delete head;	// ��带 �����ϰ�
	3) head = temp;	// ��� ���� ��带 ���� ����
	4) count --;

2. delete_at_tail
	1) Node* temp = head;	// �� ��带 ���� �Ѵ�.
	2) while (temp -> next != tail) {	// ������ �����Ҷ����� ������ ��带 �ϳ��� Ž��
			temp = temp -> next;
	   }
	3) temp -> next = NULL;	// ���� �տ� �����ϸ� ���� while���� ����, 
							// �� ���¿��� ���� ���� ������ �����̱� ������ ������ ����� ������带 NULL�� ���� (��������)
	4) tail = temp  // ������ ������ ���� �� ��带 ������ ����
	5) count--;

*/

// singly lined list (stack / queue)
/*
singly linked list�� ���ð� ť �� ������� ���� �� �ִ�. (pseudo code)

1) Stack with
temploate <typename Object>
class LinkedStack {
protected:
	//...insert Node here	// �Ʊ� ����ü �״�� ������ ��
public:
	LinkedStack() {
		TOP = NULL;
		size = 0;
	}
	int Size() const{ return size; }
	bool isEmpty() const{ return size == 0; }

	Object& top() throw(StackEmptyException) {
		if(isEmpty()) throw StackEmptyException("Top of empty stack");
		return TOP -> element;
	}
}

void push(const Object& e) {			// head�� push
	NodePtr temp = new Node(e, TOP);	// top�� head, e�� element
	TOP = temp;								
	size++;
}

Object pop() throw(StackEmptyException) {	// head���� pop
	if(isEmpty()) throw StackEmptyException("Top of empty stack");
	NodePtr old = TOP;			// ������ top�� old���ϰ� ������ top �ڿ��ִ� ��带 top���� �����Ѵ�.
	TOP = TOP -> next;
	size--;						// ���� ����� ���� �� 
	Object result = old -> element		// ������ top�̾��� old�� ele�� �ٸ� �̸����� �����Ѵ�.
	delete old;					// ������ top�� old ����
	return result;				// ������ old�� ele�� result ��ȯ
}

	/////////////////////////////////////////////////////////////
	ex. housekeeping Function
	protected
		void removeALL(){				// ����Ʈ ��ü�� ���� �Լ�
			while(!isEmpty()) pop();
		}
		void copyFrom(const LinkedStack& ls);	// copy �Լ�
	public:
		LinkedStack(const LinkedStack& ls) {	// ���������
			copyFrom(ls);
		}
		LinkedStack& operator=(const LinkedStack& ls) {		// ���� ������
			
			if(this!=&ls) {						// ���� �������� ������ �ǿ����� ����Ʈ = this, ������ ls
				removeAll();					// �� ����
				copyFrom(ls);					// �����ؼ� �޾ƿ�
			}
			// ����: ���� ������ ==���� �ϸ� �ȵ�
			// removeAll�� ���� ����Ǳ� ������ copy���� �ʾƼ� ����Ʈ�� �����Ǹ� �ڸ��� �� ����
			
			return *this;
		}
		~LinkedStack() {		// �Ҹ���
			removeAll();
		}

		template <typename Object>
		void LinkedStack<Object>::copyFrom(const LinkedStack& ls){
			TOP = NULL;
			NodePtr p = ls.TOP;
			NodePtr prev = NULL;
			while(p!=NULL) {	// ls ����Ʈ�� ���� ���� ������ �ݺ�
				NodePtr v = new Node(p->element, NULL);	// ���ο� ��带 ���� ls�� TOP���Ҹ� �����Ѵ�.)
				if(TOP==NULL) TOP = v;	// ���縦 ó�� �����ؼ� ������ ����Ʈ�� �ƹ��͵� ����Ǿ����� ������
										// ������ ������ ls.TOP�� ������ list�� head�� �����.
				else prev->next = v;	// ���� ���� ������ �ƴ϶� ���簡 ����Ǵ� ���̶�� prev�� ���� ���� ���� ���� ��带 �����Ѵ�.(link)

				// ���� �ܰ������� ���� prev�� v ����
				prev = v; 
				// ���� ���縦 ���� ls�� ������ ��嵵 �������� �̵�
				p = p->next;
			}
			size = ls.size;	// �����ϱ� ������ size�� �Ȱ��� ����� ��
		}
	/////////////////////////////////////////////////////////////


2) Queue whit
	void enqueue(const Object& e) {		// push�� ���� ���� �׷��� ť������ tail�� ���� ����߰�
		NodePtr v = new Node(e,NULL);	// ���� list �����
		if(size==0) head = v;			// ����Ʈ�� ó�� ���� ��� head�� v��
		else tail->next = v;			// �ƴ϶�� tail ������ ������ ��带 �ٿ��ش�.
		tail = v;						// �ٿ��� ��� v�� tail�� �Ѵ�.
		size++;							// �ϳ� �ٿ������� ũ�⸦ �ø���.
	}

	Object dequeue() throw(QueueEmptyException) {
		if(isEmpty()) throw QueueEmptyException("dequeue of empty queue");	// list ������� ����ó��
		NodePtr old = head;				// �� ���� �Ȱ��� head��������
		head = head->next;				// head ��� ��ġ�� �ű�� ���� ��带 ����
		if((--size)==0) tail=NULL;		// �� �ڵ�� head�� �Ű�µ� list�� ����� ��, tail�� null�� �ؼ� list�� ������� �˸�
		Object result = old->element;	// ������ ����� ���Ҹ� ���� �� ��带 �����ϰ� ������ ����� ���� ���
		delete old;
		return result;
	}

���� list �ڵ���� Ȯ���غ��� ������ �ð� ���⵵�� O(n)���� �� �� �ִ�.
-> list�� ���� ��ο��� ���԰� ������ �����ϵ��� �ٲٸ� ����������. O(n)
= doubly linked list
[header] -> [prev | ele | next] -> [prev | ele | next] -> [prev | ele | next] -> trailer ����
*/

// doubly linked list
/*
3. Deque with a Doubly Linked List
struct Node {
	Object& element;
	Node* next;			// �޺κ� link
	Node* prev;			// �պκ� link
	Node(const Object& e=Object(), Node* p =NULL, Node *n=NULL)	// �ʱ�ȭ
		:element(e), prev(p), next(n) { }
};
typedef Node* NodePtr;

void insertFirst(const Object& e) {
	NodePtr oldFirst = header->next;				// ���� list�� ù��° ��带 ��� �ڷ� ����
	NodePtr temp = newNode(e, header, oldFirst);	// �� ��带 ���� �� �޺κ� link�� ���� list�� ù ���� ����
	oldFirst->prev = temp;							// ���� ���� ��带 ������ ù��° ��� �տ��� �����Ѵ�.
	header->next = temp;							// ��� �ڿ� ���� ���� ��带 ����
	size++;											// ũ�� ����
}

void removeLast(){
	if(isEmpty()) throw StackEmptyException("Top of empty stack");	// �� list�� ��� ����ó��
	NodePtr old = trailer->prev;		// trailer ���� old ���� �Ѵ�.
	NodePtr newLast = old->prev;		// ���� ������ ����� �� ��带 newLast�� �Ѵ�.
	trailer->prev = newLast;			// trialer ���� ��带 newLast�� �����Ѵ�.
	newLast->next = trailer;			// newLast�� ���� ��带 trailer�� �Ѵ�.
	size--;								// ũ�⸦ ���̰� �����Ѵ�.
	delete old;
}
*/

// doubly linked list (vector)