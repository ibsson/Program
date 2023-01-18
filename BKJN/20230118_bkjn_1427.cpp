#include <stdio.h>

long int room[10] = { 0 };

void quicksort(int L, int R) {

	int left = L;
	int right = R;
	int pivot = room[((L + R) / 2)];
	int num = 0;

	do {
		while (room[left] > pivot) left++;

		while (room[right] < pivot) right--;

		if (left <= right) {
			num = room[left];
			room[left] = room[right];
			room[right] = num;
			left++;
			right--;
		}

	} while (left <= right);

	if (L < right) quicksort(L, right);

	if (left < R) quicksort(left, R);

}

int get(int N) {

	int cnt = 0;
	
	for (int i = 0; i < (int)(sizeof(room)/sizeof(int)); i++) {
		N /= 10;
		cnt++;
		if (N == 0) break;
	}

		return cnt;
}

int main() {

	int N = 0;

	scanf_s("%d", &N);

	int cnt = get(N);

	for (int i = 0; i < cnt; i++) {
		room[i] = N % 10;
		N /= 10;
	}

	quicksort(0, (cnt - 1));

	for (int i = 0; i < cnt; i++) {
		printf("%d", room[i]);
	}

	return 0;
}
