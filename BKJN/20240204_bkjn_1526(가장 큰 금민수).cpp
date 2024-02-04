#include <stdio.h>

int main(void) {

	int N = 0;
	int tmp = 0;
	int a = 1;

	scanf("%d", &N);

	for (int i = N; i >= 1; i--) {
		
		tmp = i;

		while (tmp > 0) {
			if ((tmp % 10 == 4) || (tmp % 10 == 7)) {  //이거 왜 (tmp % 10 != 4) || (tmp % 10 != 7)로 하면 경고 뜨지?
				a = 1;
			}
			else {
				a = 0;
				break;
			}

			tmp /= 10;
		}

		if (a == 1) {
			printf("%d\n", i);
			return 0;
		}
	}

}
