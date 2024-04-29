#include <stdio.h>

int main(void) {

	int A = 0, B = 0;

	while (scanf("%d %d", &A, &B) != EOF) { //입력한 값이 EOF 라면 반복 종료
		printf("%d\n", A + B);
	}

	return 0;
}

/*
이 문제를 통해서 EOF를 발생시켜 실행을 종료 시키는 코드를 적는 법을 알게 되었다.
*/
