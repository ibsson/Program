#include <stdio.h>
#include <string.h>

char document[2502] = { 0 }; //fgets는 \n\0이 같이 저장되기 때문에 2칸 더 만듦
char search_word[52] = { 0 }; //마찬가지

int get_result(int len) {

	int i = 0, tmp = 0, cnt = 0, result = 0;

	while (1) {

		tmp = i;
		cnt = 0;

		for (int j = 0; j < len; j++) {
			if (document[tmp] == NULL) return result;

			if (search_word[j] == document[tmp]) {
				cnt++;
			}
			else break;
			tmp++;
		}

		if (cnt == len) {
			result++;

			i += len;
		}
		else i++;

		if (document[i] == NULL) return result;
	}
}

int main(void) {

	fgets(document, sizeof(document), stdin);
	fgets(search_word, sizeof(search_word), stdin);

	int len = strlen(search_word) - 1; //개행문자도 세버림

	int result = get_result(len);

	printf("%d\n", result);

	return 0;
}
