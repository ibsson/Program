#include <stdio.h>

int main(void) {

	int A = 0, B = 0;
	int num_1[3] = { 0 };
	int num_2[3] = { 0 };

	scanf("%d %d", &A, &B);

	for (int i = 0; i < 3; i++) {
		num_1[i] = A % 10;
		A /= 10;

		num_2[i] = B % 10;
		B /= 10;
	}

	for (int i = 0; i < 3; i++) {
		if (num_1[i] == num_2[i]) continue;
		else if (num_1[i] > num_2[i]) {
			for (int j = 0; j < 3; j++) {
				printf("%d", num_1[j]);
			}
			printf("\n");
			break;
		}
		else if (num_1[i] < num_2[i]) {
			for (int j = 0; j < 3; j++) {
				printf("%d", num_2[j]);
			}
			printf("\n");
			break;
		}
	}

	return 0;
}
