#include <stdio.h>
#include <string.h>

char word[51] = { 0 };
char reversed_word[51] = { 0 };
char min_word[51] = { 0 }; //0으로 초기화 하면 NULL되는거임?

void check_alphabet(int len, int cnt) {

	if (cnt == 1) {
		strncpy(min_word, reversed_word, sizeof(min_word));
		return;
	}

	for (int i = 0; i < len; i++) {
		if (min_word[i] < reversed_word[i]) {
			break;
		}
		else if (min_word[i] == reversed_word[i]) {
			continue;
		}
		else if (min_word[i] > reversed_word[i]) {
			strncpy(min_word, reversed_word, sizeof(min_word));
			break;
		}
	}
}

void copy(char* arr, int start, int finish) {

	int pivot = 0;

	for (int i = start; i < finish; i++) {
		reversed_word[i] = arr[pivot];
		pivot++;
	}
}

void reverse(char* arr, int len) {

	int pivot = 1;
	char a;

	for (int i = 0; i < (len / 2); i++) {
		a = arr[i];
		arr[i] = arr[len - pivot];
		arr[len - pivot] = a;

		pivot++;
	}
}

void divide(int len) {

	char A[49] = { 0 };
	char B[49] = { 0 };
	char C[49] = { 0 };
	int tmp = 0, cnt = 1;

	for (int i = 0; i < (len - 2); i++) {
		for (int j = (i + 1); j < (len - 1); j++) {
			for (int k = 0; k <= i; k++) {
				A[tmp] = word[k];
				tmp++;
			}
			reverse(A, strlen(A));
			copy(A, 0, (i + 1));
			tmp = 0;
			
			for (int k = (i + 1); k <= j; k++) {
				B[tmp] = word[k];
				tmp++;
			}
			reverse(B, strlen(B));
			copy(B, (i + 1), (j + 1));
			tmp = 0;

			for (int k = (j + 1); k < len; k++) {
				C[tmp] = word[k];
				tmp++;
			}
			reverse(C, strlen(C));
			copy(C, (j + 1), len);
			tmp = 0;

			check_alphabet(len, cnt);
			cnt++;

			for (int k = 0; k < len; k++) {
				A[k] = 0;
				B[k] = 0;
				C[k] = 0;
			}
		}
	}
}

int main(void) {

	scanf("%s", word, 51);

	int len = strlen(word);

	divide(len);

	for (int i = 0; i < len; i++) {
		printf("%c", min_word[i]);
	}
	printf("\n");

	return 0;
}
