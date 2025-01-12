#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 201

int N;
int start_r, start_c;
int finish_r, finish_c;
int min_result = INT_MAX;
int dir[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };
bool visited[MAX][MAX];

void bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({{ start_r, start_c }, 0});
	visited[start_r][start_c] = true;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (r == finish_r && c == finish_c) {
			min_result = min(min_result, cnt);
		}

		for (int i = 0; i < 6; i++) {
			int n_r = r + dir[i][0];
			int n_c = c + dir[i][1];

			if (n_r >= 0 && n_r < N && n_c >= 0 && n_c < N) {
				if (!visited[n_r][n_c]) {
					q.push({ { n_r, n_c }, (cnt + 1)});
					visited[n_r][n_c] = true;
				}
			}
		}
	}
}

int main(void) {

	cin >> N;

	cin >> start_r >> start_c >> finish_r >> finish_c;

	bfs();

	if (min_result == INT_MAX) cout << "-1\n";
	else cout << min_result << "\n";

	return 0;
}
