// 숫자판 놀이
/*
숫자들이 2차원 배열에 있다. 가장 윗행에서 가장 아래 행까지 내려올 때 
걸쳐지는 길에 있는 숫자의 합이 가장 높은 것을 찾아보자. 이 때 어느 한 cell에서
다음 cell로 내려올 경우에는 바로아래, 왼쪽대각선 아래, 오른쪽대각선 아래로만 이동이 가능하다.

각 cell마다 될 수 있는 최댓값을 저장 (자신 index로부터 왼대각 위, 오른대각 위, 바로 위를 비교하여 최댓값 구할 수 있음)
=> 저장하기 위한 2차원 배열이 추가로 필요
=> 저장한 상태로 가장 마지막 행까지 위의 과정을 반복하면 마지막 행의 다음 행에서 최대값 행을 구할 수 있게된다.

구하려는 값 = 현재값 + 근처값 중 최대값(M[i-1,j-1], M[i-1,j], M[i-1, i+1])
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
	// 최댓값을 저장할 새로운 배열 생성
	int Arr[rows][cols];

	// 첫 행은 그대로 저장
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

	// 마지막 행에서 최댓값을 가지는 index 찾기
	int sum = Arr[rows - 1][0];
	int index = 0;
	for (int i = 1; i < cols; i++) {
		if (Arr[rows - 1][i] > sum) {
			sum = Arr[rows - 1][i];
			index = i;
		}
	}

	// vector 초기화
	path.clear();
	// vector에 마지막 행의 최대값 삽입
	path.push_back(arr[rows - 1][index]);

	// 역방향으로 거슬러 올라가서 path를 찾는 로직
	// 현제 row 위치는 마지막 행
	int curr_row = rows - 1;

	// 마지막의 전 행부터 루프
	for (int i = rows - 2; i >= 0; i--) {
		// 왼대각 위, 오른대각 위, 바로 위 값을 저장해서 최댓값을 비교하여 저장
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

		// 비교한 최댓값은 길을 가면서 선택할 값이므로 path에 저장한다.
		path.push_back(arr[curr_row - 1][index]);
		curr_row--;
	}
	// 뒤에서부터 거꾸로 저장하였으므로 다시 뒤집어준다.
	reverse(path);
	return sum;
}