#include <iostream>
#include <string.h>
using namespace std;

#define INF 1e9
#define MAX 501

int arr[MAX];
int dp[MAX][MAX];
int perfix_sum[MAX];

void sum(int len) {
	perfix_sum[0] = 0;
	for (int i = 1; i <= len; i++) {
		perfix_sum[i] = perfix_sum[i - 1] + arr[i - 1];
	}
}

int calculate(int i, int j) {
	return perfix_sum[j + 1] - perfix_sum[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 0, K = 0;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> K;

		for (int i = 0; i < K; i++) {
			cin >> arr[i];
		}

		sum(K);

		for (int len = 1; len < K; len++) {
			for (int i = 0; i + len < K; i++) {
				int j = i + len;
				dp[i][j] = INF;

				for (int k = i; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + calculate(i, j));
				}
			}
		}

		cout << dp[0][K - 1] << "\n";

		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		memset(perfix_sum, 0, sizeof(perfix_sum));
	}

	return 0;
}
