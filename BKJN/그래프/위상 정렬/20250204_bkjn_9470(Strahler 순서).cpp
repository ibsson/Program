#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 1001

int T, K, M, P, A, B;
int indegree[MAX];
int status[MAX];
pair<int,int> cnt[MAX];
vector <int> graph[MAX];

void topologySort() {
	queue <int> q;
	
	for (int i = 1; i < M; i++) {
		if (!indegree[i]) {
			q.push(i);
			status[i] = 1;
		}
	}

	for (int i = 0; i < M; i++) {
		int from = q.front();
		q.pop();

		for (int j = 0; j < graph[from].size(); j++) {
			int to = graph[from][j];

			if (status[from] > cnt[to].first) {
				cnt[to].first = status[from];
				cnt[to].second = 1;
				status[to] = status[from];
			}
			else if (status[from] == cnt[to].first) {
				if (cnt[to].second == 1) {
					cnt[to].second = 2;
					cnt[to].first++;
					status[to]++;
				}
			}

			indegree[to]--;
			if (!indegree[to]) q.push(to);
		}
	}
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> K >> M >> P;

		for (int i = 0; i < P; i++) {
			cin >> A >> B;

			indegree[B]++;
			graph[A].push_back(B);
		}

		topologySort();

		cout << K << " " << status[M] << "\n";

		memset(indegree, 0, sizeof(indegree));
		memset(status, 0, sizeof(status));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < M; i++) {
			graph[i].clear();
		}
	}

	return 0;
}
