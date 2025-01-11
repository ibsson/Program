#include <iostream>
using namespace std;

#define MAX 16

int N;
int map[MAX][MAX];
int col[MAX];
int result;

void dfs(int row, int cnt) {
	if (row == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!col[i]) {
			int chk = 0;

			if (!chk) {
				for (int j = 1; j < N; j++) {
					if (row < j || i < j) break;

					if (map[row - j][i - j]) {
						chk = 1;
						break;
					}
				}
			}

			if (!chk) {
				for (int j = 1; j < N; j++) {
					if (row + j == N || i + j == N) break;

					if (map[row + j][i + j]) {
						chk = 1;
						break;
					}
				}
			}

			if (!chk) {
				for (int j = 1; j < N; j++) {
					if (row + j == N || i < j) break;

					if (map[row + j][i - j]) {
						chk = 1;
						break;
					}
				}
			}

			if (!chk) {
				for (int j = 1; j < N; j++) {
					if (row < j || i + j == N) break;

					if (map[row - j][i + j]) {
						chk = 1;
						break;
					}
				}
			}

			if (!chk) {
				map[row][i] = 1;
				col[i] = 1;
				dfs(row + 1, cnt + 1);
				map[row][i] = 0;
				col[i] = 0;
			}
		}
	}
}

int main(void) {

	cin >> N;

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
