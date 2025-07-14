#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101
#define INF 1000000000

int n, m, r;
int result;
int item[MAX];
int dist[MAX];
vector <pair<int, int>> v[MAX];

void dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ dist[start], start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (dist[x] < w) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int nw = v[x][i].second;

			if (dist[nx] > w + nw) {
				dist[nx] = w + nw;
				pq.push({ dist[nx], nx });
			}
		}
	}
}

int main(void) {

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < r; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
		v[to].push_back({ from, w });
	}

	for (int i = 1; i <= n; i++) {
		fill(dist + 1, dist + (n + 1), INF);

		dijkstra(i);

		int sum = 0;

		for (int j = 1; j <= n; j++) {
			if (dist[j] <= m) {
				sum += item[j];
			}
		}

		result = max(result, sum);
	}

	cout << result << "\n";

	return 0;
}
