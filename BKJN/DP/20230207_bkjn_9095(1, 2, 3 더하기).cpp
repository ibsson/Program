#include <iostream>
#define MAX 12
using namespace std;

int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}

/*
#include <stdio.h>

int main() {

	int T = 0;
	int num = 0;
	int sum[12] = { 0, 1, 2, 4 };

	scanf_s("%d", &T);

	for (int k = 4; k < 12; k++) {
		sum[k] = sum[k - 1] + sum[k - 2] + sum[k - 3];
	}

	for (int i = 0; i < T; i++) {
		scanf_s("%d", &num);

		printf("%d\n", sum[num]);
	}

	return 0;
}
*/
