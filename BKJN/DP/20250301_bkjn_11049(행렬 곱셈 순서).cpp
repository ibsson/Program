#include <iostream>
using namespace std;

#define INF 1e9

int N;
int arr[501][2];
int dp[501][501];

void solve() {
	for (int len = 1; len < N; len++) {
		for (int i = 0; i + len < N; i++) {
			int j = i + len;
			dp[i][j] = INF;

			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1]);
			}
		}
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	solve();

	cout << dp[0][N - 1] << "\n";

	return 0;
}
