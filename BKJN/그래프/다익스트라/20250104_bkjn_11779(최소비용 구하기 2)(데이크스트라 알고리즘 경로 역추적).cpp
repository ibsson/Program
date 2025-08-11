#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAX 1001
#define INF 1000000000

int n, m;
int dist[MAX];
int path[MAX]; //경로 역추적을 위한 배열
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
				path[nx] = x; //이전 노드의 번호를 넣음
			}
		}
	}
}

int main(void) {

	cin >> n;
	cin >> m;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
	}

	int start = 0, finish = 0;

	cin >> start >> finish;

	fill(dist + 1, dist + (n + 1), INF);

	dijkstra(start);

	cout << dist[finish] << "\n";
	
	stack <int> way;

	way.push(finish);

	for (int i = 1; i < n; i++) {

		way.push(path[way.top()]);

		if (way.top() == start) break;
	}

	int len = way.size();
	cout << len << "\n";

	while (!way.empty()) {
		cout << way.top() << " ";
		way.pop();
	}

	cout << "\n";

	return 0;
}
