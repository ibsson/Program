#include <stdio.h>

int main(void) {

	int N, M = 0;
	char cas[51][51];
	int cnt_row = 0;
	int cnt_col = 0;
	int tmp = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", cas[i], 51);
	}

	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int k = 0; k < M; k++) {
			if (cas[i][k] != 'X') {
				tmp++;
				if (tmp == M) {
					cnt_row++;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		tmp = 0;
		for (int k = 0; k < N; k++) {
			if (cas[k][i] != 'X') {
				tmp++;
				if (tmp == N) {
					cnt_col++;
				}
			}
		}
	}

	if (cnt_row > cnt_col) printf("%d\n", cnt_row);
	else printf("%d\n", cnt_col);

	return 0;
}
