#include <stdio.h>

int main() {

	int N[9];
	int max = -100;
	int room = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &N[i]);
	}

	for (int i = 0; i < 9; i++) {
		if (max < N[i]) {
			max = N[i];
			room = i;
		}
	}
	printf("%d \n%d", max, room+1);

	return 0;
}
