#include <iostream>
using namespace std;

int result;
string str1, str2;
int dp[4001][4001];

int main() {

	cin >> str1;
	cin >> str2;

	int len1 = str1.length(), len2 = str2.length();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}

			result = max(result, dp[i][j]);
		}
	}

	cout << result << "\n";

	return 0;
}
