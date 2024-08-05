#include <stdio.h>
#include <stdlib.h>

int tri[31][31] = { 0 };

void Make_Triangle(int n, int k) {

	tri[0][0] = 1;
	tri[1][0] = 1, tri[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		tri[i][0] = 1;
		for (int j = 1; j < i; j++) {
			tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
		}
		tri[i][i] = 1;
	}
}

int main(void) {

	int n = 0, k = 0;

	scanf("%d %d", &n, &k);

	Make_Triangle(n, k);

	printf("%d\n", tri[n - 1][k - 1]);

	return 0;
}

/*
이 코드는 문제에 나온 그대로 삼각형을 만들어서 풀면 쉽게 풀리는 문제였다.
*/
