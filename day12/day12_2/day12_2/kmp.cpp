// kmp
/*
문자열 검색에서
문자열의 불일치가 발생한 경우 string의 앞 부분에 어떤 문자가 있는지
미리 알고 있다면 앞부분에 대해서 다시 비교하지 않고 매칭 수행
=> 패턴을 전처리하여 배열 next[M]을 구해서 잘못된 시작을 최소화

next[M]: 불일치가 발생했을 경우 이동할 다음 위치 (prefix == surfix가 될 수 있는 부분 중 가장 긴 것의 길이)
p[0~i]의 접미사와 일치한 최장 접두사의 끝자리 위치

ABCEAB라고 하면 앞의 AB는 prefix, 뒤의 AB는 suffix이다.

알고리즘 시간복잡도는 O(M+N)이다.

*/

#include <iostream>
#include <vector>	//array 사용보다 vector 사용이 다루기 쉬워서 include
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
		// 비교하는 두 문자열이 같지 않으면 이전에 겹쳤던 갯수를 그대로 가져온다.
		while (j > 0 && pattern[i] != pattern[j]) {
			j = next[j - 1];
		}
		// 비교하는 두 문자열이 같으면 이전에 겹쳤던 수에서 1만큼 증가시켜 현재 겹치는 글자수를 j에 저장
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
