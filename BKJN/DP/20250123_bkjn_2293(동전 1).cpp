#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10002

int n, k;
int dp[MAX];
vector <int> coin;

int main(void) {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x = 0;

		cin >> x;

		coin.push_back(x);
	}

	sort(coin.begin(), coin.end());

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	cout << dp[k] << "\n";

	return 0;
}
