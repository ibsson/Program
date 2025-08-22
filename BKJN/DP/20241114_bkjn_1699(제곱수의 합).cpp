#include <iostream>
#include <cmath>
#define MAX 100002
#define INF 1e9
using namespace std;

int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	dp[1] = 1, dp[2] = 2, dp[3] = 3;
	for (int i = 4; i <= N; i++) {
		dp[i] = INF;
		for (int j = 1; pow(j, 2) <= i; j++) {
			int tmp = pow(j, 2);
			dp[i] = min(dp[i], dp[i - tmp] + 1);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

int dp[100001] = { 0 };

int main(void) {

	int n = 0;

	cin >> n;

	dp[0] = 0; dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int min = 1000000;
		for (int j = 1; (j * j) <= i; j++) {
			int tmp = i - (j * j);
			if (min > dp[tmp]) min = dp[tmp];
		}

		dp[i] = min + 1;
	}

	cout << dp[n] << endl;

	return 0;
}
*/
