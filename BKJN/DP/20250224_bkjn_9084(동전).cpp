#include <iostream>
#include <string.h>
using namespace std;

int T, N, M;
int coin[21];
int dp[22][10001];

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j == 0) {
				dp[i][j] = 1;
			}
			else {
				if (j - coin[i] < 0) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - coin[i]] + dp[i - 1][j];
				}
			}
		}
	}
}

int main() {

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> coin[i];
		}

		cin >> M;

		solve();

		cout << dp[N][M] << "\n";

		memset(dp, 0, sizeof(dp));
	}

	return 0;
}
