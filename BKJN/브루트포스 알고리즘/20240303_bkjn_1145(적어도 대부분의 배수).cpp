#include <stdio.h>

int num[5] = { 0 };

int get_result(int cnt) {

	while (1) {
		for (int i = 0; i < 3; i++) {
			for (int j = (i + 1); j < 4; j++) {
				for (int k = (j + 1); k < 5; k++) {
					if ((cnt % num[i] == 0) && (cnt % num[j] == 0) && (cnt % num[k] == 0)) {
						return cnt;
					}
				}
			}
		}

		cnt++;
	}
}

int main(void) {

	int min = 101, cnt = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (min > num[i]) {
			min = num[i];
		}
	}

	cnt = min;

	int result = get_result(cnt);

	printf("%d\n", result);

	return 0;
}
