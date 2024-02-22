// kmp
/*
���ڿ� �˻�����
���ڿ��� ����ġ�� �߻��� ��� string�� �� �κп� � ���ڰ� �ִ���
�̸� �˰� �ִٸ� �պκп� ���ؼ� �ٽ� ������ �ʰ� ��Ī ����
=> ������ ��ó���Ͽ� �迭 next[M]�� ���ؼ� �߸��� ������ �ּ�ȭ

next[M]: ����ġ�� �߻����� ��� �̵��� ���� ��ġ (prefix == surfix�� �� �� �ִ� �κ� �� ���� �� ���� ����)
p[0~i]�� ���̻�� ��ġ�� ���� ���λ��� ���ڸ� ��ġ

ABCEAB��� �ϸ� ���� AB�� prefix, ���� AB�� suffix�̴�.

�˰��� �ð����⵵�� O(M+N)�̴�.

*/

#include <iostream>
#include <vector>	//array ��뺸�� vector ����� �ٷ�� ������ include
using namespace std;

vector<int> initNext(string );
void kmp(string , string );

int main() {
	string text1 = "ababababcababababcaabbabababcaab";
	string pattern1 = "abababca";
	string text2 = "this part is an algorithm design part.";
	string pattern2 = "algorithm";

	cout << "next1: ";
	vector<int> next1 = initNext(pattern1);
	for (int i = 0; i < next1.size(); i++) {
		cout << next1[i];
	}
	cout << endl << "text1 kmp\n";
	kmp(text1, pattern1);
	
	cout << "next2: ";
	vector<int> next2 = initNext(pattern2);
	for(int i = 0; i < next2.size(); i++){
		cout << next2[i];
	}
	cout << "\ntext2 kmp\n";
	kmp(text2, pattern2);
	cout << endl;
}

vector<int> initNext(string pattern) {
	int n = pattern.size();
	vector<int> next(n, 0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		// ���ϴ� �� ���ڿ��� ���� ������ ������ ���ƴ� ������ �״�� �����´�.
		while (j > 0 && pattern[i] != pattern[j]) {
			j = next[j - 1];
		}
		// ���ϴ� �� ���ڿ��� ������ ������ ���ƴ� ������ 1��ŭ �������� ���� ��ġ�� ���ڼ��� j�� ����
		if (pattern[i] == pattern[j]) {
			next[i] = ++j;
		}
	}
	return next;
}

void kmp(string text, string pattern) {
	vector<int> next = initNext(pattern);
	int n = text.size();
	int m = pattern.size();
	int j = 0;
	for (int i = 0;  i < n; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = next[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				cout << "pattern position: " << i - m + 1 << endl;
				j = next[j];
			}
			else {
				j++;
			}
		}
	}
	cout << "end search\n";
}
