#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10001
#define INF 1000000000

int n, d, c;
int Time[MAX];
vector <pair<int, int>> v[MAX];

void dijkstra(int start) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	Time[start] = 0;
	pq.push({ Time[start], start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (Time[x] < w) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int nw = v[x][i].second;

			if (Time[nx] > w + nw) {
				Time[nx] = w + nw;
				pq.push({ Time[nx], nx });
			}
		}
	}
}

int main(void) {

	int T = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= n; j++) {
			v[j].clear();
		}

		cin >> n >> d >> c;

		int to = 0, from = 0, w = 0;

		for (int j = 0; j < d; j++) {
			cin >> to >> from >> w;

			v[from].push_back({ to, w });
		}

		fill(Time, Time + (n + 1), INF);

		dijkstra(c);

		int result = 0, cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (Time[j] == INF) {
				continue;
			}
			else {
				result = max(result, Time[j]);
				cnt++;
			}
		}

		cout << cnt << " " << result << "\n";
	}

	return 0;
}
