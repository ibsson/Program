#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 301

int N, M, year;
int earth[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void bfs(int r, int c) {
	queue <pair<int, int>> q;
	q.push({ r, c });
	visited[r][c] = true;

	while (!q.empty()) {
		int c_r = q.front().first, c_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_r = c_r + dr[i], n_c = c_c + dc[i];
			
			if (n_r < 0 || n_r > (N - 1) || n_c < 0 || n_c > (M - 1)) continue;
			if (visited[n_r][n_c]) continue;

			if (earth[n_r][n_c] == 0) {
				if(earth[c_r][c_c] > 0) earth[c_r][c_c]--;
			}
			else if (earth[n_r][n_c] != 0) {
				q.push({ n_r, n_c });
				visited[n_r][n_c] = true;
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> earth[i][j];
		}
	}

	int chk = 0, cnt = 0;

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (earth[i][j] != 0) {
					chk = 1;
					break;
				}
			}
			if (chk == 1) break;
		}

		if (chk == 0) {
			cout << "0\n";
			return 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (earth[i][j] != 0 && !visited[i][j]) {
					if (cnt == 0) {
						cnt++;
						bfs(i, j);
					}
					else {
						cout << year << "\n";
						return 0;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			memset(visited[i], false, sizeof(visited[i]));
		}

		year++;
		cnt = 0, chk = 0;
	}

	return 0;
}
