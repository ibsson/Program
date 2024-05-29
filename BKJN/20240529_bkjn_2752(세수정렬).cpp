//버블 정렬 풀이

#include <stdio.h>

void BubbleSort(int num[], int len) {

	int tmp = 0;

	for (int i = 0; i < (len - 1); i++) {
		for (int j = 0; j < (len - (i + 1)); j++) {
			if (num[j] > num[j + 1]) {
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
}

int main(void) {

	int num[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &num[i]);
	}

	BubbleSort(num, 3);

	for (int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}
