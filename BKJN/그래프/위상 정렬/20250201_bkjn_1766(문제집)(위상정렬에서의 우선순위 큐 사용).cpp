#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 32001

int N, M;
int indegree[MAX];
vector <int> v[MAX];
vector <int> result;

void topologySort() {
	priority_queue <int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) pq.push(i);
	}
	
	for (int i = 0; i < N; i++) {
		int from = pq.top();
		result.push_back(from);
		pq.pop();

		for (int j = 0; j < v[from].size(); j++) {
			int to = v[from][j];
			indegree[to]--;
			if (!indegree[to]) pq.push(to);
		}
	}
}

int main() {

	cin >> N >> M;

	int A = 0, B = 0;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		indegree[B]++;
		v[A].push_back(B);
	}

	topologySort();

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
