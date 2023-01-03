#include <stdio.h>

int num[11000] = { 0 };

int main() {

	int room = 0;
	int temp = 0;

	for (int i = 1; i < 10000; i++){
		temp = i;
		room = i;
		while (temp != 0) {
			room += temp % 10;
			temp /= 10;
		}
		num[room]++;
	}

	for (int i = 1; i < 10000; i++) {
		if (num[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}
