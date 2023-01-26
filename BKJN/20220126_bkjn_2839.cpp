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
