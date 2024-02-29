#include <stdio.h>

int main(void) {

	int M = 0, N = 0, min = 0, sum = 0, cnt = 0;

	scanf("%d", &M);
	scanf("%d", &N);

	for (int i = M; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0 && i / j == j) {
				sum += i;
				if (cnt == 0) min = i;
				cnt++;
			}
		}
	}

	if (sum == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}

	return 0;
}
