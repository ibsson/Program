#include <iostream>
using namespace std;

#define MAX 21

int R, C, max_result;
char board[MAX][MAX];
bool visited[27];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs(int row, int col, int cnt) {
	max_result = max(max_result, cnt);

	for (int i = 0; i < 4; i++) {
		int n_row = row + dir[i][0];
		int n_col = col + dir[i][1];

		if (n_row >= 0 && n_row < R && n_col >= 0 && n_col < C) {
			if (!visited[board[n_row][n_col] - 'A']) {
				visited[board[n_row][n_col] - 'A'] = true;
				dfs(n_row, n_col, cnt + 1);
				visited[board[n_row][n_col] - 'A'] = false;
			}
		}
	}
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	visited[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << max_result << "\n";

	return 0;
}
