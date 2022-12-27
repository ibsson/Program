#include <stdio.h>

int main() {

	int C = 0;
	int N = 0;
	int score[1001] = { 0 };
	int sum = 0;
	int cnt = 0;
	double result = 0.0;

	scanf_s("%d", &C);
	
	for (int i = 0; i < C; i++) {
		
		scanf_s("%d", &N);

		for (int i = 0; i < N; i++) {
		  scanf_s("%d", &score[i]);
			sum += score[i];
		}

		for (int i = 0; i < N; i++) {
			if ((sum / N) < score[i]) cnt++;
		}

		result = ((double)cnt / (double)N) * 100;

		printf("%.3lf%%\n", result);

		cnt = 0;
		sum = 0;
	}


	return 0;
}
