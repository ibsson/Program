#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 101

int N, M, t;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX];

void bfs() {
	queue <pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int c_r = q.front().first, c_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_r = c_r + dr[i], n_c = c_c + dc[i];

			if (n_r < 0 || n_r >(N - 1) || n_c < 0 || n_c >(M - 1)) continue;
			if (visited[n_r][n_c]) continue;

			if (arr[n_r][n_c] == 0) {
				q.push({ n_r, n_c });
				visited[n_r][n_c] = true;
			}
			else if (arr[n_r][n_c] == 1) {
				cnt[n_r][n_c]++;
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		int chk = 0;

		bfs();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cnt[i][j] >= 2) arr[i][j] = 0;
			}
		}

		t++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					chk = 1;
					break;
				}
			}
		}

		if (!chk) break;

		for (int i = 0; i < N; i++) {
			memset(visited[i], false, sizeof(visited[i]));
			memset(cnt[i], false, sizeof(cnt[i]));
		}
	}

	cout << t << "\n";

	return 0;
}
