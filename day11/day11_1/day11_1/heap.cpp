// heap sort
/*
heap�� �̿��Ͽ� �����ϴ� ���, �켱���� ť�� �����̴�.

�켱���� ť: ť�� ���� ������ �����Ͱ� ���� ������ FIFO ������ �ڷᱸ��������,
			 �켱���� ť�� ���� ������ �����Ͱ� �ƴ϶� �켱 ������ ���� �����Ͱ� ���� ������ ������ �ڷᱸ���̴�.
			 �Ϲ������� heap�� �̿��Ͽ� �����Ѵ�.

heap: �켱���� ť�� ���� ��ȵ� ��������Ʈ�� ������ �ڷᱸ���̴�.
	  �ִ�, �ּڰ��� ã�Ƴ��� ������ ������.

heap Ư¡
1. ��������Ʈ�� ���·� �̷���� �ִ�.
2. �θ���� ����Ʈ���� ��Ұ��谡 �����Ѵ�. (�� ����)
3. ���� Ž��Ʈ���� �޸� �ߺ��� ���� ���ȴ�.

Max heap: �θ� ����� Ű ���� �ڽ� ��庸�� ũ�ų� ���� ��������Ʈ��
Min heap: �θ� ����� Ű ���� �ڽ� ��庸�� �۰ų� ���� ��������Ʈ��

heap ���� ����
1. ������ ���ҵ��� ��� ���� heap�� ����
2. ���� ū ���Һ��� �� ���Ҿ� ����
3. ������ ���Ҹ� ����Ʈ�� �ڿ������� ���ʷ� ����
4. ������������ ���ĵ� ����Ʈ ����
=> insert, remove, find �Լ��� �ʿ�

heap�� ��������Ʈ���̹Ƿ� �߰��� ����ִ� ��Ұ� ���� ������ �迭�� �̿��Ͽ� �����Ѵ�.
�迭�� �����ϸ� �θ� �ڽ� ��带 ã�ư��� ������ �����ϱ⵵ ���ϴ�.

�ڽĳ�� ã��: ���� �ڽĳ�� index = �θ��� index * 2
			   ������ �ڽĳ�� index = �θ��� index * 2 +1
�θ��� ã��: �θ��� index = �ڽĳ�� index / 2
*/

// STL ���
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