#include <stdio.h>

int main() {

	int N = 0;
	int cnt = 0;
	int num[4] = { 0 };

	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (i == 1000) break;
		if (i < 100) {
			cnt++;
			continue;
		}
    
		int tmp = i;
    
		for (int k = 0; k < 4; k++) {
			num[k] = tmp % 10;
			tmp /= 10;
			if (tmp == 0) break;
		}
    
		if (num[1] * 2 == num[0] + num[2]) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
