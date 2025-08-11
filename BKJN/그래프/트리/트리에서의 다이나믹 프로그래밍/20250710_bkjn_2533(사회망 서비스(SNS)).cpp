#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000001

int N;
vector<int> tree[MAX];
bool check[MAX];
int dp[MAX][2];

void findResult(int node) {
	dp[node][0] = 1;

	for (int i = 0; i < tree[node].size(); i++) {
		int child = tree[node][i];

		if (check[child]) continue;

		check[child] = true;
		findResult(child);

		dp[node][1] += dp[child][0];
		dp[node][0] += min(dp[child][0], dp[child][1]);
	}
}

void solution() {
	check[1] = true;
	findResult(1);

	cout << min(dp[1][0], dp[1][1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	solution();

	return 0;
}
