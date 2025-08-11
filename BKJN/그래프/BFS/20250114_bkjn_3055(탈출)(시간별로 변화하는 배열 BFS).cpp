#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int R, C;
int start_x, start_y, finish_x, finish_y;
char map[51][51];
char next_map[51][51];
bool visited[51][51];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool isValid(int r, int c) {
	if (r >= 0 && r < R && c >= 0 && c < C) return 1;
	else return 0;
}

void makeNextMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				for (int k = 0; k < 4; k++) {
					int n_row = i + dir[k][0];
					int n_col = j + dir[k][1];

					if (!isValid(n_row, n_col)) continue;

					if (map[n_row][n_col] == '.') {
						next_map[n_row][n_col] = '*';
					}
				}
			}
		}
	}
}

void cpyMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = next_map[i][j];
		}
	}
}

int bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({ { start_y, start_x }, 0 });

	while (!q.empty()) {
		memset(visited, 0, sizeof(visited));
		int size = q.size(); //시간별로 검사사
		makeNextMap();

		while (size--) {
			int row = q.front().first.first;
			int col = q.front().first.second;
			int time = q.front().second;
			q.pop();

			if (row == finish_y && col == finish_x) return time;

			for (int i = 0; i < 4; i++) {
				int n_row = row + dir[i][0];
				int n_col = col + dir[i][1];

				if (!isValid(n_row, n_col)) continue;
				if (visited[n_row][n_col]) continue;

				if ((map[n_row][n_col] == '.' && next_map[n_row][n_col] == '.') || map[n_row][n_col] == 'D') {
					visited[n_row][n_col] = true;
					q.push({ { n_row, n_col }, time + 1 });
				}
			}
		}

		cpyMap();
	}

	return 0;
}

int main(void) {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S') {
				start_y = i, start_x = j;
				map[i][j] = '.';
			}

			if (map[i][j] == 'D') {
				finish_y = i, finish_x = j;
			}

			next_map[i][j] = map[i][j];
		}
	}

	int result = bfs();

	if (!result) cout << "KAKTUS\n";
	else cout << result << "\n";

	return 0;
}

/*
16954번에서 시간별로 map의 상태를 구분해서 검사를 하니까 문제가 쉽게 풀렸다.
앞으로 이런 풀이방식을 자주 사용할 것 같아서 확실히 익혀놔야겠다.
*/
