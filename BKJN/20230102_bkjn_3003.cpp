#include <stdio.h>

int main() {

	int num[6] = { 0 };
	int chess[6] = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < (int)(sizeof(num) / sizeof(int)); i++) {
		scanf_s("%d", &num[i]);
	}

	for (int i = 0; i < (int)(sizeof(num) / sizeof(int)); i++) {
		num[i] = chess[i] - num[i];
	}

	for (int i = 0; i < (int)(sizeof(num) / sizeof(int)); i++) {
		printf("%d ", num[i]);
	}

	return 0;
}
