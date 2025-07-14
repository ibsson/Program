#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 101

int N;
int area[MAX][MAX];
int visited[MAX][MAX];
int chk[MAX][MAX];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int max_h, max_cnt;

void BFS(int i, int j) {
	queue <pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (!visited[ny][nx] && !chk[ny][nx]) {
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
			cin >> area[i][j];
			max_h = max(max_h, area[i][j]);
		}
	}
	
	for (int k = 0; k <= max_h; k++) {
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j] <= k) {
					chk[i][j] = true;
				}
			}
		}

		for (int l = 0; l < N; l++) {
			for (int m = 0; m < N; m++) {
				if (!visited[l][m] && !chk[l][m]) {
					BFS(l, m);
					cnt++;
				}
			}
		}

		max_cnt = max(max_cnt, cnt);

		memset(visited, false, sizeof(visited));
		memset(chk, false, sizeof(chk));
	}

	cout << max_cnt << "\n";

	return 0;
}
