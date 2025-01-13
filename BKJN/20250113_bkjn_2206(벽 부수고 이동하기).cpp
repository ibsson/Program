#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 1002

int N, M, result = INT_MAX;
int map[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dis[2][MAX][MAX];
bool visited[MAX][MAX];

int bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({ {1, 1}, 0 });
	dis[0][1][1] = 1;

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int status = q.front().second;
		q.pop();

		if (row == N && col == M) return 1;

		for (int i = 0; i < 4; i++) {
			int n_row = row + dir[i][0];
			int n_col = col + dir[i][1];

			if (n_row >= 1 && n_row <= N && n_col >= 1 && n_col <= M) {
				if (!visited[n_row][n_col]) {
					if (map[n_row][n_col] == 1 && status == 0 && dis[1][n_row][n_col] > (dis[status][row][col] + 1)) {
						q.push({ { n_row, n_col }, 1 });
						dis[1][n_row][n_col] = dis[status][row][col] + 1;
					}
					else if (map[n_row][n_col] == 0 && dis[status][n_row][n_col] > (dis[status][row][col] + 1)) {
						q.push({ { n_row, n_col }, status });
						dis[status][n_row][n_col] = dis[status][row][col] + 1;
					}
				}
			}
		}
	}

	return 0;
}

int main(void) {

	cin >> N >> M;

	char tmp = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dis[0][i][j] = INT_MAX;
			dis[1][i][j] = INT_MAX;
		}
	}

	if (bfs()) {
		result = min(dis[0][N][M], dis[1][N][M]);
		cout << result << "\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}
