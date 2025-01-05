#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 50001
#define INF 1000000000

int N, M;
int food[MAX];
vector <pair<int, int>> v[MAX];

void dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	food[start] = 0;
	pq.push({ food[start], start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (food[x] < w) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int nw = v[x][i].second;

			if (food[nx] > w + nw) {
				food[nx] = w + nw;
				pq.push({ food[nx], nx });
			}
		}
	}
}

int main(void) {

	cin >> N >> M;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
		v[to].push_back({ from, w });
	}

	fill(food, food + (N + 1), INF);

	dijkstra(1);

	cout << food[N] << "\n";

	return 0;
}
