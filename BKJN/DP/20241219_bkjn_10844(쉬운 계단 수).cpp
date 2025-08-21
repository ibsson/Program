#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[101][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] += (dp[i - 1][j + 1]);
			}
			else if(j == 9) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			else {
				dp[i][j] += (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
			}

			dp[i][j] %= MOD;
		}
	}

	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res += dp[N][i];
		res %= MOD;
	}

	cout << res << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

#define MOD 1000000000

int dp[102][10];
int N;

int main(void) {

	cin >> N;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 0; i <= 9; i++) {
		if (i == 0 || i == 1 || i == 9) dp[2][i] = 1;
		else dp[2][i] = 2;
	}

	for (int i = 3; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = (dp[i - 1][1] % MOD);
			else if (j == 9) dp[i][j] = (dp[i - 1][8] % MOD);
			else {
				dp[i][j] = (dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD);
				dp[i][j] %= MOD;
			}
		}
	}

	int result = 0;

	for (int i = 0; i <= 9; i++) {
		result += dp[N][i];
		result %= MOD;
	}

	cout << result % MOD << "\n";

	return 0;
}
*/
