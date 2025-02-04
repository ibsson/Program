#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 51

int N, L, R;
int cnt;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int nation[MAX][MAX];
int visited[MAX][MAX];
vector <pair<int, int>> v[MAX * MAX];
vector <int> sum;

void bfs(int r, int c) {
	queue <pair<int, int>> q;
	v[cnt].push_back({ r, c });
	q.push({ r, c });
	visited[r][c] = true;
	sum.push_back(nation[r][c]);

	while (!q.empty()) {
		int c_r = q.front().first, c_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_r = c_r + dy[i], n_c = c_c + dx[i];

			if (n_r < 0 || n_r == N || n_c < 0 || n_c == N) continue;
			if (visited[n_r][n_c]) continue;

			if (abs(nation[n_r][n_c] - nation[c_r][c_c]) >= L && abs(nation[n_r][n_c] - nation[c_r][c_c]) <= R) {
				v[cnt].push_back({ n_r, n_c });
				q.push({ n_r, n_c });
				visited[n_r][n_c] = true;
				sum[cnt] += nation[n_r][n_c];
			}
		}
	}
}

bool chkFinish() {
	bool chk = true;
	cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				for (int k = 0; k < 4; k++) {
					int n_r = i + dy[k], n_c = j + dx[k];

					if (n_r < 0 || n_r == N || n_c < 0 || n_c == N) continue;
					if (visited[n_r][n_c]) continue;

					if (abs(nation[n_r][n_c] - nation[i][j]) >= L && abs(nation[n_r][n_c] - nation[i][j]) <= R) {
						chk = false;
						bfs(i, j);
						cnt++;
						break;
					}
				}
			}
		}
	}

	return chk;
}

int main() {

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> nation[i][j];
		}
	}

	int day = 0;

	while (1) {
		if (chkFinish()) break;

		for (int i = 0; i < cnt; i++) {
			int _size = v[i].size();
			sum[i] /= _size;

			for (int j = 0; j < _size; j++) {
				nation[v[i][j].first][v[i][j].second] = sum[i];
			}
		}

		for (int i = 0; i < N; i++) {
			memset(visited[i], 0, sizeof(visited[i]));
		}
		for (int i = 0; i < cnt; i++) {
			v[i].clear();
		}
		sum.clear();

		day++;
	}

	cout << day << "\n";

	return 0;
}
