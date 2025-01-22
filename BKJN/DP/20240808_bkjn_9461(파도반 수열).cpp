#include <stdio.h>

long long int P[102] = { 0 };

void Make_P() {

	P[1] = 1, P[2] = 1, P[3] = 1, P[4] = 2, P[5] = 2;

	for (int j = 6; j <= 100; j++) {
		P[j] = P[j - 5] + P[j - 1];
	}
}

int main(void) {

	int T = 0, N = 0;

	scanf("%d", &T);

	Make_P();

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		printf("%lld\n", P[N]);
	}

	return 0;
}

/*
이 문제는 dp로 쉽게 풀었다.
우선 스스로 점화식을 생각해내서 풀어냈다는 것이 가장 만족스럽다.
앞으로도 스스로 풀어내는 문제가 더 많아지도록 더 노력해야겠다.
*/
