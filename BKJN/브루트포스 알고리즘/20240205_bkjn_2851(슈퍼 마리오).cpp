#include <stdio.h>

int main(void) {

	int num[10] = { 0 };
	int tmp = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 10; i++) {
		tmp += num[i];

		if (tmp >= 100) {
			if ((100 - (tmp - num[i])) >= (tmp - 100)) {
				printf("%d\n", tmp);
				break;
			}
			else {
				printf("%d\n", tmp - num[i]);
				break;
			}
		}
		
		if (tmp < 100 && i == 9) {
			printf("%d\n", tmp);
			break;
		}
	}

	return 0;
}
