#include <stdio.h>

int main() {

	int N = 0;
	int M = 0;
	int room = 0;
	int num[100001] = { 0 };
	int i = 0;
	int j = 0;
	int result = 0;

	scanf_s("%d %d", &N, &M);

	for (int k = 1; k <= N; k++) {
		scanf_s("%d", &room);
		num[k] = num[k - 1] + room;
	}

	for (int k = 0; k < M; k++) {
		scanf_s("%d %d", &i, &j);
		if (i == 1) {
			result = num[j];
			printf("%d\n", result);
			continue;
		}
		result = num[j] - num[i - 1];
		printf("%d\n", result);
	}

	return 0;
}
