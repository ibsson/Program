/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* first = (char*)malloc(sizeof(char) * 10);
int len_first;

int Same_Composition_Check(char *word) {

	int len_word = strlen(word);
	int cnt_1 = 1, cnt_2 = 0, tmp = 0;

	for (int i = 0; i < len_first; i++) {
		cnt_1 = 1, cnt_2 = 0;

		for (int j = (i + 1); j < len_first; j++) {
			if (first[i] == first[j]) {
				cnt_1++;
			}
		}
		for (int j = 0; j < len_word; j++) {
			if (first[i] == word[j]) {
				cnt_2++;
			}
		}

		if (cnt_1 != cnt_2) {
			return 0;
		}
	}

	return 1;
}

int Subtract_Check(char* word) {

	int len_word = strlen(word);
	int cnt = 0, check = 0;
	char* copy = (char*)malloc(sizeof(char) * 10);

	for (int i = 0; i < len_word; i++) {

		cnt = 0;

		for (int j = 0; j < len_word; j++) {
			if (i == j) continue;
			else copy[cnt] = word[j];
			cnt++;
		}

		check = Same_Composition_Check(copy);

		if (check == 1) return 1;

		for (int j = 0; j < len_word; j++) {
			copy[j] = 0;
		}
	}

	return 0;
}

int Plus_Check(char* word) {

	int len_word = strlen(word);
	int check = 0;
	char* copy = word;

	for (int i = 65; i <= 90; i++) {
		copy[len_word] = i;
		check = Same_Composition_Check(copy);

		if (check == 1) return 1;
	}

	return 0;
}


int Change_Check(char* word) {

	int len_word = strlen(word);
	int cnt = 0, check = 0;
	char* copy = word;

	for (int i = 0; i < len_word; i++) {
		for (int j = 65; j <= 90; j++) {
			copy[i] = j;
			check = Same_Composition_Check(copy);

			if (check == 1) return 1;
		}
	}

	return 0;
}

int main(void) {

	int N = 0, cnt = 0;
	char** word = (char**)malloc(sizeof(char*) * 100);

	for (int i = 0; i < 100; i++) {
		word[i] = (char*)malloc(sizeof(char) * 10);
	}

	scanf_s("%d", &N);

	scanf_s("%s", first, sizeof(first));

	len_first = strlen(first);

	for (int i = 0; i < (N - 1); i++) {
		scanf_s("%s", word[i], sizeof(word[i]));

		if (Same_Composition_Check(word[i]) == 1) {
			cnt++;
		}
		else if (Subtract_Check(word[i]) == 1) {
			cnt++;
		}
		else if (Plus_Check(word[i]) == 1) {
			cnt++;
		}
		else if (Change_Check(word[i]) == 1) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
*/
