#include <stdio.h>

typedef struct cow{

	int num = 0;
	int direction = 0;

}Cow;

Cow a[100];
int check_1[10];
int check_2[10];

int main(void) {

	int N = 0;
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].num, &a[i].direction);

		if (check_1[a[i].num] == 0) {
			check_1[a[i].num]++;
			check_2[a[i].num] = a[i].direction;
		}
		else {
			if (check_2[a[i].num] != a[i].direction) {
				cnt++;
				check_2[a[i].num] = a[i].direction;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
