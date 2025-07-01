#include <stdio.h>

int main() {

	int N = 0;
	int num[51] = { 0 };
	int max = -10;
	int min = 1000001;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {
		if (max < num[i]) max = num[i];
		if (min > num[i]) min = num[i];
	}

	printf("%d\n", (max * min));

	return 0;
}
