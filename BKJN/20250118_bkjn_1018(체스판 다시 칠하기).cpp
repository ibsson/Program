#include <iostream>
using namespace std;

int N, M, min_result = 10000;
char chess[51][51];
char tmp[8][8];

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> chess[i];
	}

	for (int i = 0; i <= (N - 8); i++) {
		for (int j = 0; j <= (M - 8); j++) {
			int cnt1 = 0, cnt2 = 0, k = i, l = j;

			while (k != (i + 8)) {
				while (l != (j + 8)) {
					if (chess[k][l] != 'B') {
						cnt1++;
					}
					if (chess[k][l + 1] != 'W') {
						cnt1++;
					}
					if (chess[k + 1][l] != 'W') {
						cnt1++;
					}
					if (chess[k + 1][l + 1] != 'B') {
						cnt1++;
					}

					if (chess[k][l] != 'W') {
						cnt2++;
					}
					if (chess[k][l + 1] != 'B') {
						cnt2++;
					}
					if (chess[k + 1][l] != 'B') {
						cnt2++;
					}
					if (chess[k + 1][l + 1] != 'W') {
						cnt2++;
					}
					l += 2;
				}
				l = j;
				k += 2;
			}

			min_result = min(min_result, min(cnt1, cnt2));
		}
	}

	cout << min_result << "\n";

	return 0;
}
