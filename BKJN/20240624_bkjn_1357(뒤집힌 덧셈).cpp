#include <stdio.h>

int Rev(int num) {

	int tmp_1 = num;
	int tmp_2 = 0, cnt = 0, mul = 1, result = 0;

	while (tmp_1 != 0) {
		tmp_1 /= 10;
		cnt++;
	}

	for (int i = 0; i < (cnt - 1); i++) {
		mul *= 10;
	}

	while (num != 0) {
		tmp_2 = num % 10;
		result += tmp_2 * mul;
		mul /= 10;

		num /= 10;
	}

	return result;
}

int main(void) {

	int X = 0, Y = 0;

	scanf("%d %d", &X, &Y);

	int num_1 = Rev(X);
	int num_2 = Rev(Y);

	int result = Rev(num_1 + num_2);

	printf("%d\n", result);

	return 0;
}

/*
이런 간단한 구현 문제는 이제 쉽게 풀 수 있는 것 같다.
문제 그대로 접근하려고 했다.

1. Rev함수에서 모든 자리수의 숫자를 뒤집는다.

Rev함수만 잘 구현하면 될거라고 생각했고, 잘 구현 되었고, 한번에 맞춰서 좋았다. 앞으로 더 빠르게 풀 수 있도록 더 노력해야 겠다.
*/
