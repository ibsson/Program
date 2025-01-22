#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MAX 101

int n, m;
vector <pair<int, int>> v[MAX];
int dist[MAX];

void dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_x = pq.top().second;
		int w = pq.top().first;
		pq.pop();

		if (dist[cur_x] < w) continue;
		
		for (int i = 0; i < v[cur_x].size(); i++) {
			int next_x = v[cur_x][i].first;
			int next_w = v[cur_x][i].second;

			if (dist[next_x] > w + next_w) {
				dist[next_x] = w + next_w;
				pq.push({ dist[next_x], next_x});
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
	}

	for (int i = 1; i <= n; i++) {
		fill(dist, dist + (n + 1), INT_MAX);

		dijkstra(i);

		for (int j = 1; j <= n; j++) {
			if (dist[j] == INT_MAX) cout << "0 ";
			else cout << dist[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
