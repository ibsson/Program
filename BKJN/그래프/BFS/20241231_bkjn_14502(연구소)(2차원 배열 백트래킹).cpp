#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
int map[9][9];
int cpy[9][9];
int visited[9][9];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int max_cnt;

void BFS(int i, int j) {
	queue <pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (!visited[ny][nx] && cpy[ny][nx] == 0) {
					q.push({ ny, nx });
					cpy[ny][nx] = 2;
					visited[ny][nx] = 1;
				}
			}
		}
	}
}

void SetWall(int start, int cnt) {

	if (cnt == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cpy[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && cpy[i][j] == 2) {
					BFS(i, j);
				}
			}
		}

		int z_cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cpy[i][j] == 0) {
					z_cnt++;
				}
			}
		}

		max_cnt = max(z_cnt, max_cnt);

		memset(cpy, 0, sizeof(cpy));
		memset(visited, 0, sizeof(visited));

		return;
	}

	for (int i = start; i < N * M; i++) {
		int y = i / M;
		int x = i % M;

		if (map[y][x] == 0) {
			map[y][x] = 1;
			SetWall(i + 1, cnt + 1);
			map[y][x] = 0;
		}
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	SetWall(0, 0);

	cout << max_cnt << "\n";

	return 0;
}
