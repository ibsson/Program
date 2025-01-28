//20250128 복습
#include <iostream>
using namespace std;

#define MAX 10000

int main() {

	int N = 0;

	cin >> N;

	int cnt_5 = N / 5, ans = MAX;

	for (int i = 0; i <= cnt_5; i++) {
		int tmp = N - (5 * i), cnt = 0;

		cnt += i;
		cnt += tmp / 3;
		tmp %= 3;

		if (tmp == 0) ans = min(ans, cnt);
	}

	if (ans == MAX) cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}

/*
#include <stdio.h>

int main() {

	int N = 0;
	int num = 0;
	int cnt1 = 0;
	int cnt2 = 0;
		

	scanf_s("%d", &N);

	while (1) {
		if (N % 5 != 0) {
			N -= 3;
			cnt1++;
		}
		if (N % 5 == 0) {
			cnt2 = N / 5;
			break;
		}
		if (N < 0) {
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", cnt1 + cnt2);

	return 0;
}
*/
