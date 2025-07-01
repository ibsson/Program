#include <stdio.h>

int main(void) {

	int N = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = i; j < N; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
