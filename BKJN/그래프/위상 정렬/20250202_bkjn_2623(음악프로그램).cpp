#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int N, M;
int indegree[MAX];
vector <int> graph[MAX];
vector <int> result;
vector <int> tmp;

bool topologySort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) q.push(i);
	}

	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			return false;
		}

		int from = q.front();
		result.push_back(from);
		q.pop();

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j];
			indegree[to]--;
			if (!indegree[to]) q.push(to);
		}
	}

	return true;
}

int main() {

	cin >> N >> M;

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> cnt;

		int x = 0;
		for (int j = 0; j < cnt; j++) {
			cin >> x;
			tmp.push_back(x);
		}

		int A = tmp[0];
		for (int j = 1; j < tmp.size(); j++) {
			graph[A].push_back(tmp[j]);
			indegree[tmp[j]]++;
			A = tmp[j];
		}

		tmp.clear();
	}

	if (!topologySort()) {
		cout << "0\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << result[i] << "\n";
		}
	}

	return 0;
}
