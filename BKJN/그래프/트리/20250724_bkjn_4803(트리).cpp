#include <iostream>
#include <vector>
#define MAX 501
using namespace std;

bool visited[MAX];
vector <int> v[MAX];

bool DFS(int cur, int pre) {
	if (visited[cur]) return true;
	visited[cur] = true;

	for (auto i : v[cur]) {
		if (i != pre && DFS(i, cur)) return true;
	}

	return false;
}

int main() {
	int t = 1;

	while (1) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;

			v[from].push_back(to);
			v[to].push_back(from);
		}

		for (int i = 1; i <= n; i++) {
			visited[i] = false;
		}

		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (!DFS(i, 0)) {
					res++;
				}
			}
		}

		if (res == 0) cout << "Case " << t << ": No trees.\n";
		else if (res == 1) cout << "Case " << t << ": There is one tree.\n";
		else cout << "Case " << t << ": " << "A forest of " << res << " trees.\n";

		t++;
	}

	return 0;
}
