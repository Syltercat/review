// List
/*
<배열과 리스트의 차이>
array
	- 고정된 크기
	- 생성이 간편함
	- 높은 공간효율성
	- 시간 복잡도 O(1)

list
	- 크기 변경 가능
	- 구현이 어려움
	- 낮은 공간 효율성
	- O(N)
*/

// singly linked list
/*
<singly linked list>
node = [element | link]
[head | link] -> [element | link] -> [element | tail] 구조

Node 구조체 (class로 만들어도 됨)
struct Node {
	Object& element;
	Node* next;

	Node(const Object& e = Object(), Node* n = NULL) // defalut
	:element(e), next(n); { }
};
typedef Node* NodePtr; // Node type의 NodePtr 포인터 변수 생성

위의 구조체를 이용해서 singly linked list 생성
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

<singly linked list 데이터 삽입>
[head | link] -> [element | link] -> [element | tail] 구조의 어느 위치에 데이터를 삽입할 것인지에 따라 코드 흐름이 다름

1. insert_at_head
	1) Node* n1 = new Node (element, head)
	2) head = n1;	// head를 node1로 변경
	3) count++;
	=> 새 node를 할당하고 값을 넣어준 후 새로 만든 노드 tail에 이전 list의 head를 넣어준다.

2. insert_at_tail
	1) Node* n1 = new Node (element, NULL) // 가장 마지막 노드가 되기 때문에 link 값을 넣을 필요가 없다.
	2) tail -> next = n2; // 이전 list의 꼬리 뒷부분을 n2로 한다.
	3) tail = n2; // 꼬리를 n2로 한다. (tail 재설정)
	4) count++;
	
<singly linked list 데이터 삭제>
삽입과 마찬가지로 어느 부분을 삭제할 것인가에 따라 삭제 흐름이 다르다.

1. delete_at_head
	1) Node* temp = head -> next;	// head가 사라지면 head 다음에 오는 노드들을 찾을 수 없으므로 
									// 우선 head 다음의 노드에 이름을 붙여서 head 없이도 찾을 수 있도록 함.
	2) delete head;	// 헤드를 삭제하고
	3) head = temp;	// 헤드 다음 노드를 헤드로 정함
	4) count --;

2. delete_at_tail
	1) Node* temp = head;	// 빈 노드를 헤드로 한다.
	2) while (temp -> next != tail) {	// 꼬리에 도달할때까지 헤드부터 노드를 하나씩 탐색
			temp = temp -> next;
	   }
	3) temp -> next = NULL;	// 꼬리 앞에 도달하면 위의 while문을 멈춤, 
							// 이 상태에서 다음 노드는 무조건 꼬리이기 때문에 도달한 노드의 다음노드를 NULL로 변경 (꼬리삭제)
	4) tail = temp  // 위에서 삭제한 꼬리 전 노드를 꼬리로 지정
	5) count--;

*/

