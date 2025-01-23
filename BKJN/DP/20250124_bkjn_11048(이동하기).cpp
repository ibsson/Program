#include <iostream>
#include <queue>
using namespace std;

#define MAX 1002

int N, M;
int grid[MAX][MAX];
int dp[MAX][MAX];
int dr[2] = { 0, 1 };
int dc[2] = { 1, 0 };

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
		}
	}

	dp[1][1] = grid[1][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 2; k++) {
				int next_r = i + dr[k];
				int next_c = j + dc[k];

				if (dp[next_r][next_c] < dp[i][j] + grid[next_r][next_c]) dp[next_r][next_c] = dp[i][j] + grid[next_r][next_c];
			}
		}
	}

	cout << dp[N][M] << "\n";

	return 0;
}
