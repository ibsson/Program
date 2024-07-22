#include <stdio.h>

int main(void) {

	int N = 0;

	scanf("%d", &N);

	int a = 1, i = 0;

	while (1) {
		a += 6 * i;

		i++;

		if (a >= N) break;
	}

	printf("%d\n", i);

	return 0;
}
