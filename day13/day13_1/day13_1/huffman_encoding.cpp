// Huffman encoding
/*
���� Ʈ���� �� ���� ���� Ʈ���̸� �����ϴ� ���
(Ʈ����: �ϳ��� ���� �ڵ尡 �ٸ� ���� �ڵ��� ���κΰ� ���� �ʴ� ���� �����ϴ� ���ᱸ��)

- �켱���� ť�� ����Ͽ� �󵵼��� ���� ���� ���ں��� ���ʷ� Ʈ���̸� �����.
- ���ڵ��� �޽����� ���̴� ������ �󵵼� Ʈ���� ����ġ �ܺ� ��� ���̿� ����.
- ������ �󵵼��� ������ ��찡 �������̴�.
- ���ڴ� leaf���� �� �� �ִ�.

(����ġ �ܺ� ��� ����(weighted external path length) = sum(leaf������ �Ÿ� * ����ġ)

* preifx code: �� ������ �ڵ尡 �ٸ� ������ �ڵ������ prefix�� �� �� ����.
ex.
		  
		  0
	b			d
			a		c
=> ���� ���� Ʈ���� ���� �� a=10, b=0, c=11, d = 1�ε� 11�� �ǹ��ϴ� ���� dd���� c���� ������ �� ����.
   �̴� ���ڵ� �� �� ���� ����̴�.

<������ Ʈ�� ���� ����>
- �ּ� ���� ����ϴ� ���� ���� �����ϴ�.
	=> �־��� �ؽ�Ʈ�� �󵵼��� ����ؼ� �ּڰ� �� ���� ��� ¦ ���� leaf�� ���� ��
	   ���� ����ġ�� ���Ѵ�. 
- ���� �ּڰ� �� ���� ��� ���� ������� ¦ ���� ����ġ�� ���ϴ� ���� �ݺ��Ѵ�.

*/

#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct Node {
	char symbol;	// ������ ����
	int frequency;	// �󵵼�
	Node* left;		// ���� �ڽ�
	Node* right;	// ������ �ڽ�
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
	// text�� ���̸�ŭ loop, c �������� ���ڰ� ����ְ� �ش� ���ڰ� ������ �� ������ freq ����
	for (char c: text) {
		freq[c]++;
	}

	// �󵵼��� ���ϴ� �񱳱� ����
	auto cmp = [](Node* left, Node* right) {
		return left->frequency > right->frequency;
		};
	// pq��� �켱���� ť ���� (���Լ��� cmp���)
	priority_queue<Node*, vector<Node*>, decltype(cmp)>pq(cmp);
	for (auto& p : freq) {
		pq.push(newNode(p.first, p.second, nullptr, nullptr));
	}

	// build huffman tree
	while (pq.size() > 1)
	{	
		// �󵵼��� ���� ���� �� ��带 ������ �� �� ���� ���� ���ο� ���� ���� �����Ͽ� 
		// �켱���� ť�� �־��ְ� huffman tree ����
		Node* p = pq.top();
		pq.pop();
		Node* q = pq.top();
		pq.pop();
		// �󵵼��� ���ؼ� ���� ���� null���ڸ� ������ �ǰ�, ������ �� ��带 �ڽ����� �Ѵ�.
		Node* r = newNode('\0', p->frequency + q->frequency, p, q);
		pq.push(r);
	}

	// root return
	return pq.top();
}

void generateHuffmanTreeCode(Node* root, string code, map<char, string>& codes) {
	// root == null: �ش� ��带 root�� �ϴ� subtree�� �� ��������� -> return
	if (!root) {
		return;
	}

	// root != null: leaf�� �ǹ�
	if (root->symbol != '\0') {
		codes[root->symbol] = code;
	}
	// ���� �ڽĿ��� ��������� ȣ��, ���ݱ��� ������ �ڵ忡 0�߰�
	generateHuffmanTreeCode(root->left, code + "0", codes);
	// ������ �ڽĿ��� ��������� ȣ��, ���ݱ��� ������ �ڵ忡 1�߰�
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