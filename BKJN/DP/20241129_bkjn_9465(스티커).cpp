#include <iostream>
#define MAX 100001
using namespace std;

int arr[2][MAX];
int dp[2][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][0] = arr[0][0], dp[1][0] = arr[1][0];
		int _max = 0;
		for (int i = 1; i < n; i++) {
			if (i > 1) {
				_max = max(dp[0][i - 2], dp[1][i - 2]);

				if (_max > dp[1][i - 1]) dp[0][i] = _max + arr[0][i];
				else dp[0][i] = dp[1][i - 1] + arr[0][i];

				if (_max > dp[0][i - 1]) dp[1][i] = _max + arr[1][i];
				else dp[1][i] = dp[0][i - 1] + arr[1][i];
			}
			else {
				dp[0][i] = dp[1][i - 1] + arr[0][i];
				dp[1][i] = dp[0][i - 1] + arr[1][i];
			}
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}

/*
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
*/
