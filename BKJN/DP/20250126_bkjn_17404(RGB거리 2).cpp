#include <iostream>
#define MAX 1002
#define INF 1000000
using namespace std;

int home[MAX][3];
int dp[MAX][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> home[i][0] >> home[i][1] >> home[i][2];
	}

	int res = INF;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 3; k++) {
				dp[j][k] = INF;
			}
		}
		dp[0][0] = home[0][0], dp[0][1] = home[0][1], dp[0][2] = home[0][2];

		for (int j = 1; j < N; j++) {
			if (j == 1) {
				for (int k = 0; k < 3; k++) {
					if (i == k) continue;
					
					dp[j][k] = dp[j - 1][i] + home[j][k];
				}
			}
			else {
				dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + home[j][0];
				dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + home[j][1];
				dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + home[j][2];
			}
		}

		for (int j = 0; j < 3; j++) {
			if (j == i) continue;

			res = min(res, dp[N - 1][j]);
		}
	}
	
	cout << res << '\n';

	return 0;
}

/*
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
*/
