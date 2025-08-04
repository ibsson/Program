#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

vector <int> v[MAX];
bool visited[MAX];
int res = 0;

void DFS(int x, int cnt) {
	if (cnt == 4) {
		res = 1;
		return;
	}

	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i]]) {
			visited[v[x][i]] = true;
			DFS(v[x][i], cnt + 1);
			visited[v[x][i]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[j] = false;
		}

		visited[i] = true;
		DFS(i, 0);

		if (res == 1) break;
	}

	cout << res << '\n';

	return 0;
}
