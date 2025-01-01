#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF 1000000000

int N, M;
vector <pair<int, int>> v[MAX];
int dist[MAX];

void dijkstra(int start, int finish) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (dist[x] < w) continue; //이미 갱신된 노드는 검사하지 않음 (이미 더 작은 값으로 갱신되기 전에 먼저 우선순위큐에 들어가있던 노드는  넘어감)

		for (int i = 0; i < v[x].size(); i++) {
			int nw = v[x][i].second;
			int nx = v[x][i].first;

			if (dist[nx] > nw + w) {
				dist[nx] = nw + w;
				pq.push({ dist[nx], nx });
			}
		}
	}
}

int main(void) {

	cin >> N;
	cin >> M;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> w;

		v[from].push_back({ to, w });
	}

	fill(dist + 1, dist + (N + 1), INF);

	int start = 0, finish = 0;

	cin >> start >> finish;

	dijkstra(start, finish);

	cout << dist[finish] << "\n";

	return 0;
}

/*
시간초과가 떠서 성능을 향상시키는 방법을 찾아보다가 이미 더 작은값으로 갱신된 노드는 검사하지 않으면 불필요한 연산을 줄여준다는 것을 알게되었다.
다익스트라 알고리즘의 성능을 향상시키기 위해서 if (dist[x] < w) continue; 이 문장을 추가해줬더니 문제가 풀렸다.
앞으로 다익스트라 알고리즘 문제를 풀때 잘 쓸 것 같다.
*/
