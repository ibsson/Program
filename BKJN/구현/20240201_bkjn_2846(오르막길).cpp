#include <stdio.h>

int Pi[1001] = { 0 };

int hill(int n) {

	int tmp1 = 0;
	int tmp2 = 0;

	for (int i = 0; i < n; i++) {

		if (Pi[i] < Pi[i + 1]) {

			for (int j = i + 1; j < n; j++) {

				if (Pi[j] > Pi[j + 1] || Pi[j] == Pi[j + 1]) {

					tmp2 = Pi[j] - Pi[i];
					i = j;

					break;
				}
			}
		}
		if (tmp1 < tmp2) tmp1 = tmp2;
	}

	return tmp1;
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Pi[i]);
	}

	printf("%d\n", hill(N));

	return 0;
}
