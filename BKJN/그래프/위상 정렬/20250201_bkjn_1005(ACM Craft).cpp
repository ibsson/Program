#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1001

int T, N, K, W;
int indegree[MAX];
int D[MAX];
int D_sum[MAX];
vector <int> graph[MAX];

void topologySort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			q.push(i);
			D_sum[i] = D[i];
		}
	}

	for (int i = 0; i < N; i++) {
		int from = q.front();
		q.pop();

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j];
			D_sum[to] = max(D_sum[to], D_sum[from] + D[to]);
			indegree[to]--;
			if (!indegree[to]) q.push(to);
		}
	}
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> D[i];
		}

		int A = 0, B = 0;
		for (int i = 0; i < K; i++) {
			cin >> A >> B;

			indegree[B]++;
			graph[A].push_back(B);
		}

		cin >> W;

		topologySort();

		cout << D_sum[W] << "\n";

		memset(indegree, 0, sizeof(D));
		memset(D, 0, sizeof(D));
		memset(D_sum, 0, sizeof(D));
		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
	}

	return 0;
}
