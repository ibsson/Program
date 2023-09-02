#include <stdio.h>

int num[1001];

void eratos(int N, int K) {

	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		for (int h = 1; h * i <= N; h++) {
			if (num[h * i] != 1) cnt++;
			if (cnt == K) {
				printf("%d\n", h * i);
				break;
			}
			num[h * i] = 1;
		}
		if (cnt == K) break;
	}
}

int main(void) {

	int N, K = 0;

	scanf("%d", &N);
	scanf("%d", &K);

	eratos(N, K);

	return 0;
}
