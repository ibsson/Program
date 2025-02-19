#include <iostream>
using namespace std;

#define MAX 102

int N;
int grid[MAX][MAX];
long long int dp[MAX][MAX];
int dr[2] = { 0, 1 };
int dc[2] = { 1, 0 };

long long int dfs(int r, int c) {
	if (r == (N - 1) && c == (N - 1)) return 1;

	if (dp[r][c] != -1) return dp[r][c];

	dp[r][c] = 0;

	for (int i = 0; i < 2; i++) {
		int nr = r, nc = c;

		for (int j = 0; j < grid[r][c]; j++) {
			nr += dr[i], nc += dc[i];
		}

		if (nr > (N - 1) || nc > (N - 1)) continue;

		dp[r][c] = dp[r][c] + dfs(nr, nc);
	}

	return dp[r][c];
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;
}
