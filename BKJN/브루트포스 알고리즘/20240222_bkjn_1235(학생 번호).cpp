#include <stdio.h>
#include <string.h>

typedef struct student {

	char num[101];

}Student;

Student a[1000];
char tmp_1[101] = { 0 };
char tmp_2[101] = { 0 };

void slice(int index, int len, int cnt, int check) {

	int p = 0;

	if (check == 1) {
		for (int i = (len - cnt); i < len; i++) {
			tmp_1[p] = a[index].num[i];
			p++;
		}
	}

	if (check == 2) {
		for (int i = (len - cnt); i < len; i++) {
			tmp_2[p] = a[index].num[i];
			p++;
		}
	}

}

int main(void) {

	int N = 0;
	int len = 0;
	int cnt = 1;
	int check = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", a[i].num, 101);
	}

	len = strlen(a[0].num);

	for (int i = 0; i < (N - 1); i++) {
		slice(i, len, cnt, 1);

		for (int j = (i + 1); j < N; j++) {
			slice(j, len, cnt, 2);
			if (strcmp(tmp_1, tmp_2) == 0) {
				cnt++;
				i = -1;
				break;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
