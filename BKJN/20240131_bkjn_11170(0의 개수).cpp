#Sol_2

#include <stdio.h>

int check_0(int n, int m) {

	int cnt = 0;
	for (int i = n; i <= m; i++) {
		if (i == 0) cnt++;
		int i2 = i;

		while (i2 > 0) {
			if (i2 % 10 == 0)cnt++;
			i2 /= 10;
		}

	}
	return cnt;
}

int main() {

	int T, N, M;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%d\n", check_0(N, M));
	}

}

#sol_1

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
