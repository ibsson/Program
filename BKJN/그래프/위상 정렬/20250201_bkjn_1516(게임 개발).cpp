#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 501

int N;
int t[MAX];
int result_t[MAX];
int indegree[MAX];
vector<int> v[MAX];

void topologySort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			result_t[i] = t[i];
		}
	}

	while (!q.empty()) {
		int from = q.front();
		q.pop();

		for (int i = 0; i < v[from].size(); i++) {
			int to = v[from][i];

			result_t[to] = max(result_t[to], result_t[from] + t[to]);

			indegree[to]--;
			if (indegree[to] == 0) {
				q.push(to);
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> t[i];
		while (true) {
			int x;
			cin >> x;
			if (x == -1) break;

			// x가 i보다 먼저 지어져야 하므로 i로 가는 간선을 생성
			v[x].push_back(i);
			indegree[i]++;
		}
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		cout << result_t[i] << "\n";
	}

	return 0;
}
