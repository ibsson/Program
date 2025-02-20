#include <iostream>
using namespace std;

#define MAX 501

int n;
int grid[MAX][MAX];
int dp[MAX][MAX];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int dfs(int r, int c) {
	if (dp[r][c] != 0) return dp[r][c];

	dp[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];

		if (nr < 0 || nr > (n - 1) || nc < 0 || nc > (n - 1)) continue;

		if (grid[r][c] < grid[nr][nc]) {
			dp[r][c] = max(dp[r][c], 1 + dfs(nr, nc));
		}
	}

	return dp[r][c];
}

int solve() {
	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0) {
				dp[i][j] = dfs(i, j);
			}

			result = max(result, dp[i][j]);
		}
	}

	return result;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	cout << solve() << "\n";

	return 0;
}
