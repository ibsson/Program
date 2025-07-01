#include <stdio.h>

int num[10] = { 0 };

int set() {

	int max = 0;

	if ((num[6] + num[9]) % 2 == 0) {
		num[6] = (num[6] + num[9]) / 2;
		num[9] = 0;
	}
	else {
		num[6] = ((num[6] + num[9]) / 2) + 1;
		num[9] = 0;
	}
	//6과 9를 한번에 취급

	for (int i = 0; i < 10; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}

	return max;
}

int main(void) {

	int N = 0;
	int tmp = 0;

	scanf("%d", &N);

	while (N > 0) {

		num[N % 10]++;
		N /= 10;
	}

	printf("%d\n", set());

	return 0;
}
