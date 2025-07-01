#include <stdio.h>

int main(void) {

	int num[2][31] = { 0 };
	int homework[29] = { 0 };

	for (int i = 1; i <= 30; i++) {
		num[0][i - 1] = i;
	}

	for (int i = 0; i < 28; i++) {
		scanf("%d", &homework[i]);

		num[1][homework[i] - 1]++;
	}

	for (int i = 0; i < 30; i++) {
		if (num[1][i] == 0) printf("%d\n", num[0][i]);
	}

	return 0;
}

/*
가볍게 뇌 풀어주는 문제로 풀어 본 문제다.
*/
