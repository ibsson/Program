#include <stdio.h>

int main(void) {

	int L = 0, P = 0, V = 0, i = 1;

	while (1) {
		scanf("%d %d %d", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0) break;

		int a = V / P;
		a = a * L;

		int b = V % P;

		if (b <= L) {
			a += b;
		}
		else {
			a += L;
		}

		printf("Case %d: ", i);
		printf("%d\n", a);

		i++;
	}
		
	return 0;
}
