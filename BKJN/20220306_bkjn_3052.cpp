#include <stdio.h>

int main() {

	int num[10];
	int cnt = 0;
	int room[42] = { 0 };

	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 10; i++) {
		room[num[i]%42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (room[i] != 0) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
