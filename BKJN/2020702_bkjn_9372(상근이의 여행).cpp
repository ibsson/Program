#include <stdio.h>

int main(void) {

	int T = 0, N = 0, M = 0;

	scanf("%d", &T);

	int num1 = 0, num2 = 0;

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &num1, &num2);
		}

		printf("%d\n", (N - 1));
	}

	return 0;
}
