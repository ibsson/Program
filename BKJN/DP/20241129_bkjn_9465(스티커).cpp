#include <iostream>
using namespace std;

int stiker[2][100002];
long long int dp[2][100002];

int main(void) {

	int T = 0, n = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> stiker[j][k];
				dp[j][k + 1] = stiker[j][k];
			}
		}

		if (n == 1) {
			int tmp = max(stiker[0][0], stiker[1][0]);
			cout << tmp << endl;
			continue;
		}

		dp[0][0] = 0, dp[1][0] = 0;
		long long int result = 0;

		for (int j = 2; j <= n; j++) {
			dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
			dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);

			int chk = max(dp[0][j], dp[1][j]);

			if (result < chk) result = chk;
		}

		cout << result << endl;
	}

	return 0;
}
