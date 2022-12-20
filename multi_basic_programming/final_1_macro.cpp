#include <stdio.h>

#define swap_1(a, b) ( (a) ^= (b) ^= (a) ^= (b))

#define SWAP(num1, num2, type) do{ type room; room = num1; num1 = num2; num2 = room; } while (0)

int main() {

	int num1 = 0;
	int num2 = 0;
	int room1 = 0;

	scanf_s("%d %d", &num1, &num2);

	if (num1 > num2) {
		swap_1(num1, num2);
	}

	if (num1 % 2 == 0) num1 += 1;

	for (int i = num1; i <= num2; i += 2) {
		room1 += num1;
	}

	printf("%d\n", room1);

	return 0;
}
