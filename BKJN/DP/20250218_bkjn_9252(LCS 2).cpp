#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 1002

string a, b;
int LCS[MAX][MAX];
string result;

int main() {

	cin >> a;
	cin >> b;

	int a_len = a.length(), b_len = b.length();

	for (int i = 1; i <= a_len; i++) {
		for (int j = 1; j <= b_len; j++) {
			if (a[i - 1] == b[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	int i = a_len;
	int j = b_len;
	while (i >= 1 && j >= 1) {
		if (LCS[i][j] > LCS[i - 1][j] && LCS[i - 1][j] == LCS[i][j - 1] && LCS[i][j - 1] == LCS[i - 1][j - 1]) {
			result += b[j - 1];
			i--;
			j--;
		}
		else if (LCS[i - 1][j] > LCS[i][j - 1] && LCS[i - 1][j] == LCS[i][j]) {
			i--;
		}
		else if (LCS[i - 1][j] < LCS[i][j - 1] && LCS[i][j - 1] == LCS[i][j]) {
			j--;
		}
		else {
			j--;
		}
	}

	reverse(result.begin(), result.end());
	cout << LCS[a_len][b_len] << "\n";
	cout << result << "\n";

	return 0;
}
