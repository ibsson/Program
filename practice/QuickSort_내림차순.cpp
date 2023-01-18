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
