#include <iostream>
#include <queue>
using namespace std;

char map[8][8];
char maze[9][8][8];
int dir[9][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 0} };

int bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({ {7, 0}, 0 });

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt == 9) return 1;

		if (maze[cnt][row][col] == '.') {
			for (int i = 0; i < 9; i++) {
				int n_row = row + dir[i][0];
				int n_col = col + dir[i][1];

				if (n_row >= 0 && n_row < 8 && n_col >= 0 && n_col < 8) {
					if (maze[cnt][n_row][n_col] != '#') {
						q.push({ {n_row, n_col}, cnt + 1 });
					}
				}
			}
		}
	}

	return 0;
}

int main(void) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < 8; k++) {
				maze[i][j][k] = '.';
			}
		}

		for (int j = i; j < 8; j++) {
			for (int l = 0; l < 8; l++) {
				maze[i][j][l] = map[j - i][l];
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}
