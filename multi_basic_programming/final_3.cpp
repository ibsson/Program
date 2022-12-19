#include <stdio.h>

int main() {

	int num = 0;
	int cnt = 0;

	scanf_s("%d", &num);

	if (num == 1) {
		printf("0\n");
		return 0;
	}

	for (int i = (num + 1); i < (2 * num); i++) {
		for (int k = 2; k < i; k++) {
			if (i % k == 0) break;
			if ((k + 1) == i) {
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
