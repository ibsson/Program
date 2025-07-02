#include <stdio.h>

int main(void) {

	int N = 0;

	scanf("%d", &N);

	if (N % 2 == 0) printf("CY");
	else printf("SK\n");

	return 0;
}

/*
이 문제는 짝수일때는 무조건 창영, 홀수일때는 상근이가 이긴다는 규칙을 발견해서 쉽게 풀었다.
*/
