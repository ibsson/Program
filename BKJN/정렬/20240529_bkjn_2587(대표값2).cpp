#include <stdio.h>
#include <string.h>

void InsertionSort(int data[], int len) {

	int value = 0;

	for (int i = 1; i < len; i++) {
		if (data[i - 1] <= data[i]) continue;

		value = data[i];

		for (int j = 0; j < i; j++) {
			if (data[j] > value) {
				memmove(&data[j + 1], &data[j], sizeof(data[0]) * (i - j)); 
				data[j] = value; 
				break;
			}
		}
	}
}

int main(void) {

	int num[5] = { 0 };
	int average = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}

	InsertionSort(num, 5);

	for (int i = 0; i < 5; i++) {
		average += num[i];
	}

	average /= 5;

	printf("%d\n", average);
	printf("%d\n", num[2]);

	return 0;
}
