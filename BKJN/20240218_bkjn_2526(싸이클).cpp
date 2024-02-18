#include <stdio.h>

int main(void) {

	int N = 0, P = 0, tmp = 0, cnt = 0, i = 0;
	int remain[1001] = { 0 };

	scanf("%d %d", &N, &P);

	remain[0] = N;

	while (cnt == 0) {
		i++;
		remain[i] = (remain[i - 1] * N) % P;

		for (int j = 0; j < i; j++) {
			if (remain[i] == remain[j]) {
				cnt = i - j;
				break;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
