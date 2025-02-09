#include <stdio.h>

int main() {

	int num1 = 0;
	int num2 = 0;
	int room1 = 0;
	int room2 = 0;

	scanf_s("%d %d", &num1, &num2);

	if (num1 > num2) {
		room1 = num1;
		num1 = num2;
		num2 = room1;
	}

	room1 = num1;

	for (int i = 0; i < (num2 - num1 - 1); i++) {
		room1 += 1;
		if ((room1 % 2) != 0) {
			room2 += room1;
		}
	}

	printf("%d", room2);

	return 0;
}
