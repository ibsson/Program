#include <stdio.h>

int main() {

	char word[1000001] = { 0 };
	int cnt = 0;
	int a = 0;

	fgets(word, sizeof(word), stdin);

	for (int i = 0; i < sizeof(word); i++) {
		if (a == 0) {
			if (word[0] == ' ') {
				a++;
				if (word[1] == '\n') {
					a++;
					break;
				}
				continue;
			}
		}
		if (word[i] == ' ' && word[i - 1] != ' ' && word[i + 1] != '\n') cnt++;
		if (word[i] == NULL) break;
	}

	if (a == 2) {
		printf("0\n");
		return 0;
	}

	printf("%d\n", (cnt + 1));

	return 0;
}
