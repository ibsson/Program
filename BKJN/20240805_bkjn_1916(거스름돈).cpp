#include <stdio.h>

int main(void) {

	int n = 0, cnt = 0;

	scanf("%d", &n);

	while (n % 5 != 0) {
		n -= 2;
		cnt++;

		if (n < 0) {
			printf("-1\n");
			return 0;
		}
	}

	cnt += n / 5;

	printf("%d\n", cnt);

	return 0;
}

/*
다이나믹 프로그래밍 유형의 문제를 계속 풀어보면서 이런 유형의 문제는 어떻게 접근해야 하는지 조금은 감이 생기는 것 같다.
*/
