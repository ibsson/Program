#include <stdio.h>

int main(void) {

	int N, K = 0;
	int A = 1;
	int num[11] = { 0 };

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	int tmp = (N-1);
	int cnt = 0;

	while (1) {
		if (K == 0) break;

		if (K < num[tmp]) {
			tmp--;
		}
		else {
			K -= num[tmp];
			tmp = (N-1);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
