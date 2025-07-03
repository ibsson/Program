#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 100001

int V, farthestNode;
int maxDist = 0;
bool visited[MAX];
vector <pair<int, int>> tree[MAX];

void dfs(int node, int dist) {
	visited[node] = true;

	if (dist > maxDist) {
		maxDist = dist;
		farthestNode = node;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int nextNode = tree[node][i].first;
		int nw = tree[node][i].second;

		if (!visited[nextNode]) {
			dfs(nextNode, (dist + nw));
		}
	}
}

int main(void) {

	cin >> V;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < V; i++) {
		cin >> from;

		while (1) {
			cin >> to;
			if (to == -1) break;
			cin >> w;

			tree[from].push_back({ to, w });
		}
	}

	dfs(1, 0);

	memset(visited, false, sizeof(visited));
	dfs(farthestNode, 0);

	cout << maxDist << "\n";

	return 0;
}

/*
1. 임의의 노드에서 시작해서 가장 먼 노드를 찾는다.
2. 1에서 찾은 노드에서 다시 dfs를 실행하여 가장 먼 노드까지의 거리를 구한다.
3. 이 거리가 트리의 지름이다.

이 방식으로 풀었다.
*/
