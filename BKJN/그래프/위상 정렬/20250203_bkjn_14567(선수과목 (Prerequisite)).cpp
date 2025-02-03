#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int N, M;
int indegree[MAX];
int dp[MAX];
vector <int> graph[MAX];

void topologySort() {
	queue <int> q;
	fill(dp, dp + (N + 1), 1);

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int from = q.front();
		q.pop();

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j];
			dp[to] = max(dp[to], dp[from] + 1);
			indegree[to]--;
			if (!indegree[to]) q.push(to);
		}
	}
}

int main() {

	cin >> N >> M;

	int A = 0, B = 0;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		indegree[B]++;
		graph[A].push_back(B);
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";

	return 0;
}
