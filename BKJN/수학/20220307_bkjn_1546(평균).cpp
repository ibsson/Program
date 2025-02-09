#include <stdio.h>

int main() {

	int N;
	int point[1000];
	int max=-100;
	double total=0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &point[i]);
		if (max < point[i]) {
			max = point[i];
		}
	}

	for (int i = 0; i < N; i++) {
		total += ((double)point[i] / (double)max * 100.0);
	}
	printf("%lf", total / N);

	return 0;
}
