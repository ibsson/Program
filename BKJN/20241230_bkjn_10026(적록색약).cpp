#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 101

int N, cnt_1, cnt_2;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void BFS(int i, int j) {
	queue <pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (!visited[ny][nx] && grid[ny][nx] == grid[y][x]) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt_1++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 'R') {
				grid[i][j] = 'G';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt_2++;
			}
		}
	}

	cout << cnt_1 << " " << cnt_2 << "\n";

	return 0;
}
