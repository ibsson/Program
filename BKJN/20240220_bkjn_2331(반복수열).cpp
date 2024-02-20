#include <stdio.h>

int num[10001] = { 0 };

int get_power(int a, int p) {

	int tmp_1 = 0, tmp_2 = 1, result = 0;
	
	while (a != 0) {
		tmp_1 = (a % 10);

		for (int i = 0; i < p; i++) {
			tmp_2 *= tmp_1;
		}

		result += tmp_2;
		tmp_2 = 1;

		a /= 10;
	}

	return result;
}

int main(void) {

	int A = 0, P = 0, i = 0, cnt = 0, check = 0;;

	scanf("%d %d", &A, &P);

	num[0] = A;

	while (check == 0) {
		i++;

		num[i] = get_power(num[i - 1], P);

		for (int j = 0; j < i; j++) {
			if (num[j] == num[i]) {
				printf("%d\n", j);
				check = 1;

				break;
			}
		}
	}

	printf("");

	return 0;
}
