#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

struct Node {
	int num, dist;
};

vector <Node> tree[MAX];
bool visited[MAX];
int res = 0;

void DFS(int cur, int target, int cnt) {
	if (cur == target) {
		res = cnt;
		return;
	}

	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i].num, dist = tree[cur][i].dist;

		if (!visited[next]) {
			visited[next] = true;
			DFS(next, target, cnt + dist);
			visited[next] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < (N - 1); i++) {
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		visited[a] = true;
		DFS(a, b, 0);

		cout << res << '\n';

		for (int j = 1; j <= N; j++) {
			visited[j] = false;
		}
		res = 0;
	}

	return 0;
}
