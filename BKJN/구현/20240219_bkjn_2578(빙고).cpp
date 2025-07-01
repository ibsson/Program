#include <stdio.h>

int bingo[5][5] = { 0 };
int horizontal[5] = { 0 };
int column[5] = { 0 };
int tmp = 0;

void horizontal_check() {

	int cnt = 0;

	for (int j = 0; j < 5; j++) {

		if (horizontal[j] == 1) continue;

		cnt = 0;

		for (int k = 0; k < 5; k++) {
			if (bingo[j][k] == 0) {
				cnt++;
			}
			else break;
		}

		if (cnt == 5) {
			tmp++;
			horizontal[j] = 1;
		}
	} //가로줄 검사
}

void column_check() {

	int cnt = 0;

	for (int j = 0; j < 5; j++) {

		if (column[j] == 1) continue;

		cnt = 0;

		for (int k = 0; k < 5; k++) {
			if (bingo[k][j] == 0) {
				cnt++;
			}
			else break;
		}

		if (cnt == 5) {
			tmp++;
			column[j] = 1;
		}
	} //세로줄 검사
}

int diagonal_line_check_1() {

	int cnt = 0;

	for (int j = 0; j < 5; j++) {
		if (bingo[j][j] == 0) {
			cnt++;
		}
	}

	if (cnt == 5) {
		tmp++;
		return 1;
	}
	//대각선 검사 (\)

	return 0;
}

int diagonal_line_check_2() {
	
	int cnt = 0;

	for (int j = 0; j < 5; j++) {
		if (bingo[j][4 - j] == 0) {
			cnt++;
		}
	}

	if (cnt == 5) {
		tmp++;
		return 1;
	}
	//대각선 검사 /

	return 0;
}

int main(void) {

	int N = 0, result = 1, check_1 = 0, check_2 = 0, check_3 = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &bingo[i][j]);
		}
	}

	for (int i = 0; i < 25; i++) {
		scanf("%d", &N);

		check_1 = 0;

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (bingo[j][k] == N) {
					bingo[j][k] = 0;
					check_1 = 1;
					break;
				}
			}
			if (check_1 == 1) break;
		}

		horizontal_check();

		if (tmp == 3) {
			printf("%d\n", result);
			break;
		}

		column_check();

		if (tmp == 3) {
			printf("%d\n", result);
			break;
		}

		if (check_2 == 0) {
			check_2 = diagonal_line_check_1();
		}

		if (tmp == 3) {
			printf("%d\n", result);
			break;
		}

		if (check_3 == 0) {
			check_3 = diagonal_line_check_2();
		}

		if (tmp == 3) {
			printf("%d\n", result);
			break;
		}

		result++;
	}

	return 0;
}
