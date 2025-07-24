#include <iostream>
#include <string>
#include <queue>
#define MAX 51
using namespace std;

string map[MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int res = -1;

void BFS(int i, int j, int N, int M) {
	bool visited[MAX][MAX] = { false };
	int dist[MAX][MAX] = { 0 };
	queue <pair<int, int>> Q;

	visited[i][j] = true;
	Q.push({ i, j });

	while (!Q.empty()) {
		int y = Q.front().first, x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k], nx = x + dx[k];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 'W') continue;
			if (visited[ny][nx]) continue;

			dist[ny][nx] = dist[y][x] + 1;

			if (res < dist[ny][nx]) res = dist[ny][nx];

			visited[ny][nx] = true;
			Q.push({ ny, nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				BFS(i, j, N, M);
			}
		}
	}

	cout << res << '\n';

	return 0;
}
