#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 5;

//�� ��û�ѵ�..
void print(int(*arr)[SIZE], int);
void mark(int(*arr)[SIZE], int);
int checkBingo(int(*arr)[SIZE], int);
void fillBorad(int(*arr)[SIZE]);
void Swap(int(*arr)[SIZE],int a, int b, int c, int d);
int computerSelect(int(*arr)[SIZE]);

int main() {
	srand(unsigned(time(NULL)));
	int arr_u[SIZE][SIZE], arr_c[SIZE][SIZE];
	int bingo_u = 0, bingo_c = 0;
	int* p_u = &bingo_u;
	int* p_c = &bingo_c;
	int bingo_user = 0;
	int bingo_computer = 0;
	fillBorad(arr_c);
	fillBorad(arr_u);

	while (bingo_user < 5 && bingo_computer < 5) {
		cout << "\n\n���� ����\n";
		print(arr_u, SIZE);
		cout << "\n��ǻ�� ����\n";
		print(arr_c, SIZE);

		cout << "\n��ȣ�� �Է��ϼ���. �ߺ��� ���ڴ� �ڵ����� ���� �Ѿ�ϴ�.\n";
		int choice = 0;
		cin >> choice;

		mark(arr_u, choice);
		mark(arr_c, choice);

		bingo_u = checkBingo(arr_u, *p_u);
		bingo_c = checkBingo(arr_c, *p_c);

		cout << "�÷��̾� ����: " << *p_u << endl << "��ǻ�� ����: " << *p_c;

		bingo_user = *p_u;
		bingo_computer = *p_c;

		*p_u = 0;
		*p_c = 0;

		int c_choice = computerSelect(arr_c);
		cout << "\n\n��ǻ�� choice: " << c_choice << endl;

		mark(arr_u, c_choice);
		mark(arr_c, c_choice);

		bingo_u = checkBingo(arr_u, *p_u);
		bingo_c = checkBingo(arr_c, *p_c);

		cout << "�÷��̾� ����: " << *p_u << endl << "��ǻ�� ����: " << *p_c;

		bingo_user = *p_u;
		bingo_computer = *p_c;

		*p_u = 0;
		*p_c = 0;

	}

	cout << "\n\n���� ����\n";
	print(arr_u, SIZE);
	cout << "\n��ǻ�� ����\n";
	print(arr_c, SIZE);

	if (bingo_user >= 5) {
		cout << "�¸�\n";
	}
	else {
		cout << "�й�\n";
	}
}

void print(int(*arr)[SIZE], int size) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 0) {
				cout << "*" << "\t";
			}
			else {
				cout << arr[i][j] << "\t";
			}
		}
		cout << endl;
	}
}

void mark(int(*arr)[SIZE], int n) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == n) {
				arr[i][j] = 0;
			}
		}
	}
}

int checkBingo(int(*arr)[SIZE], int bingo) {
	int row_count = 0;
	int column_count = 0;
	int cross1_count = 0;
	int cross2_count = 0;
	for (int i = 0; i < SIZE; i++) {
		row_count = 0;
		column_count = 0;
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 0) {
				row_count++;
			}
			if (arr[j][i] == 0) {
				column_count++;
			}
			if (arr[i][j] == 0 && i + j == 4) {
				cross2_count++;
			}
		}
		if (row_count == 5) {
			bingo++;
		}
		if (column_count == 5) {
			bingo++;
		}
		if (arr[i][i] == 0) {
			cross1_count++;
		}
	}
	if (cross1_count == 5) {
		bingo++;
	}
	if (cross2_count == 5) {
		bingo++;
	}
	return bingo;
}

void Swap(int(*arr)[SIZE], int a, int b, int c, int d) {
	int temp[1][1] = { 0 };
	temp[0][0] = arr[a][b];
	arr[a][b] = arr[c][d];
	arr[c][d] = temp[0][0];
}

void fillBorad(int(*arr)[SIZE]) {
	int a = 1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			arr[i][j] = a;
			a++;
		}
	}
	for (int i = 0; i < 25; i++) {
		int row = rand() % 5;
		int col = rand() % 5;
		int row2 = rand() % 5;
		int col2 = rand() % 5;
		Swap(arr, row, col, row2, col2);
	}
}

int computerSelect(int(*arr)[SIZE]) {
	int count[SIZE][SIZE] = { 0 };
	int maxcount = 1;

	// ���õ� ������ �ʱⰪ
	int selectNum = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 0) {
				continue;
			}
			else {
				for (int k = 0; k < SIZE; k++) {
					if (arr[i][k] != 0) {
						count[i][j]++;
					}
					if (arr[k][j] != 0) {
						count[i][j]++;
					}
				}
			}
			// ***
			// �밢1
			if (i == j) {
				for (int k = 0; k < SIZE; k++) {
					if (arr[k][k] != 0) {
						count[i][j]++;
					}
				}
			}

			// �밢2
			if (i == SIZE - 1 - j) {
				for (int k = 0; k < SIZE; k++) {
					if (arr[k][SIZE - 1 - k] != 0) {
						count[i][j]++;
					}
				}
			}

			if (count[i][j] > maxcount) {
				maxcount = count[i][j];
				selectNum = arr[i][j];
			}
		}
	}
	return selectNum;
}
