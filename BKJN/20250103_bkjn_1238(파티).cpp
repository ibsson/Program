#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF 1000000000

int N, M, X;
int result;
vector <pair<int, int>> v[MAX];
int dist[MAX][MAX];

void dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start][start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (dist[start][x] < w) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nw = v[x][i].second;
			int nx = v[x][i].first;

			if (dist[start][nx] > nw + w) {
				dist[start][nx] = nw + w;
				pq.push({ dist[start][nx], nx });
			}
		}
	}
}

int main(void) {

	cin >> N >> M >> X;

	int from = 0, to = 0, w = 0;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			dist[i][j] = INF;
		}
	}

	dijkstra(X);

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;

		dijkstra(i);
	}

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;

		result = max(result, dist[i][X] + dist[X][i]);
	}

	cout << result << "\n";

	return 0;
}
