#include <iostream>
using namespace std;

#define MAX 18
#define INF 100000000

int N, M, D, cnt_kill, result;
int grid[MAX][MAX];
int tmp[MAX][MAX];
int arrow[3] = { INF, INF, INF };
int _min[3] = { INF, INF, INF };
pair<int, int> pos[3];

bool chkFinish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 1) return false;
		}
	}

	return true;
}

void playGame() {
	cnt_kill = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = grid[i][j];
		}
	}

	while (1) {
		if (chkFinish()) return;

		for (int i = 0; i < 3; i++) {
			_min[i] = INF, pos[i] = { -1, -1 };
		}

		for (int a = 0; a < 3; a++) {
			for (int i = (N - 1); i >= 0; i--) {
				for (int j = 0; j < M; j++) {
					int len = abs(N - i) + abs(arrow[a] - j);

					if (len > D) continue;
					if (tmp[i][j] != 1) continue;

					if (_min[a] > len || (_min[a] == len && j < pos[a].second)) {
						_min[a] = len;
						pos[a] = { i, j };
					}
				}
			}
		}

		for (int a = 0; a < 3; a++) {
			if (pos[a].first == -1 || pos[a].second == -1) continue;
			if (tmp[pos[a].first][pos[a].second] == 0) continue;
			tmp[pos[a].first][pos[a].second] = 0;
			cnt_kill++;
		}

		for (int i = (N - 1); i >= 1; i--) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = tmp[i - 1][j];
			}
		}
		for (int i = 0; i < M; i++) {
			tmp[0][i] = 0;
		}
	}
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		playGame();
		result = max(result, cnt_kill);
		return;
	}

	for (int i = idx; i < M; i++) {
		arrow[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main() {

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
