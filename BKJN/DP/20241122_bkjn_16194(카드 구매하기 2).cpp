#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	int num[1002] = { 0 };
	int dp[1002] = { 0 };

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = num[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = (i - 1); j >= i / 2; j--) {
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}
