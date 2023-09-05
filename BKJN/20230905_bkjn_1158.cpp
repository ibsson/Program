#include <stdio.h>

int main(void) {

	int N = 0;
	int K = 0;
	int num[5001] = { 0 };
	int room[5001] = { 0 };

	for (int i = 1; i < sizeof(num) / sizeof(int); i++) {
		num[i] = i;
	}

	scanf("%d %d", &N, &K);

	int cnt = K;
	int tmp = 1;
	int a = 1;

	while (1) {
		for (int i = 0; i < K; i++) {

			if (tmp > N) {
				tmp = 1;
			}

			if (num[tmp] == 0) {
				while (1) {
					if (tmp > N) {
						tmp = 1;
					}
					if (num[tmp] != 0) break;
					tmp++;
				}
			}

			if (i + 1 == cnt) {
				num[tmp] = 0;
				room[a] = tmp;
				a++;
			}
			tmp++;
		}
		if (a == N + 1) break;
	}

	printf("<");

	for (int i = 1; i <= N; i++) {
		printf("%d", room[i]);
		if (i == N) break;
		printf(",");
		printf(" ");
	}

	printf(">");

	return 0;
}
