#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 300001
#define INF 10000000000
vector <pair<int, int>> v[MAX];
int N, M, K, X;
int dist[MAX];

void dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nw = v[x][i].second;
			int nx = v[x][i].first;

			if (dist[nx] > w + nw) {
				dist[nx] = w + nw;
				pq.push({ dist[nx], nx });
			}
		}
	}
}

int main(void) {

	cin >> N >> M >> K >> X;

	int from = 0, to = 0;

	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		v[from].push_back({ to, 1 });
	}

	fill(dist + 1, dist + (N + 1), INF);

	dijkstra(X);

	int chk = 0;

	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			chk = 1;
			cout << i << "\n";
		}
	}

	if (chk == 0) {
		cout << "-1\n";
	}

	return 0;
}
