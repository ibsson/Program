#include <iostream>
using namespace std;

const int mod = 1e9 + 9;

long long int dp[1000002] = { 0 };

void Calculate_Dp(int n);

int main(void) {

	int T = 0;

	cin >> T;

	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	int n = 0;

	for (int i = 0; i < T; i++) {
		cin >> n;

		Calculate_Dp(n);
	}

	return 0;
}

void Calculate_Dp(int n) {

	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] % mod) + (dp[i - 2] % mod) + (dp[i - 3] % mod);
	}

	cout << dp[n] % mod << endl;
}
