// ������ ����
/*
���ڵ��� 2���� �迭�� �ִ�. ���� ���࿡�� ���� �Ʒ� ����� ������ �� 
�������� �濡 �ִ� ������ ���� ���� ���� ���� ã�ƺ���. �� �� ��� �� cell����
���� cell�� ������ ��쿡�� �ٷξƷ�, ���ʴ밢�� �Ʒ�, �����ʴ밢�� �Ʒ��θ� �̵��� �����ϴ�.

�� cell���� �� �� �ִ� �ִ��� ���� (�ڽ� index�κ��� �޴밢 ��, �����밢 ��, �ٷ� ���� ���Ͽ� �ִ� ���� �� ����)
=> �����ϱ� ���� 2���� �迭�� �߰��� �ʿ�
=> ������ ���·� ���� ������ ����� ���� ������ �ݺ��ϸ� ������ ���� ���� �࿡�� �ִ밪 ���� ���� �� �ְԵȴ�.

���Ϸ��� �� = ���簪 + ��ó�� �� �ִ밪(M[i-1,j-1], M[i-1,j], M[i-1, i+1])
=> M[i,j] = A[i,j] + max(M[i-1, j-1], M[i-1, j], M[i-1, i+1])
*/

#include <iostream>
#include <vector>

using namespace std;

const int rows = 8;
const int cols = 9;

void reverse(vector<int>& path);
int maxsumpath(int arr[rows][cols], vector<int>& path);

int main() {
	int intarray[rows][cols] = {
	{3, 4, 9, -2, 2, 51, -23, 2,-1},
	{223, 7, 8, -11, 5, -99, 2, 3, -4},
	{2, 51, -23, -23, 6, 3, 2, 4, 5},
	{5, -99, 2, -1, 32, 2, 5, -99, 2},
	{6, 3, 3, -4, 2, -1, 6, 3, 3},
	{32, 2, 4, 5, 3, -4, 2, -1, 4},
	{4, 4, 23, 6, 2, -1, 3, -4, 34},
	{78, 32, 1, 7, 3, -4, -23, -23, 6}
	};
	vector<int> path;
	int sum = maxsumpath(intarray, path);
	cout << "MaxSum: " << sum << endl;
	cout << "Path: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i];
		if (i != path.size() - 1) {
			cout << " -> ";
		}
	}
	cout << endl;
}


void reverse(vector<int>& path) {
	int size = path.size();
	for (int i = 0; i < size / 2; i++) {
		int temp = path[i];
		path[i] = path[size - 1 - i];
		path[size - 1 - i] = temp;
	}
}

int maxsumpath(int arr[rows][cols], vector<int>& path) {
	// �ִ��� ������ ���ο� �迭 ����
	int Arr[rows][cols];

	// ù ���� �״�� ����
	for (int i = 0; i < cols; i++) {
		Arr[0][i] = arr[0][i];
	}
	
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int left = (j > 0) ? Arr[i - 1][j - 1] : 0;
			int down = Arr[i - 1][j];
			int right = (j < cols - 1) ? Arr[i - 1][j + 1] : 0;

			int next = left;
			if (down > next)
				next = down;
			if (right > next)
				next = right;
			Arr[i][j] = arr[i][j] + next;
 		}
	}

	// ������ �࿡�� �ִ��� ������ index ã��
	int sum = Arr[rows - 1][0];
	int index = 0;
	for (int i = 1; i < cols; i++) {
		if (Arr[rows - 1][i] > sum) {
			sum = Arr[rows - 1][i];
			index = i;
		}
	}

	// vector �ʱ�ȭ
	path.clear();
	// vector�� ������ ���� �ִ밪 ����
	path.push_back(arr[rows - 1][index]);

	// ���������� �Ž��� �ö󰡼� path�� ã�� ����
	// ���� row ��ġ�� ������ ��
	int curr_row = rows - 1;

	// �������� �� ����� ����
	for (int i = rows - 2; i >= 0; i--) {
		// �޴밢 ��, �����밢 ��, �ٷ� �� ���� �����ؼ� �ִ��� ���Ͽ� ����
		int left = (index > 0) ? Arr[i][index - 1] : 0;
		int up = Arr[i][index];
		int right = (index < cols - 1) ? Arr[i][index + 1] : 0;

		int prev = left;
		if (up > prev)
			prev = up;
		if (right > prev)
			prev = right;
		if (prev == left)
			index--;
		if (prev == right)
			index++;

		// ���� �ִ��� ���� ���鼭 ������ ���̹Ƿ� path�� �����Ѵ�.
		path.push_back(arr[curr_row - 1][index]);
		curr_row--;
	}
	// �ڿ������� �Ųٷ� �����Ͽ����Ƿ� �ٽ� �������ش�.
	reverse(path);
	return sum;
}