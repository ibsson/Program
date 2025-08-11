#include <iostream>
#include <string>
using namespace std;

#define MAX 1002

int LCS[MAX][MAX];

int main(void) {

	string a;
	string b;

	cin >> a;
	cin >> b;

	int a_len = a.length();
	int b_len = b.length();

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
	
	cout << LCS[a_len][b_len] << "\n";

	return 0;
}
