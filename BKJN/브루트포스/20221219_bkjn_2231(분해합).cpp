#include <stdio.h>

int cal(int n) {

	int room = 0;

	for (int i = 1; i <= n; i++) {
		int tmp = i;
		int sum = i;
		while (tmp != 0) {
			sum += (tmp % 10);
			tmp /= 10;
		}
		if (sum == n) {
			room = i;
			break;
		}
	}

	return room;
}

int main() {

	int num = 0;

	scanf_s("%d", &num);

	int result = cal(num);

	printf("%d\n", result);

	return 0;
}

/*
#include <stdio.h>

int main() {

	int num = 0;
	int room = 0;

	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		if (i < 10) {
			room = i + (i % 10);
			if (room == num) {
				printf("%d\n", i);
				break;
			}
		}
		else if (i < 100 && i >= 10) {
			room = i + (i / 10) + (i % 10);
			if (room == num) {
				printf("%d\n", i);
				break;
			}
		}
		else if (i < 1000 && i >= 100) {
			room = i + (i / 100) + (i % 100 / 10) + (i % 100 % 10);
			if (room == num) {
				printf("%d\n", i);
				break;
			}
		}
		else if (i < 10000 && i >= 1000) {
			room = i + (i / 1000) + (i % 1000 / 100) + (i % 1000 % 100 / 10) + (i % 1000 % 100 % 10);
			if (room == num) {
				printf("%d\n", i);
				break;
			}
		}
		else if (i < 100000 && i >= 10000) {
			room = i + (i / 10000) + (i % 10000 / 1000) + (i % 10000 % 1000 / 100) + (i % 10000 % 1000 % 100 / 10) + (i % 10000 % 1000 % 100 % 10);
			if (room == num) {
				printf("%d\n", i);
				break;
			}
		}
		else if (i < 1000000 && i >= 10000) {
			room = i + (i / 100000) + (i % 100000 / 10000) + (i % 100000 % 10000 / 1000) + (i % 100000 % 10000 % 1000 / 100) + (i % 1000000 % 10000 % 1000 % 100 / 10) + (i % 100000 % 10000 % 1000 % 100 % 10);
			if (room == num) {
				printf("%d\n", i);
				break;
			}
		}
		if (i == num && num != room) {
			printf("0\n");
			break;
		}
	}

	return 0;
}
*/
