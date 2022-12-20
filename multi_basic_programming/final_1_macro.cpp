#include <stdio.h>

#define SWAP(num1, num2, type) do{ \
	type room; \
	room = num1; \
	num1 = num2; \
	num2 = room; \
} while (0)

int main() {

	int num1 = 0;
	int num2 = 0;
	int room1 = 0;
	int room2 = 0;

	scanf_s("%d %d", &num1, &num2);

	if (num1 > num2) {
		SWAP(num1, num2, int);
	}

	room1 = num1;

	for (int i = 0; i <= (num2 - num1); i++) {
		if ((room1 % 2) != 0) {
			room2 += room1;
		}
		room1 += 1;
	}

	printf("%d\n", room2);

	return 0;
}
