#include <stdio.h>

int main() {

	int A, B, C;
	int num[10] = { 0 };
	int portion, rest;


	scanf("%d\n%d\n%d", &A, &B, &C);

	portion = A * B * C;

	for ( ; ; ) {
		rest = portion % 10;
		num[rest]++;

		portion = portion / 10;
		if (portion == 0) {
			break;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		printf("%d\n", num[i]);
	}
	
	return 0;
}
