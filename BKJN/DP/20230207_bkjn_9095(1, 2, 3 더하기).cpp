#include <stdio.h>

int main() {

	int T = 0;
	int num = 0;
	int sum[12] = { 0, 1, 2, 4 };

	scanf_s("%d", &T);

	for (int k = 4; k < 12; k++) {
		sum[k] = sum[k - 1] + sum[k - 2] + sum[k - 3];
	}

	for (int i = 0; i < T; i++) {
		scanf_s("%d", &num);

		printf("%d\n", sum[num]);
	}

	return 0;
}
