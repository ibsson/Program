#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int len = 0, time = 0;
	char* word = (char*)malloc(sizeof(char) * 16);

	scanf("%s", word, 16);
	
	len = strlen(word);

	for (int i = 0; i < len; i++) {
		if (word[i] >= 65 && word[i] <= 67) {
			time += 3;
		}
		else if (word[i] >= 68 && word[i] <= 70) {
			time += 4;
		}
		else if (word[i] >= 71 && word[i] <= 73) {
			time += 5;
		}
		else if (word[i] >= 74 && word[i] <= 76) {
			time += 6;
		}
		else if (word[i] >= 77 && word[i] <= 79) {
			time += 7;
		}
		else if (word[i] >= 80 && word[i] <= 83) {
			time += 8;
		}
		else if (word[i] >= 84 && word[i] <= 86) {
			time += 9;
		}
		else if (word[i] >= 87 && word[i] <= 90) {
			time += 10;
		}
	}

	printf("%d\n", time);

	return 0;
}
