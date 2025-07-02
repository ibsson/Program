#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 1002

int N, M, K, result = INT_MAX;
int map[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dis[11][MAX][MAX];

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
				if (map[n_row][n_col] == 1 && status < K && dis[status + 1][n_row][n_col] > (dis[status][row][col] + 1)) {
					q.push({ { n_row, n_col }, status + 1 });
					dis[status + 1][n_row][n_col] = dis[status][row][col] + 1;
				}
				else if (map[n_row][n_col] == 0 && dis[status][n_row][n_col] > (dis[status][row][col] + 1)) {
					q.push({ { n_row, n_col }, status });
					dis[status][n_row][n_col] = dis[status][row][col] + 1;
				}
			}
		}
	}

	return 0;
}

int main(void) {

	cin >> N >> M >> K;

	char tmp = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int l = 0; l <= K; l++) {
				dis[l][i][j] = INT_MAX;
			}
		}
	}

	if (bfs()) {
		for (int i = 0; i <= K; i++) {
			result = min(result, dis[i][N][M]);
		}
		cout << result << "\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}
