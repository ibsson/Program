#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 51

int R, C, T, sum;
int A[MAX][MAX];
int tmp[MAX][MAX];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
vector <pair<int, int>> cleaner;

void spread(int c_r, int c_c) {
	int num = A[c_r][c_c] / 5, cnt = 0;

	for (int i = 0; i < 4; i++) {
		int n_r = c_r + dr[i], n_c = c_c + dc[i];

		if (n_r < 0 || n_r >(R - 1) || n_c < 0 || n_c >(C - 1)) continue;
		if (A[n_r][n_c] == -1) continue;

		tmp[n_r][n_c] += num;
		cnt++;
	}

	tmp[c_r][c_c] += A[c_r][c_c] - num * cnt;
}

void clean() {
	int row_1 = cleaner[0].first;
	int row_2 = cleaner[1].first;

	for (int i = row_1 - 1; i > 0; i--) tmp[i][0] = tmp[i - 1][0];
	for (int i = 0; i < C - 1; i++) tmp[0][i] = tmp[0][i + 1];
	for (int i = 0; i < row_1; i++) tmp[i][C - 1] = tmp[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--) tmp[row_1][i] = tmp[row_1][i - 1];
	tmp[row_1][1] = 0;

	for (int i = row_2 + 1; i < R - 1; i++) tmp[i][0] = tmp[i + 1][0];
	for (int i = 0; i < C - 1; i++) tmp[R - 1][i] = tmp[R - 1][i + 1];
	for (int i = R - 1; i > row_2; i--) tmp[i][C - 1] = tmp[i - 1][C - 1];	
	for (int i = C - 1; i > 1; i--) tmp[row_2][i] = tmp[row_2][i - 1];
	tmp[row_2][1] = 0;
}

int main() {

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1) cleaner.push_back({ i, j });
		}
	}

	for (int t = 1; t <= T; t++) {
		sum = 0;
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (A[i][j] != 0 && A[i][j] != -1) {
					spread(i, j);
				}
			}
		}
		clean();

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (A[i][j] != -1) {
					A[i][j] = tmp[i][j];
					sum += tmp[i][j];
				}
			}
		}

		for (int i = 0; i < R; i++) {
			memset(tmp[i], 0, sizeof(tmp[i]));
		}
	}

	cout << sum << "\n";

	return 0;
}
