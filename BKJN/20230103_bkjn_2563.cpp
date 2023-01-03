#include <stdio.h>

int paper[100][100];

int main() {

	int N = 0;
	int left = 0;
	int down = 0;
	int cnt = 0;
	int room = 0;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &left, &down);

		for (int k = 0; k < 10; k++) {
			room = down;
			for (int j = 0; j < 10; j++) {
				paper[left][room] = 1;
				room++;
			}
			left++;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int k = 0; k < 100; k++) {
			if (paper[i][k] == 1) cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
