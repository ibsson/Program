#include <iostream>
#include <vector>
#include <queue>
#define MAX 3001
using namespace std;

struct Node {
	int idx, dist;
};

vector <int> graph[MAX];
int cycle[MAX];
int pre[MAX];
int visited[MAX];
bool hasCycle;

void findCycle(int cur) {
	visited[cur] = true;

	for (int i = 0; i < graph[cur].size(); i++) {
		if (hasCycle) return;

		int next = graph[cur][i];

		if (visited[next]) {
			if (next != pre[cur]) {
				cycle[cur] = true;
				hasCycle = true;

				while (cur != next) {
					cycle[pre[cur]] = true;
					cur = pre[cur];
				}
			}
		}
		else {
			pre[next] = cur;
			findCycle(next);
		}
	}
}

void BFS(int a) {
	queue <Node> q;
	q.push({ a, 0 });
	visited[a] = true;

	while (!q.empty()) {
		int cur = q.front().idx, dist = q.front().dist;
		q.pop();

		if (cycle[cur]) {
			cout << dist << ' ';
			return;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next ,dist + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	findCycle(1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[j] = false;
		}

		BFS(i);
	}

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 3001

int N;
vector <int> edge[MAX];
int Visited[MAX];
int Pre[MAX];
int Cycle[MAX];
int has_Cycle;

void Find_Cycle(int cur); //그래프에서 사이클을 찾는 로직
void BFS();

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int from = 0, to = 0;
		cin >> from >> to;

		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	Find_Cycle(1);
	memset(Visited, 0, sizeof(Visited));

	BFS();

	cout << "\n";

	return 0;
}

void Find_Cycle(int cur) {
	Visited[cur] = true;

	for (int i = 0; i < edge[cur].size(); i++) {
		if (has_Cycle) return;

		int next = edge[cur][i];

		if (Visited[next]) {
			if (next != Pre[cur]) {
				Cycle[cur] = true;
				has_Cycle = true;

				while (cur != next) {
					Cycle[Pre[cur]] = true;
					cur = Pre[cur];
				}
				return;
			}
		}
		else {
			Pre[next] = cur;
			Find_Cycle(next);
		}
	}
}

void BFS() {
	queue <pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		q.push({i, 0});

		while (!q.empty()) {
			int cur = q.front().first;
			int dis = q.front().second;
			q.pop();

			if (Cycle[cur]) {
				cout << dis << " ";
				while (!q.empty()) {
					q.pop();
				}
				break;
			}

			for (int j = 0; j < edge[cur].size(); j++) {
				if (!Visited[edge[cur][j]]) {
					q.push({ edge[cur][j], dis + 1 });
					Visited[edge[cur][j]] = 1;
				}
			}
		}

		memset(Visited, 0, sizeof(Visited));
	}
}

/*
그래프에서 사이클을 찾는 코드를 어떻게 구현해야 할지 모르겠어서 다른사람의 코드를 참고했다.
그래프를 돌다가 자신의 부모노드가 아니면서 이전에 방문한적이 있는 노드가 있다면 그때 사이클이 형성된다.
이 로직은 자주 쓰일 것 같아서 잘 공부해놓아야겠다.
*/
*/
