#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10002
#define INF 100000

int n, k;
int dp[MAX];
vector <int> coin;

int main(void) {

	cin >> n >> k;

	int x = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;

		coin.push_back(x);
	}

	sort(coin.begin(), coin.end());

	for (int i = 1; i <= k; i++) {
		if (i % coin[0] == 0) dp[i] = i / coin[0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (j == coin[i]) dp[j] = 1;
			else if (dp[j - coin[i]] == 0) continue;
			else if (dp[j] == 0) dp[j] = dp[j - coin[i]] + 1;
			else dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 0) cout << "-1\n";
	else cout << dp[k] << "\n";

	return 0;
}
