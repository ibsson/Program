#include <iostream>
using namespace std;

#define MAX 502

int M, N;
int grid[MAX][MAX];
int dp[MAX][MAX];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int dfs(int r, int c) {
	if (r == (M - 1) && c == (N - 1)) return 1;

	if (dp[r][c] != -1) return dp[r][c];

	dp[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];

		if (nr < 0 || nr > (M - 1) || nc < 0 || nc > (N - 1)) continue;

		if (grid[r][c] > grid[nr][nc]) {
			dp[r][c] = dp[r][c] + dfs(nr, nc);
		}
	}

	return dp[r][c];
}

int main() {

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;
}
