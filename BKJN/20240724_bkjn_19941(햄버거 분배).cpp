#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[20001];
int check[20001];

int main(void) {

	int N = 0, K = 0, cnt = 0;

	scanf("%d %d", &N, &K);

	scanf("%s", table, 20001);
	memset(check, 0, sizeof(table));

	for (int i = 0; i < N; i++) {
		if (table[i] == 'P') {
			for (int j = (i - K); j <= (i + K); j++) {
				if (table[j] == 'H' && check[j] == 0) {
					cnt++;
					check[j] = 1;
					break;
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}

/*
이 문제의 접근 방법은

1. 배열의 왼쪽 부분부터 시작해서 P가 나오면 index-K 부터 index+K 중에 P가 있으면 cnt를 추가한다.

이 방법으로 했다.
이런 형식의 문제를 많이 풀어보니까 점점 이런 문제를 쉽게 푸는 방법을 알게 되는 것 같다.
*/
