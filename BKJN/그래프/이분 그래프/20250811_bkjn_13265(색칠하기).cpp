#include <iostream>
#include <queue>
#include <vector>
#define RED 1
#define BLUE 2
#define MAX 1001
using namespace std;

vector <int> graph[MAX];
int color[MAX];

void DFS(int cur) {
	if (!color[cur]) color[cur] = RED;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];

		if (!color[next]) {
			if (color[cur] == RED) color[next] = BLUE;
			else color[next] = RED;

			DFS(next);
		}
	}
}

bool isBinGraph(int V) {
	for (int cur = 1; cur <= V; cur++) {
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			if (color[cur] == color[next]) return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n, m;
		cin >> n >> m;

		int x, y;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i <= n; i++) {
			if (!color[i]) DFS(i);
		}

		if (isBinGraph(n)) cout << "possible\n";
		else cout << "impossible\n";

		for (int i = 1; i <= n; i++) {
			graph[i].clear();
			color[i] = 0;
		}
	}

	return 0;
}
