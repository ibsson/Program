#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 126
#define INF 1000000000

int map[MAX][MAX];
int dist[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N;

void dijkstra(int y, int x) {
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	dist[y][x] = map[y][x];
	pq.push({ dist[y][x], {y, x} });

	while (!pq.empty()) {
		int w = pq.top().first;
		int _y = pq.top().second.first;
		int _x = pq.top().second.second;
		pq.pop();
		
		if (dist[_y][_x] < w) continue;

		for (int i = 0; i < 4; i++) {
			int ny = _y + dir[i][0];
			int nx = _x + dir[i][1];
			int nw = map[ny][nx];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (dist[ny][nx] > nw + w) {
					dist[ny][nx] = nw + w;
					pq.push({ dist[ny][nx], {ny, nx} });
				}
			}
		}
	}
}

int main(void) {

	int cnt = 1;

	while (1) {
		cin >> N;

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		dijkstra(0, 0);

		cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << "\n";

		cnt++;
	}
	

	return 0;
}

/*
인접리스트에서의 최단거리만 풀어봤던터라 그냥 배열에서는 어떻게 데이크스트라 알고리즘을 사용해야할지 두려웠는데
그냥 똑같은 논리로 사용하면 되는것이었다.
데이크스트라 알고리즘을 알면 쉽게 풀리는 문제였다.
*/
