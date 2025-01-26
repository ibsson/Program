#include<iostream>
using namespace std;

#define MAX 1000000
int N;
int color[1001][3];
int dp[1001][3];
int ans = MAX;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}

	for (int RGB = 0; RGB < 3; RGB++) {
		for (int i = 0; i < 3; i++) {
			if (i == RGB) dp[0][i] = color[0][i];
			else dp[0][i] = MAX;
		}

		for (int i = 1; i < N; i++) {
			dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i < 3; i++) {
			if (i == RGB) continue;
			else ans = min(ans, dp[N - 1][i]);
		}
	}

	cout << ans << "\n";

	return 0;
}
