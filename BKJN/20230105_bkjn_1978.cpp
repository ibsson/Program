#include <stdio.h>

int main() {

	int N = 0;
	int num[101] = { 0 };
	int cnt = 0;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {
		if (num[i] == 0 || num[i] == 1 ) continue;
		if (num[i] == 2) {
			cnt++;
			continue;
		}
		for (int k = 2; k < num[i]; k++) {
			if (num[i] % k == 0) break;
			if (k + 1 == num[i]) cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
