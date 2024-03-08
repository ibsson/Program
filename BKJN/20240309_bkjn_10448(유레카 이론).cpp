#include <stdio.h>

int num[45] = { 0 };

int check_3_or_not(int K, int cnt) {

	int tmp = 0;

	tmp = K;

	for (int i = 0; i < cnt; i++) {
		tmp -= num[i];

		for (int j = 0; j < cnt; j++) {
			tmp -= num[j];

			for (int k = 0; k < cnt; k++) {
				if (tmp == num[k]) {
					return 1;
				}
			}
			tmp += num[j];

		}
		if (i == (cnt - 1)) {
			return 0;
		}

		tmp += num[i];
	}
}

int check_lower_than_K(int K) {

	int cnt = 0;

	for (int i = 0; i < 45; i++) {
		if (num[i] > K) {
			break;
		}
		cnt++;
	}

	return cnt;
}

int main(void) {

	int T = 0, K = 0;

	scanf("%d", &T);

	for (int i = 0; i < sizeof(num); i++) {
		for (int j = 1; j <= (i + 1); j++) {
			num[i] = j * (j + 1) / 2;
		}
	}

	for (int i = 0; i < T; i++) {
		scanf("%d", &K);

		int cnt = check_lower_than_K(K);
		
		printf("%d\n", check_3_or_not(K, cnt));
	}

	return 0;
}
