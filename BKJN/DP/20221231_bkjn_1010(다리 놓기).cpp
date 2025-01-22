#include <stdio.h>

int main() {

	int T = 0;
	int N = 0;
	int M = 0;

	scanf_s("%d", &T);

	for (int i = 0; i < T; i++) {

		int result = 1;

		scanf_s("%d %d", &N, &M);
		
		for (int k = 0; k < N; k++) {
			result *= M - k;
			result /= k + 1;
		}
		
		printf("%d\n", result);
	
	}

	return 0;
}
