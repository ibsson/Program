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

	int a = get_word_start_pos();
	
	if (a == -1) {
		printf("0\n");
		return 0;
	}

	for (int i = a; i < (int)(sizeof(word) / sizeof(char)); i++) {

		if (word[i] == ' ') cnt++;

		if (word[i] == '\n' && word[i - 1] == ' ') cnt--;

		if (word[i] == NULL) break;
	}

	printf("%d\n", (cnt + 1));

	return 0;
}
