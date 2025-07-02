//qsort 풀이

#include <stdio.h>
#include <stdlib.h>

int ComparePoint(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2) return 1;
	else if (*elem1 < *elem2) return -1;
	else return 0;
}

int main(void) {

	int num[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
	}

	qsort((void*)num, 3, sizeof(int), ComparePoint);

	for (int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}

//퀵 정렬 풀이

#include <stdio.h>

void Swap(int* A, int* B) {

	int tmp = *A;
	*A = *B;
	*B = tmp;
}

int Partition(int data[], int Left, int Right) {

	int First = Left;
	int Pivot = data[First];

	Left++;

	while (Left <= Right) {
		while (data[Left] <= Pivot && Left < Right) {
			Left++;
		}
		while (data[Right] >= Pivot && Left <= Right) {
			Right--;
		}

		if (Left < Right) Swap(&data[Left], &data[Right]);
		else break;
	}

	Swap(&data[First], &data[Right]);

	return Right;
}

void QuickSort(int data[], int Left, int Right) {

	if (Left < Right) {
		int Index = Partition(data, Left, Right);

		QuickSort(data, Left, (Index - 1));
		QuickSort(data, (Index + 1), Right);
	}
}

int main(void) {

	int num[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
	}

	QuickSort(num, 0, 2);

	for (int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}

//삽입 정렬 풀이

#include <stdio.h>
#include <string.h>

void InsertionSort(int num[], int len) {

	int value = 0;

	for (int i = 1; i < len; i++) {
		if (num[i - 1] <= num[i]) continue;

		value = num[i];

		for (int j = 0; j < i; j++) {
			if (num[j] > value) {
				memmove(&num[j + 1], &num[j], sizeof(num[0]) * (i - j)); //메모리의 내용을 이동시키는 함수. 배열처럼 연속된 데이터를 단번에 이동시킬때 유용
				num[j] = value;                                            //ㄴ 1.원본 데이터가 옮겨갈 메모리의 주소, 2.원본 데이터 주소, 3.이동시킬 바이트 양
				break;
			}
		}
	}
}

int main(void) {

	int num[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		scanf("%d", &num[i]);
	}

	InsertionSort(num, 3);

	for (int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}

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
		scanf("%d", &num[i]);
	}

	BubbleSort(num, 3);

	for (int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}
