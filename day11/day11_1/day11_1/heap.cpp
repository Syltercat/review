// heap sort
/*
heap을 이용하여 정렬하는 방법, 우선순위 큐의 일종이다.

우선순위 큐: 큐는 먼저 들어오는 데이터가 먼저 나가는 FIFO 형식의 자료구조이지만,
			 우선순위 큐는 먼저 들어오는 데이터가 아니라 우선 순위가 높은 데이터가 먼저 나가는 형태의 자료구조이다.
			 일반적으로 heap을 이용하여 구현한다.

heap: 우선순위 큐를 위해 고안된 완전이진트리 형태의 자료구조이다.
	  최댓값, 최솟값을 찾아내는 연산이 빠르다.

heap 특징
1. 완전이진트리 형태로 이루어져 있다.
2. 부모노드와 서브트리간 대소관계가 성립한다. (반 정렬)
3. 이진 탐색트리와 달리 중복된 값이 허용된다.

Max heap: 부모 노드의 키 값이 자식 노드보다 크거나 같은 완전이진트리
Min heap: 부모 노드의 키 값이 자식 노드보다 작거나 같은 완전이진트리

heap 정렬 순서
1. 정렬할 원소들을 모두 공백 heap에 삽입
2. 제일 큰 원소부터 한 원소씩 삭제
3. 삭제한 원소를 리스트의 뒤에서부터 차례로 삽입
4. 오름차순으로 정렬된 리스트 생성
=> insert, remove, find 함수가 필요

heap은 완전이진트리이므로 중간에 비어있는 요소가 없기 때문에 배열을 이용하여 구현한다.
배열로 구현하면 부모나 자식 노드를 찾아가는 연산을 구현하기도 편하다.

자식노드 찾기: 왼쪽 자식노드 index = 부모노드 index * 2
			   오른쪽 자식노드 index = 부모노드 index * 2 +1
부모노드 찾기: 부모노드 index = 자식노드 index / 2
*/

// STL 사용
#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, less<int>> pq1;
    pq1.push(5);
    pq1.push(2);
    pq1.push(8);
    pq1.push(9);
    pq1.push(1);
    pq1.push(14);

    pq1.pop();
    pq1.pop();

    cout << "Max Heap PQ : ";
    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(5);
    pq2.push(2);
    pq2.push(8);
    pq2.push(9);
    pq2.push(1);
    pq2.push(14);

    pq2.pop();
    pq2.pop();

    cout << "Min Heap PQ : ";
    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;

    return 0;
}