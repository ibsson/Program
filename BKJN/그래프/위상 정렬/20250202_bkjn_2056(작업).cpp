#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10001

int N, max_t;
int t[MAX];
int result_t[MAX];
int indegree[MAX];
vector <int> graph[MAX];

void topologySort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int from = q.front();
		q.pop();

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j];
			result_t[to] = max(result_t[to], result_t[from] + t[to]);
			indegree[to]--;
			if (!indegree[to]) q.push(to);
		}
	}
}

int main() {

	cin >> N;

	int cnt = 0, x = 0;
	for (int i = 1; i <= N; i++) {
		cin >> t[i];
		result_t[i] = t[i];
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> x;

			indegree[i]++;
			graph[x].push_back(i);
		}
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		max_t = max(max_t, result_t[i]);
	}

	cout << max_t << "\n";

	return 0;
}
