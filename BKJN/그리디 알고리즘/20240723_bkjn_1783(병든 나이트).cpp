#include <stdio.h>

int main(void) {

	int N = 0, M = 0;

	scanf("%d %d", &N, &M);

	if (N == 1) printf("1\n");
	else if (N == 2) {
		if (M >= 1 && M < 3) printf("1\n");
		else if (M >= 3 && M < 5) printf("2\n");
		else if (M >= 5 && M < 7) printf("3\n");
		else printf("4\n");
	}
	else if (N >= 3) {
		if (M == 1) printf("1\n");
		else if (M == 2) printf("2\n");
		else if (M == 3) printf("3\n");
		else if (M >= 4 && M < 7) printf("4\n");
		else if (M >= 7) printf("%d\n", (M - 2));
	}

	return 0;
}

/*
이 문제는 계속 고민하다가 모르겠어서 다른분의 코드를 참고했다.
이런 많은 조건 분기 문제는 한번도 풀어본 적이 없는 것 같아서 조금 어려웠다.
DFS나 BFS문제로 생각을 했는데 잘 생각해보면 규칙이 있는 문제였다.
이런 많은 조건 분기 문제는 값이 달라지는 조건을 잘 찾는것이 가장 중요하다고 생각이 들었고,
규칙을 찾아내는 것도 중요하다는 생각이 들었다.
*/
