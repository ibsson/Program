#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
#define MAX 20002

int V, E, K;
int dist[MAX];
vector <pair<int, int>> v[MAX];

void Dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int w_x = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int next_w = v[x][i].second;
			int next = v[x][i].first;

			if (dist[next] > w_x + next_w) {
				dist[next] = w_x + next_w;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main(void) {

	cin >> V >> E;
	cin >> K;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
	}

	fill(dist + 1, dist + (V + 1), INF);

	Dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}

/*
다익스트라 알고리즘을 사용할때 가중치가 더 작은것부터 검사하는것이 더 효율적이라는것을 알게되었다.
*/
