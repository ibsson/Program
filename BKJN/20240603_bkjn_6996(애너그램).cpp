#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertionSort(char data[], int len) {

	char value;

	for (int i = 1; i < len; i++) {
		if (data[i - 1] <= data[i]) continue;

		value = data[i];

		for (int j = 0; j < i; j++) {
			if (data[j] > value) {
				memmove(&data[j + 1], &data[j], sizeof(data[0]) * (i - j));
				data[j] = value;
				break;
			}
		}
	}
}

int main(void) {

	int T = 0, len_1 = 0, len_2 = 0, check = 0;
	char* str_1 = (char*)malloc(sizeof(char) * 101);
	char* str_2 = (char*)malloc(sizeof(char) * 101);

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%s", str_1, 101);
		scanf("%s", str_2, 101);

		len_1 = strlen(str_1);
		len_2 = strlen(str_2);

		printf("%s & %s are ", str_1, str_2);
	
		InsertionSort(str_1, len_1);
		InsertionSort(str_2, len_2);

		check = strcmp(str_1, str_2);

		if (check == 0) printf("anagrams.\n");
		else printf("NOT anagrams.\n");

		for (int i = 0; i < len_1; i++) {
			str_1[i] = NULL;
		}

		for (int i = 0; i < len_2; i++) {
			str_2[i] = NULL;
		}
	}

	free(str_1);
	free(str_2);

	return 0;
}

/*
둘 다 알파벳 순서로 정렬해서 같으면 애너그램이고 다르면 애너그램이 아닌것으로 구분하는 방법으로 접근했다.
그대로 구현이 된 것 같다.
여기선 scanf를 썼는데 fgets를 쓸때 \n이 추가되어 글자수가 하나 더 늘어나는 것과 헷갈려서 strlen에 -1을 해준것 때문에 처음에 결과가 이상하게 나왔던 것 빼면 쉽게 풀었다.
앞으로는 scanf랑 fgets를 쓸때 fgets만 글자수가 하나 더 늘어나는 걸 헷갈리면 안되겠다.
*/
