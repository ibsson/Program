#include <stdio.h>

char board[51][51];
int max = -1;

void check_max(int N) {

	int cnt = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[i][j] == board[i][j + 1]) {
				cnt++;
				
				if (max < cnt) {
					max = cnt;
				}
			}
			else {
				if (max < cnt) {
					max = cnt;

					cnt = 1;
				}
				else cnt = 1;
			}
		}

		if (max == N) return;

		cnt = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[j][i] == board[j + 1][i]) {
				cnt++;

				if (max < cnt) {
					max = cnt;
				}
			}
			else {
				if (max < cnt) {
					max = cnt;

					cnt = 1;
				}
				else cnt = 1;
			}
		}

		if (max == N) return;

		cnt = 1;
	}
}

void change_horizontal(int N) {

	int tmp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[i][j] != board[i][j + 1]) {

				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;

				check_max(N);

				if (max == N) return;

				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;
			}
		}
	}
}

void change_vertical(int N) {

	int tmp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[j][i] != board[j + 1][i]) {

				tmp = board[j][i];
				board[j][i] = board[j + 1][i];
				board[j + 1][i] = tmp;

				check_max(N);

				if (max == N) return;

				tmp = board[j][i];
				board[j][i] = board[j + 1][i];
				board[j + 1][i] = tmp;
			}
		}
	}
}

int main(void) {

	int N = 0, a = 0, b = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", board[i], sizeof(board[i]));
	}

	change_horizontal(N);

	if (max == N) {
		printf("%d\n", max);
		return 0;
	}

	change_vertical(N);

	printf("%d\n", max);

	return 0;
}
