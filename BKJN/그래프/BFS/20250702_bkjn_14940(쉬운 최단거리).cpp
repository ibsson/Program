#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int grid[MAX][MAX];
bool visited[MAX][MAX];
int res[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void BFS(int i, int j, int n, int m) {
	queue <pair<pair<int, int>, int>> Q;
	Q.push({ {i, j}, 1 });
	visited[i][j] = true;

	while (!Q.empty()) {
		int y = Q.front().first.first, x = Q.front().first.second;
		int dist = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];

			if ((ny < 0 || ny >= n) || (nx < 0 || nx >= m)) continue;
			if (visited[ny][nx]) continue;

			if (grid[ny][nx] != 0) {
				res[ny][nx] = dist;
				visited[ny][nx] = true;
				Q.push({ {ny, nx}, dist + 1 });
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 2) {
				BFS(i, j, n, m);
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && res[i][j] == 0) res[i][j] = -1;

			cout << res[i][j] << ' ';
		}

		cout << "\n";
	}

	return 0;
}
