#include <stdio.h>

int cnt_row(int N, int M, char cas[][51]) {

	int tmp = 0;
	int row = 0;

	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int k = 0; k < M; k++) {
			if (cas[i][k] != 'X') {
				tmp++;
				if (tmp == M) {
					row++;
				}
			}
		}
	}

	return row;
}

int cnt_col(int N, int M, char cas[][51]) {

	int tmp = 0;
	int col = 0;

	for (int i = 0; i < M; i++) {
		tmp = 0;
		for (int k = 0; k < N; k++) {
			if (cas[k][i] != 'X') {
				tmp++;
				if (tmp == N) {
					col++;
				}
			}
		}
	}
	
	return col;
}

int main(void) {

	int N = 0;
	int M = 0;
	char cas[51][51];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", cas[i], 51);
	}

	int a = cnt_row(N, M, cas);
	int b = cnt_col(N, M, cas);

	if (a > b) printf("%d\n", a);
	else printf("%d\n", b);

	return 0;
}
