#include <stdio.h>

int max = -100000000;
int min = 100000000;
int num[1000000];

int main() {

	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {
		if (num[i] < min) {
			min = num[i];
		}
	}
	printf("%d ", min);

	for (int i = 0; i < N; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}
	printf("%d", max);

	return 0;
}
