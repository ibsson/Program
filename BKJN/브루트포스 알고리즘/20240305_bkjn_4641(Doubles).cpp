#include <stdio.h>

int num[16] = { 0 };

int get_len() {

	int len = 0, i = 0;

	while (num[i] != 0) {
		len++;
		i++;
	}

	return len;
}

int main(void) {

	while (1) {

		int i = 0, cnt = 0;

		while (1) {
			scanf("%d", &num[i]);

			if (num[i] == -1) return 0;

			if (num[i] == 0) break;

			i++;
		}

		int len = get_len();

		for (int k = 0; k < len; k++) {
			for (int l = 0; l < len; l++) {
				if (num[k] * 2 == num[l]) {
					cnt++;
					break;
				}
			}
		}

		printf("%d\n", cnt);

		for (int m = 0; m < len; m++) {
			num[m] = 0;
		}
	}

	return 0;
}
