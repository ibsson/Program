#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 32001

int N, M;
int indegree[MAX];
vector <int> graph[MAX];
vector <int> result;

void topologySort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int from = q.front();
		result.push_back(from);
		q.pop();

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j];
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

		graph[A].push_back(B);
		indegree[B]++;
	}

	topologySort();

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
