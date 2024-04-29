#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Check_Word(char* first, char* word, int len_first, int len_word) {

	int cnt = 0, check = 0;

	if (len_first > len_word) check = len_first;
	else check = len_word;

	for (int i = 0; i < len_first; i++) {
		for (int j = 0; j < len_word; j++) {
			if (first[i] == word[j]) {
				word[j] = 33;
				cnt++;
				break;
			}
		}
	}

	if (check - cnt >= 0 && check - cnt <= 1) return 1;

	return 0;
}

int main(void) {

	int N = 0, cnt = 0, len_first = 0, len_word = 0, check = 0;

	scanf("%d", &N);

	char* first = (char*)malloc(sizeof(char) * 10);
	char** word = (char**)malloc(sizeof(char*) * (N - 1)); //2차원 배열 열 동적할당

	scanf("%s", first, 10);

	for (int i = 0; i < (N - 1); i++) {
		word[i] = (char*)malloc(sizeof(char) * 10); //2차원 배열 행 동적할당
	}

	for (int i = 0; i < (N - 1); i++) {
		scanf("%s", word[i], 10);
	}

	len_first = strlen(first);

	for (int i = 0; i < (N - 1); i++) {
		len_word = strlen(word[i]);

		if (len_first - len_word == 1 || len_first - len_word == -1 || len_first - len_word == 0) {
			if (check = Check_Word(first, word[i], len_first, len_word) == 1) cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}

/*
#접근 방법
두 단어의 길이차이가 1 이하여야 한다.
위 조건을 만족할때 문자의 종류의 차이가 1 이하여야 한다.

되게 어렵게 풀었다. 처음에는 문자 하나하나 다 바꿔가며 무식하게 풀으려 했는데 안될 것 같아서 방법을 바꿨다.
무식하게 하는 방법은 가장 마지막에 생각해야 하는 것 같다.
문제를 보다보면 만족해야만 하는 조건이 나온다. 이 조건을 찾으면 문제를 쉽게 풀 수 있다.
그 조건을 찾는 것이 참 어렵지만 찾아내려고 계속 하다보면 나중에는 잘 찾게 될거라고 생각한다.
그리고 이번 문제에서는 2차원 배열을 포인터로 만드는 방법을 익혔다.
*/
