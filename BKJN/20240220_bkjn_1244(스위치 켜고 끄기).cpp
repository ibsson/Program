#include <stdio.h>

int button[101] = { 0 };

typedef struct student {

	int gen;
	int num;

}Student;

void man(int n, int k) {

	for (int i = k; i <= n; i++) {
		if (button[i] == 0) button[i] = 1;
		else if (button[i] == 1) button[i] = 0;

		i += (k - 1);
	}

}

void woman(int n, int k) {

	int cur = k;

	while (1) {
		if (button[k] == button[cur]) {
			if (button[k] == 0) {
				button[k] = 1;
				button[cur] = 1;
			}
			else if (button[k] == 1) {
				button[k] = 0;
				button[cur] = 0;
			}
		}
		else break;

		k++;
		cur--;

		if (cur == 0) break;
		
		if (k == (n + 1)) break;
	}

}

int main(void) {

	int N = 0;
	int A = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &button[i]);
	}

	Student a[101];

	scanf("%d", &A);

	for (int i = 0; i < A; i++) {
		scanf("%d %d", &a[i].gen, &a[i].num);
	}

	for (int i = 0; i < A; i++) {
		if (a[i].gen == 1) {
			man(N, a[i].num);
		}
		else if (a[i].gen == 2) {
			woman(N, a[i].num);
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d", button[i]);

		
		if (i == N) {
			printf("\n");
			break;
		}
		else if (i % 20 == 0) {
			printf("\n");
			continue;
		}

		printf(" ");
	}

	return 0;
}
