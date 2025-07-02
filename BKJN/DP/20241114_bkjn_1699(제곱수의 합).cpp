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
