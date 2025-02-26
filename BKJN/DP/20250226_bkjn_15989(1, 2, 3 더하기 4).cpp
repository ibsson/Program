#include <iostream>
#include <string.h>
using namespace std;

int dp[3][10001];

void solve(int n) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0) {
				dp[i][j] = 1;
			}
			else {
				if (j - (i + 1) < 0) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] + dp[i][j - (i + 1)];
			}
		}
	}
}

int main() {

	int T = 0, n = 0;

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> n;

		solve(n);

		cout << dp[2][n] << "\n";

		memset(dp, 0, sizeof(dp));
	}

	return 0;
}
