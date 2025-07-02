#include <stdio.h>

int main(void) {

	int N = 0;
	long long int len[81] = { 0 };

	scanf("%d", &N);

	len[1] = 4;
	len[2] = 6;

	for (int i = 3; i <= N; i++) {
		len[i] = len[i - 1] + len[i - 2];
	}

	printf("%lld\n", len[N]);

	return 0;
}

/*
피보나치 수열과 비슷한 문제라서 쉽게 풀었다.
*/
