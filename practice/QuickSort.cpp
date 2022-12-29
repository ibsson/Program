#include <stdio.h>

int num[10000000] = { 0 };

void quicksort(int L, int R) {

	int left = L;
	int right = R;
	int pivot = num[((L + R) / 2)];
	int room = 0;

	do {
		while (num[left] < pivot) left++;

		while (num[right] > pivot) right--;

		if (left <= right) {
			room = num[left];
			num[left] = num[right];
			num[right] = room;
			left++;
			right--;
		}

	} while (left <= right);

	if (L < right) quicksort(L, right);

	if (left < R) quicksort(left, R);

}

int main() {

	int N = 0;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num[i]);
	}

	quicksort(0, (N - 1));

	for (int i = 0; i < N; i++) {
		printf("%d ", num[i]);
	}

	return 0;
}
