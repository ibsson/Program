#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 501
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int cnt = 0;
int res = 0;

void BFS(int i, int j, int n, int m) {
	int width = 1;

	queue <pair<int, int>> Q;
	Q.push({ i, j });
	visited[i][j] = true;

	while (!Q.empty()) {
		int y = Q.front().first, x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k], nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			Q.push({ ny, nx });
			visited[ny][nx] = true;
			width++;
		}
	}

	res = max(res, width);
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				if (!visited[i][j]) {
					BFS(i, j, n, m);
					cnt++;
				}
			}
		}
	}

	cout << cnt << '\n';
	cout << res << '\n';

	return 0;
}
