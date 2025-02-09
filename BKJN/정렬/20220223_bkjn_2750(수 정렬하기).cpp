#include<stdio.h>

int main() {

	int num[1000];
	int shelter = 0;
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < T; i++) {
		for (int k = i+1; k < T; k++) {
			if (num[i] > num[k]) {
				shelter = num[i];
				num[i] = num[k];
				num[k] = shelter;
			}
		}
		printf("%d\n", num[i]);
	}

	return 0;
}
