#include <stdio.h>

int check_666(int N) {

	int disaster = 666, room = 0, check_N = 0;

	while (1) {

		int tmp = disaster;
		int check_straight = 0;

		while (tmp != 0) {
			room = tmp % 10;
			if (room == 6) {
				check_straight++;
				if (check_straight == 3) {
					break;
				}
			}
			else {
				check_straight = 0;
			}
			tmp /= 10;
		}

		if (check_straight == 3) {
			check_N++;
		}

		if (check_N == N) {
			return disaster;
		}

		disaster++;
	}
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	int result = check_666(N);

	printf("%d\n", result);

	return 0;
}
