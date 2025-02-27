#include <iostream>
#include <string>
using namespace std;

string str;
int dp[2500][2500];
int min_cut[2500];

int main() {

	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		dp[i][i] = 1;
	}

	for (int i = 0; i <= (len - 2); i++) {
		if (str[i] == str[i + 1]) dp[i][i + 1] = 1;
	}

	for (int i = (len - 2); i >= 0; i--) {
		for (int j = (i + 1); j < len; j++) {
			if (str[i] == str[j] && dp[i + 1][j - 1] == 1) dp[i][j] = 1;
		}
	}

	for (int i = 0; i < len; i++) {
		if (dp[0][i]) {
			min_cut[i] = 1;
		}
		else {
			min_cut[i] = (i + 1);
			for (int j = 1; j <= i; j++) {
				if (dp[j][i]) {
					min_cut[i] = min(min_cut[i], min_cut[j - 1] + 1);
				}
			}
		}
	}

	cout << min_cut[len - 1] << "\n";

	return 0;
}
