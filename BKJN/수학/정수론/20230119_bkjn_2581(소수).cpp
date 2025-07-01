#include <stdio.h>

int main() {

	int M = 0;
	int N = 0;
	int num = 0;
	int sum = 0;
	int cnt = 0;
	int room = 0;
	
	scanf_s("%d", &M);
	scanf_s("%d", &N);

	num = M;

	for (int i = 0; i <= N - M; i++) {
		for (int k = 2; k <= num; k++) {
			if (num == 2) {
				room = num;
				sum += num;
				cnt = 1;
				continue;
			}
			if (num % k == 0) break;
			else if (k + 1 == num) {
				sum += num;
				if (cnt == 0) room = num;
				cnt = 1;
			}
		}
		num++;
	}

	if (cnt == 0) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n%d\n", sum, room);

	return 0;
}
