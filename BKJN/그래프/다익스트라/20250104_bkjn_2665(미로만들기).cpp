#include <iostream>
#include <queue>
using namespace std;

#define MAX 51
#define INF 1000000000

int n;
char maze[MAX][MAX];
int cnt[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dijkstra(int y, int x) {
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	cnt[y][x] = 0;
	pq.push({ cnt[y][x], {y, x} });

	while (!pq.empty()) {
		int _y = pq.top().second.first;
		int _x = pq.top().second.second;
		int w = pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = _y + dir[i][0];
			int nx = _x + dir[i][1];
		
			if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
				if (maze[ny][nx] == '0') {
					if (cnt[ny][nx] > w + 1) {
						cnt[ny][nx] = w + 1;
						pq.push({ cnt[ny][nx], {ny, nx} });
					}
				}
				else {
					if (cnt[ny][nx] > w) {
						cnt[ny][nx] = w;
						pq.push({ cnt[ny][nx], {ny, nx} });
					}
				}
			}
		}
	}
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt[i][j] = INF;
		}
	}

	dijkstra(0, 0);

	cout << cnt[n - 1][n - 1] << "\n";

	return 0;
}
