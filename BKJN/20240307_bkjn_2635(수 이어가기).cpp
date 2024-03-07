#include <stdio.h>

int num_1[1000] = { 0 };
int num_2[1000] = { 0 };

int main(void) {

	int N = 0, i = 1, max = -1, p = 0;

	scanf("%d", &N);
	num_1[0] = N;

	while (i <= N){
		p = 2;
		num_1[1] = i;

		while (1) {
			num_1[p] = num_1[p - 2] - num_1[p - 1];
			
			if (num_1[p] < 0) {
				break;
			}

			p++;
		}

		if (max < p) {
			max = p;
			for (int j = 0; j < p; j++) {
				num_2[j] = num_1[j];
			}
		}

		for (int j = 2; j <= p; j++) {
			num_1[j] = 0;
		}

		i++;
	}

	printf("%d\n", max);

	for (int j = 0; j < max; j++) {
		printf("%d", num_2[j]);
		if (j == (max - 1)) {
			printf("\n");
			break;
		}

		printf(" ");
	}

	return 0;
}
