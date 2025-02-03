#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 101

int N, M, X, Y, L;
int indegree[MAX];
int cnt[MAX];
vector <pair<int, int>> graph[MAX];
vector <int> result;

void topologySort() {
	queue <int> q;

	q.push(N);
	cnt[N] = 1;

	for (int i = 0; i < N; i++) {
		int from = q.front();
		q.pop();

		if (graph[from].empty()) result.push_back(from);

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j].first;
			int c = graph[from][j].second;

			cnt[to] += cnt[from] * c;

			indegree[to]--;
			if (!indegree[to]) q.push(to);
		}
	}
}

int main() {

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> L;

		indegree[Y]++;
		graph[X].push_back({ Y, L });
	}

	topologySort();

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " " << cnt[result[i]] << "\n";
	}

	return 0;
}
