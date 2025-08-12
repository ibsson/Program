#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector <int> v[MAX];
int dp[MAX];
int parent[MAX];

void DFS(int cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (next == parent[cur]) continue;

		dp[next] += dp[cur];

		DFS(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> parent[i];
		if (i == 1) continue;

		v[i].push_back(parent[i]);
		v[parent[i]].push_back(i);
	}
		
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		dp[a] += b;
	}

	DFS(1);

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}

	return 0;
}
