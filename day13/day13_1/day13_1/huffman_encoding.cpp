// Huffman encoding
/*
여러 트라이 중 가장 좋은 트라이를 결정하는 기법
(트라이: 하나의 문자 코드가 다른 문자 코드의 접두부가 되지 않는 것을 보장하는 지료구조)

- 우선순위 큐를 사용하여 빈도수가 가장 작은 문자부터 차례로 트라이를 만든다.
- 인코딩된 메시지의 길이는 허프만 빈도수 트리의 가중치 외부 경로 길이와 같다.
- 동일한 빈도수를 가지는 경우가 최적해이다.
- 문자는 leaf에만 올 수 있다.

(가중치 외부 경로 길이(weighted external path length) = sum(leaf까지의 거리 * 가중치)

* preifx code: 한 문자의 코드가 다른 문자의 코드워드의 prefix가 될 수 없다.
ex.
		  
		  0
	b			d
			a		c
=> 위와 같은 트리가 있을 때 a=10, b=0, c=11, d = 1인데 11이 의미하는 것이 dd인지 c인지 구분할 수 없다.
   이는 인코딩 할 수 없는 경우이다.

<허프만 트리 구축 과정>
- 최소 힙을 사용하는 것이 가장 적합하다.
	=> 주어진 텍스트의 빈도수를 계산해서 최솟값 두 개를 골라 짝 지어 leaf에 넣은 후
	   둘의 가중치를 더한다. 
- 다음 최솟값 두 개를 골라 같은 방법으로 짝 짓고 가중치를 더하는 것을 반복한다.

*/

#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct Node {
	char symbol;	// 저장할 문자
	int frequency;	// 빈도수
	Node* left;		// 왼쪽 자식
	Node* right;	// 오른쪽 자식
};

Node* newNode(char symbol, int frequency, Node* left, Node* right) {
	Node* node = new Node;
	node->symbol = symbol;
	node->frequency = frequency;
	node->left = left;
	node->right = right;
	return node;
}

Node* generateHuffmanTree(const string& text) {
	map<char, int> freq;
	// text의 길이만큼 loop, c 변수에는 문자가 들어있고 해당 문자가 나오면 그 문자의 freq 증가
	for (char c: text) {
		freq[c]++;
	}

	// 빈도수를 비교하는 비교기 생성
	auto cmp = [](Node* left, Node* right) {
		return left->frequency > right->frequency;
		};
	// pq라는 우선순위 큐 생성 (비교함수로 cmp사용)
	priority_queue<Node*, vector<Node*>, decltype(cmp)>pq(cmp);
	for (auto& p : freq) {
		pq.push(newNode(p.first, p.second, nullptr, nullptr));
	}

	// build huffman tree
	while (pq.size() > 1)
	{	
		// 빈도수가 가장 낮은 두 노드를 제거한 후 두 빈도의 합을 새로운 상위 노드로 생성하여 
		// 우선순위 큐에 넣어주고 huffman tree 만듬
		Node* p = pq.top();
		pq.pop();
		Node* q = pq.top();
		pq.pop();
		// 빈도수를 더해서 만든 노드는 null문자를 가지게 되고, 더해준 두 노드를 자식으로 한다.
		Node* r = newNode('\0', p->frequency + q->frequency, p, q);
		pq.push(r);
	}

	// root return
	return pq.top();
}

void generateHuffmanTreeCode(Node* root, string code, map<char, string>& codes) {
	// root == null: 해당 노드를 root로 하는 subtree가 잘 만들어졌음 -> return
	if (!root) {
		return;
	}

	// root != null: leaf를 의미
	if (root->symbol != '\0') {
		codes[root->symbol] = code;
	}
	// 왼쪽 자식에서 재귀적으로 호출, 지금까지 생성된 코드에 0추가
	generateHuffmanTreeCode(root->left, code + "0", codes);
	// 오른쪽 자식에서 재귀적으로 호출, 지금까지 생성된 코드에 1추가
	generateHuffmanTreeCode(root->right, code + "1", codes);
}

string encode(const string& text, const map<char, string>& codes) {
	string encodeText;
	for (char c : text) {
		encodeText += codes.at(c);
	}
	return encodeText;
}

int main() {
	string text = "this is a test string";
	Node* root = generateHuffmanTree(text);
	map<char, string>codes;
	string code;
	generateHuffmanTreeCode(root, code, codes);

	string encodedText = encode(text, codes);

	cout << "huffman code table: " << endl;
	for (auto& p : codes) {
		cout << p.first << ": " << p.second << endl;
	}
	cout << "input text: " << text << endl;
	cout << "encoded text: " << encodedText << endl;
}