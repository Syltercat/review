// mouse_maze
/*
치즈 많이 먹기

어떤 쥐가 p[n][m]의 미로에 있을 때 왼쪽 아래(p[n-1][0])에서 시작하여
출구(p[0][m-1])에 도달하려한다.

단, 이 쥐는 항상 오른쪽 또는 위쪽으로만 움직일 수 있으며 쥐덫을 피하면서
치즈를 최대한 많이 먹으며 출구로 이동해야한다.

=> 치즈 = 1, 치즈X = 0, 쥐덧 = -99 (큰 음수값을 넣어 최대값을 찾을 때 덫을 피할 수 있도록 한다.)
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
	// 치즈와 덫의 값을 저장할 2차원 배열을 새로 생성
	int cheese[MAX_SIZE][MAX_SIZE] = { 0 };

	// 새로운 배열의 입구를 기존 미로 입구로 초기화
	cheese[n - 1][0] = maze[n - 1][0];

	// 첫번째 열의 치즈값을 조사
	for (int i = n - 2; i >= 0; i--) {
		cheese[i][0] = maze[i][0] + cheese[i + 1][0];
	}

	// 입구가 있는 마지막 행의 치즈값 조사
	for (int i = 1; i < m; i++) {
		cheese[n - 1][i] = maze[n - 1][i] + cheese[n - 1][i - 1];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j < m; j++) {
			// 위로 올라가는 것과 오른쪽으로 가는 것 중 더 큰 값을 선택하여 저장
			cheese[i][j] = maze[i][j] + max(cheese[i + 1][j], cheese[i][j - 1]);
		}
	}

	// 도착점이 [0, m-1]이므로 이에 맞춰 i와 j 초기화
	int i(0), j(m - 1);
	// 최대합의 값을 가지는 경로의 마지막 위치 값을 저장 = 도착점 저장
	// 저장 방법은 10을 곱한 후 더해서 행과 열의 정보를 구분할 수 있게 한다.
	path.push_back(i * MAX_SIZE + j);

	while (i < n - 1 || j > 0) {
		// 위쪽으로 간 경우라면 현재 위치에서 maze에 있는 값을 뺀 경우 아래 index의 값과 같을 것이다.
		// 따라서 아래 if가 만족한 경우라면 위로 향한 것이므로 길을 역순으로 찾기 위해
		// 아래로 내려간다는 의미로 i를 증가시킨다.
		if (i < n - 1 && cheese[i][j] - maze[i][j] == cheese[i + 1][j]) {
			i++;
		}
		// 쥐는 위와 오른쪽으로 밖에 움직일 수 없으므로 위로 가는 경우가 아니라면
		// 오른쪽으로 간 것이다. 역순 찾기 이므로 왼쪽 이동을 위해 j를 감소시킨다.
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
		// 10을 곱해 구분하였으므로 나누기와 나머지 연산으로 분리한다.
		int row = path[i] / MAX_SIZE;
		int col = path[i] % MAX_SIZE;
		cout << "( " << row << ", " << col << " )";
		if (i < path.size() - 1) {
			cout << " -> ";
		}
	}
	cout << endl;
}