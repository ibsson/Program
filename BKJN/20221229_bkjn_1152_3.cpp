#include <stdio.h>

char word[1000001] = { 0 };

int get_word_start_pos() {

	for (int i = 0; i < (int)(sizeof(word) / sizeof(char)); i++) {
		if ('A' <= word[i] && word[i] <= 'z') return i;
		if (word[i] == '\n') return (-1);
	}
}

int main() {

	int cnt = 0;

	fgets(word, sizeof(word), stdin);

	for (int i = get_word_start_pos(); i < (int)(sizeof(word) / sizeof(char)); i++) {

		if (word[i] < 'A' || 'z' < word[i]) {

			if ('A' <= word[i - 1] && word[i - 1] <= 'z') {
				cnt++;
			}

			if (word[i] == NULL) break;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
