#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 801
#define INF 1000000000

int N, E;
int dist[3][MAX];
vector <pair<int, int>> v[MAX];

void dijkstra(int idx, int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[idx][start] = 0;
	pq.push({ dist[idx][start], start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (dist[idx][x] < w) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int nw = v[x][i].second;

			if (dist[idx][nx] > w + nw) {
				dist[idx][nx] = w + nw;
				pq.push({ dist[idx][nx], nx });
			}
		}
	}
}

int main(void) {

	cin >> N >> E;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
		v[to].push_back({ from, w });
	}

	int v1 = 0, v2 = 0;

	cin >> v1 >> v2;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
	}

	dijkstra(0, 1);
	dijkstra(1, v1);
	dijkstra(2, v2);

	if (dist[0][v1] == INF || dist[1][v2] == INF || dist[1][N] == INF || dist[0][v2] == INF || dist[2][v1] == INF || dist[2][N] == INF) {
		cout << "-1\n";
	}
	else {
		if (dist[0][v1] + dist[1][v2] + dist[2][N] > dist[0][v2] + dist[2][v1] + dist[1][N]) {
			cout << dist[0][v2] + dist[2][v1] + dist[1][N] << "\n";
		}
		else {
			cout << dist[0][v1] + dist[1][v2] + dist[2][N] << "\n";
		}
	}

	return 0;
}
