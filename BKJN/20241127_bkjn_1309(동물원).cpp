#include <iostream>
using namespace std;

int dp[100001][3];

int main(void) {

	int N = 0, mod = 9901;

	cin >> N;

	dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}

	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % mod << endl;

	return 0;
}
