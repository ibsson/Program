#include <stdio.h>

int main(void) {

	int E = 0, S = 0, M = 0, cnt = 0;
	int e = 0, s = 0, m = 0;

	scanf("%d %d %d", &E, &S, &M);

	while (1) {
		e++;
		if (e == 16) e = 1;

		s++;
		if (s == 29) s = 1;

		m++;
		if (m == 20) m = 1;

		cnt++;

		if (e == E && s == S && m == M) {
			printf("%d\n", cnt);
			break;
		}
	}

	return 0;
}
