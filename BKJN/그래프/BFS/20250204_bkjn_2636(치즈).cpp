#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 101

int r, c, t;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int board[MAX][MAX];
int visited[MAX][MAX];

void bfs() {
	queue <pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	t++;

	while (!q.empty()) {
		int c_r = q.front().first;
		int c_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_r = c_r + dy[i], n_c = c_c + dx[i];

			if (n_r < 0 || n_r == r || n_c < 0 || n_c == c) continue;
			if (visited[n_r][n_c]) continue;

			if (board[n_r][n_c] == 0) {
				q.push({ n_r, n_c });
				visited[n_r][n_c] = true;
			}

			if (board[n_r][n_c] == 1) {
				board[n_r][n_c] = 0;
				visited[n_r][n_c] = true;
				
			}
		}
	}
}

int main() {

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0, last_cnt = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 1) cnt++;
		}
	}

	if (cnt == 0) {
		cout << "0" << "\n";
		cout << "0" << "\n";
		return 0;
	}

	while (1) {
		bfs();

		last_cnt = cnt;
		cnt = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == 1) cnt++;
			}
		}

		if (cnt == 0) break;

		for (int i = 0; i < r; i++) {
			memset(visited[i], 0, sizeof(visited[i]));
		}
	}

	cout << t << "\n";
	cout << last_cnt << "\n";

	return 0;
}
