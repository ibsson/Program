#include <stdio.h>

int num[21];
int N = 0, S = 0;
int cnt = 0;

void Get_Number_Of_Cases(int idx, int sum) {

	if (S == sum && idx != 0) cnt++;

	if (idx == N) return;

	for (int i = idx; i < N; i++) {
		Get_Number_Of_Cases(i + 1, sum + num[i]);
	}
}

int main(void) {

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	Get_Number_Of_Cases(0, 0);

	printf("%d\n", cnt);

	return 0;
}

/*
이 문제를 보고 백트래킹 문제인것을 알게 되었지만, 한번도 백트래킹 문제를 풀어본 적이 없어서
계속 고민하다가 결국 검색해서 풀어내었다.
모든 경우의 수를 고려하는게 어려웠다.
하지만 계속 코드를 들여다 보니 어떤 원리로 작동하는지 조금이나마 이해 할 수 있었다.
백트래킹 문제를 계속 공부해서 이런 문제에 익숙해지고 쉽게 만들 수 있도록 더 열심히 해야겠다.
*/
