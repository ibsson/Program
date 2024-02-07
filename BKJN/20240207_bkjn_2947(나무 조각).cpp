#include <stdio.h>

int num[5] = { 0 };

void sort() {

	int tmp = 0;
	
	for (int i = 0; i < 4; i++) {
		if (num[i] > num[i + 1]) {
			tmp = num[i];
			num[i] = num[i + 1];
			num[i + 1] = tmp;
		}
		else continue;

		for (int j = 0; j < 5; j++) {
			printf("%d", num[j]);

			if (j == 4) {
				printf("\n");
				break;
			}

			printf(" ");
		}
	}

}

int main(void) {

	int a = 0;
	int check[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}

	while (1) {
		for (int i = 0; i < 5; i++) {
			if (num[i] != check[i]) {
				a = 1;
				break;
			}
			else {
				a = 0;
			}
		}

		if (a == 1) sort();
		else break;
	}

	return 0;
}
