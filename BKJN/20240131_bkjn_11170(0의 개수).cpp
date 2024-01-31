#include <stdio.h>

int get_len(int N) {

	int len = 1;

	while (1) {
		if (N / 10 == 0) return len;

		len++;
		N /= 10;
	}
}

int main(void) {

	int N = 0;
	int M = 0;
	int T = 0;
	int cnt = 0;
	int len = 0;
	int tmp = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		scanf("%d %d", &N, &M);

		for (int j = N; j <= M; j++) {

			len = get_len(j);
			tmp = j;

			for (int k = 0; k < len; k++) {
				if (tmp % 10 == 0) {
					cnt++;
				}
				tmp /= 10;
			}
		}

		printf("%d\n", cnt);
		
		cnt = 0;
	}

	return 0;
}
