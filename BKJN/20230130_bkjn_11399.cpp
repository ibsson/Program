#include <stdio.h>

int time[1001] = { 0 };

void quicksort(int L, int R) {

	int left = L;
	int right = R;
	int pivot = time[((L + R) / 2)];
	int room = 0;

	do {
		while (time[left] < pivot) left++;

		while (time[right] > pivot) right--;

		if (left <= right) {
			room = time[left];
			time[left] = time[right];
			time[right] = room;
			left++;
			right--;
		}

	} while (left <= right);

	if (L < right) quicksort(L, right);

	if (left < R) quicksort(left, R);

}

int main() {

	int N = 0;
	int sum = 0;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &time[i]);
	}

	quicksort(0, (N - 1));

	for (int i = 0; i < N; i++) {
		for (int k = 0; k <= i; k++) {
			sum += time[k];
		}
	}

	printf("%d\n", sum);

	return 0;
}
