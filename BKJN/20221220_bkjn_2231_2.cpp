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
