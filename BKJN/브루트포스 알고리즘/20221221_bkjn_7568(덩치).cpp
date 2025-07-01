#include <stdio.h>

int main() {

	int N = 0;
	int man[2][51] = { 0 };

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &man[0][i], &man[1][i]);
	}

	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int k = 0; k < N; k++) {
			if (man[0][i] < man[0][k] && man[1][i] < man[1][k]) {
				count++;
			}
		}
		printf("%d ", count);
	}

	return 0;
}