// singly lined list (stack / queue)
/*
singly linked list는 스택과 큐 두 방법으로 만들 수 있다. (pseudo code)

1) Stack with
temploate <typename Object>
class LinkedStack {
protected:
	//...insert Node here	// 아까 구조체 그대로 넣으면 됨
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

void push(const Object& e) {			// head에 push
	NodePtr temp = new Node(e, TOP);	// top이 head, e는 element
	TOP = temp;								
	size++;
}

Object pop() throw(StackEmptyException) {	// head부터 pop
	if(isEmpty()) throw StackEmptyException("Top of empty stack");
	NodePtr old = TOP;			// 기존의 top을 old라하고 기존의 top 뒤에있던 노드를 top으로 변경한다.
	TOP = TOP -> next;
	size--;						// 먼저 사이즈를 줄인 후 
	Object result = old -> element		// 기존의 top이었던 old의 ele를 다른 이름으로 저장한다.
	delete old;					// 기존의 top인 old 삭제
	return result;				// 삭제한 old의 ele인 result 반환
}

	/////////////////////////////////////////////////////////////
	ex. housekeeping Function
	protected
		void removeALL(){				// 리스트 전체를 비우는 함수
			while(!isEmpty()) pop();
		}
		void copyFrom(const LinkedStack& ls);	// copy 함수
	public:
		LinkedStack(const LinkedStack& ls) {	// 복사생성자
			copyFrom(ls);
		}
		LinkedStack& operator=(const LinkedStack& ls) {		// 대입 연산자
			
			if(this!=&ls) {						// 현재 연산자의 왼쪽의 피연산자 리스트 = this, 오른쪽 ls
				removeAll();					// 다 비우고
				copyFrom(ls);					// 복사해서 받아옴
			}
			// 주의: 위의 조건을 ==으로 하면 안됨
			// removeAll이 먼저 실행되기 때문에 copy되지 않아서 리스트가 삭제되며 자멸할 수 있음
			
			return *this;
		}
		~LinkedStack() {		// 소멸자
			removeAll();
		}

		template <typename Object>
		void LinkedStack<Object>::copyFrom(const LinkedStack& ls){
			TOP = NULL;
			NodePtr p = ls.TOP;
			NodePtr prev = NULL;
			while(p!=NULL) {	// ls 리스트에 값이 없을 때까지 반복
				NodePtr v = new Node(p->element, NULL);	// 새로운 노드를 만들어서 ls의 TOP원소를 저장한다.)
				if(TOP==NULL) TOP = v;	// 복사를 처음 시작해서 복사할 리스트에 아무것도 저장되어있지 않으면
										// 위에서 저장한 ls.TOP을 복사할 list의 head로 만든다.
				else prev->next = v;	// 복사 시작 순간이 아니라 복사가 진행되는 중이라면 prev의 다음 노드로 새로 만든 노드를 저장한다.(link)

				// 다음 단계진행을 위해 prev에 v 저장
				prev = v; 
				// 다음 복사를 위해 ls의 복사할 노드도 다음으로 이동
				p = p->next;
			}
			size = ls.size;	// 복사하기 때문에 size는 똑같이 만들면 됨
		}
	/////////////////////////////////////////////////////////////


2) Queue whit
	void enqueue(const Object& e) {		// push와 같은 역할 그러나 큐에서는 tail로 삽입 노드추가
		NodePtr v = new Node(e,NULL);	// 새로 list 만들고
		if(size==0) head = v;			// 리스트를 처음 만들 경우 head를 v로
		else tail->next = v;			// 아니라면 tail 다음에 생성한 노드를 붙여준다.
		tail = v;						// 붙여준 노드 v를 tail로 한다.
		size++;							// 하나 붙여줬으니 크기를 늘린다.
	}

	Object dequeue() throw(QueueEmptyException) {
		if(isEmpty()) throw QueueEmptyException("dequeue of empty queue");	// list 비었으면 예외처리
		NodePtr old = head;				// 뺄 때는 똑같이 head에서부터
		head = head->next;				// head 노드 위치를 옮기고 기존 헤드를 삭제
		if((--size)==0) tail=NULL;		// 위 코드로 head를 옮겼는데 list가 비었을 때, tail을 null로 해서 list가 비었음을 알림
		Object result = old->element;	// 삭제할 노드의 원소를 받은 후 노드를 삭제하고 삭제한 노드의 원소 출력
		delete old;
		return result;
	}

위의 list 코드들을 확인해보면 삭제의 시간 복잡도가 O(n)임을 알 수 있다.
-> list의 양쪽 모두에서 삽입과 삭제가 가능하도록 바꾸면 간단해진다. O(n)
= doubly linked list
[header] -> [prev | ele | next] -> [prev | ele | next] -> [prev | ele | next] -> trailer 구조
*/

// doubly linked list
/*
3. Deque with a Doubly Linked List
struct Node {
	Object& element;
	Node* next;			// 뒷부분 link
	Node* prev;			// 앞부분 link
	Node(const Object& e=Object(), Node* p =NULL, Node *n=NULL)	// 초기화
		:element(e), prev(p), next(n) { }
};
typedef Node* NodePtr;

void insertFirst(const Object& e) {
	NodePtr oldFirst = header->next;				// 원래 list의 첫번째 노드를 헤더 뒤로 저장
	NodePtr temp = newNode(e, header, oldFirst);	// 새 노드를 만든 후 뒷부분 link를 기존 list의 첫 노드로 연결
	oldFirst->prev = temp;							// 새로 만든 노드를 기존의 첫번째 노드 앞에다 연결한다.
	header->next = temp;							// 헤더 뒤에 새로 만든 노드를 연결
	size++;											// 크기 증가
}

void removeLast(){
	if(isEmpty()) throw StackEmptyException("Top of empty stack");	// 빈 list의 경우 예외처리
	NodePtr old = trailer->prev;		// trailer 앞을 old 노드로 한다.
	NodePtr newLast = old->prev;		// 기존 마지막 노드의 앞 노드를 newLast로 한다.
	trailer->prev = newLast;			// trialer 이전 노드를 newLast로 변경한다.
	newLast->next = trailer;			// newLast의 다음 노드를 trailer로 한다.
	size--;								// 크기를 줄이고 삭제한다.
	delete old;
}
*/

// doubly linked list (vector)