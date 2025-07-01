#include <stdio.h>

int main() {

	int N = 0;
	int room = 0;
	int shelter = 0;
	int count[10] = { 0 };

	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++) {

		int temp = i;
		while (temp != 0) {
			count[temp % 10]++;
			temp /= 10;
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", count[i]);
	}

	return 0;
}
