#include <stdio.h>
#include <string.h>

typedef struct alphabet {
	char word;
	int cnt;
}alphabet;

int main(void) {

	char name[51] = { 0 };
	alphabet A[26];
	char result[51] = { 0 };

	for (int i = 0; i < 26; i++) {
		A[i].word = i + 65;
		A[i].cnt = 0;
	}

	scanf("%s", &name, 51);

	int len = strlen(name);

	for (int i = 0; i < len; i++) {
		A[name[i] - 65].cnt++;
	}

	int cnt_odd = 0, odd_index = 0;

	for (int i = 0; i < 26; i++) {
		if (A[i].cnt % 2 != 0) {
			cnt_odd++;
			odd_index = i;
		}

		if (cnt_odd == 2) { //글자수가 홀수개인 글자가 1개 이상이면 성립 불가.
			printf("I'm Sorry Hansoo\n");
			return 0;
		}
	}

	int current_index = 0;

	for (int i = 0; i < 26; i++) {
		for (int j = current_index; j < (current_index + (A[i].cnt / 2)); j++) {
			result[j] = A[i].word;
		}

		current_index += A[i].cnt / 2;
		A[i].cnt -= A[i].cnt / 2;
	}

	if (cnt_odd == 1) {
		result[current_index] = A[odd_index].word;
		current_index++;
		A[odd_index].cnt--;
	}

	for (int i = 25; i >= 0; i--) {
		for (int j = current_index; j < (current_index + A[i].cnt); j++) {
			result[j] = A[i].word;
		}

		current_index += A[i].cnt;
		A[i].cnt -= A[i].cnt;
	}

	printf("%s\n", result);

	return 0;
}

/*
이 문제의 접근 방식은

1. 한 글자씩 검사하며 해당 알파벳의 배열에 갯수를 넣는다.
2. 우선 반을 완성하고 나머지 반은 뒤 알파벳에서 돌아오면서 따로 완성한다

이렇게 접근을 했고 그대로 구현이 되었다.
조금 어려웠지만 계속 생각해보니 금방 접근 방법을 생각해낼 수 있었고, 접근 방법을 알아내니 쉽게 풀렸던 문제였던 것 같다.
*/
