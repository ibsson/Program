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
		scanf_s("%d", &num[i]);
	}

	BubbleSort(num, 3);

	for (int i = 0; i < 3; i++) {
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}
