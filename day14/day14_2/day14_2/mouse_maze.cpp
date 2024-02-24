// mouse_maze
/*
ġ�� ���� �Ա�

� �㰡 p[n][m]�� �̷ο� ���� �� ���� �Ʒ�(p[n-1][0])���� �����Ͽ�
�ⱸ(p[0][m-1])�� �����Ϸ��Ѵ�.

��, �� ��� �׻� ������ �Ǵ� �������θ� ������ �� ������ �㵣�� ���ϸ鼭
ġ� �ִ��� ���� ������ �ⱸ�� �̵��ؾ��Ѵ�.

=> ġ�� = 1, ġ��X = 0, �㵡 = -99 (ū �������� �־� �ִ밪�� ã�� �� ���� ���� �� �ֵ��� �Ѵ�.)
=> cheese[i,j] = p[i,j] + max(cheese[i-1,j], cheese[i,j-1]) 

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 9;

void reverse(vector<int>& path);
int maxcheese(int maze[MAX_SIZE][MAX_SIZE], int n, int m, vector<int>& path);
void pathprint(const vector<int>& path, int n, int m);

int main() {
	int n = MAX_SIZE;
	int m = MAX_SIZE;
	int maze[MAX_SIZE][MAX_SIZE] = {
		{0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,-99,0},
		{1,0,-99,0,0,0,0,1,0},
		{0,0,0,0,1,-99,0,0,0},
		{0,1,0,1,0,0,0,0,0},
		{0,0,0,0,0,-99,1,-99,0},
		{0,1,0,0,1,0,0,0,0},
		{0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0}
	};
	vector<int> path;
	int maxCheese = maxcheese(maze, n, m, path);
	cout << "Maximum cheese: " << maxCheese << endl;

	pathprint(path, n, m);
	cout << endl;
}

void reverse(vector<int>& path) {
	int size = path.size();
	for (int i = 0; i < size / 2; i++)
	{
		int temp = path[i];
		path[i] = path[size - 1 - i];
		path[size - 1 - i] = temp;
	} 
}

int maxcheese(int maze[MAX_SIZE][MAX_SIZE], int n, int m, vector<int>& path) {
	// ġ��� ���� ���� ������ 2���� �迭�� ���� ����
	int cheese[MAX_SIZE][MAX_SIZE] = { 0 };

	// ���ο� �迭�� �Ա��� ���� �̷� �Ա��� �ʱ�ȭ
	cheese[n - 1][0] = maze[n - 1][0];

	// ù��° ���� ġ��� ����
	for (int i = n - 2; i >= 0; i--) {
		cheese[i][0] = maze[i][0] + cheese[i + 1][0];
	}

	// �Ա��� �ִ� ������ ���� ġ� ����
	for (int i = 1; i < m; i++) {
		cheese[n - 1][i] = maze[n - 1][i] + cheese[n - 1][i - 1];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j < m; j++) {
			// ���� �ö󰡴� �Ͱ� ���������� ���� �� �� �� ū ���� �����Ͽ� ����
			cheese[i][j] = maze[i][j] + max(cheese[i + 1][j], cheese[i][j - 1]);
		}
	}

	// �������� [0, m-1]�̹Ƿ� �̿� ���� i�� j �ʱ�ȭ
	int i(0), j(m - 1);
	// �ִ����� ���� ������ ����� ������ ��ġ ���� ���� = ������ ����
	// ���� ����� 10�� ���� �� ���ؼ� ��� ���� ������ ������ �� �ְ� �Ѵ�.
	path.push_back(i * MAX_SIZE + j);

	while (i < n - 1 || j > 0) {
		// �������� �� ����� ���� ��ġ���� maze�� �ִ� ���� �� ��� �Ʒ� index�� ���� ���� ���̴�.
		// ���� �Ʒ� if�� ������ ����� ���� ���� ���̹Ƿ� ���� �������� ã�� ����
		// �Ʒ��� �������ٴ� �ǹ̷� i�� ������Ų��.
		if (i < n - 1 && cheese[i][j] - maze[i][j] == cheese[i + 1][j]) {
			i++;
		}
		// ��� ���� ���������� �ۿ� ������ �� �����Ƿ� ���� ���� ��찡 �ƴ϶��
		// ���������� �� ���̴�. ���� ã�� �̹Ƿ� ���� �̵��� ���� j�� ���ҽ�Ų��.
		else {
			j--;
		}
		path.push_back(i * MAX_SIZE + j);
	}
	reverse(path);
	return cheese[0][m - 1];
}

void pathprint(const vector<int>& path, int n, int m) {
	cout << "Path: " << endl;
	for (int i = 0; i < path.size(); i++) {
		// 10�� ���� �����Ͽ����Ƿ� ������� ������ �������� �и��Ѵ�.
		int row = path[i] / MAX_SIZE;
		int col = path[i] % MAX_SIZE;
		cout << "( " << row << ", " << col << " )";
		if (i < path.size() - 1) {
			cout << " -> ";
		}
	}
	cout << endl;
}