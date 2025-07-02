#include <stdio.h>

double num[10001] = { 0 };

int main(void) {

	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lf", &num[i]);
	}

	double max = -1;

	for (int i = 0; i < N; i++) {
		double tmp = 1;

		for (int j = i; j < N; j++) {
			tmp *= num[j];

			if (max < tmp) {
				max = tmp;
			}
		}
	}

	printf("%.3lf\n", max);

	return 0;
}

/*
이 문제는 브루트포스로 풀었다.
처음부터 시작해서 연속된 부분을 곱해보면서 최대값이 나오면 최대값을 업데이트 해주는 방식으로 풀었다.
*/
