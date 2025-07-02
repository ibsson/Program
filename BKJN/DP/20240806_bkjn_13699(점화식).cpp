#include <stdio.h>

int main(void) {

	int n = 0;
	long long int t[36] = { 0 };

	scanf("%d", &n);

	t[0] = 1;

	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = (i - 1); j >= 0; j--) {
			t[i] += t[k] * t[j];
			k++;
		}
	}

	printf("%lld\n", t[n]);

	return 0;
}

/*
이 문제도 다이나믹 프로그래밍으로 문제에 주어진 점화식 조건 그대로 쉽게 구현했다.
*/
