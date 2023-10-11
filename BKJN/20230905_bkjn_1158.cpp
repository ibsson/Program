
//New solution

#include <stdio.h>

#define DATA_LEN_MAX 5000

int data[2][DATA_LEN_MAX];
int cnt = 0;
int address_now = 0;


int pop(int jump) {

	if (jump <= 0)
		return -1;

	int address_previous;

	for (int i = 0; i < jump; i++) {
		address_previous = address_now;
		address_now = data[1][address_now];
	}

	int return_value = data[0][address_now];

	data[1][address_previous] = data[1][address_now];
	address_now = address_previous;

	return return_value;
}

int main() {

	scanf("%d", &cnt);

	if (cnt < 1 || cnt >= DATA_LEN_MAX)
		cnt = DATA_LEN_MAX;

	for (int i = 0; i < cnt; i++) {
		data[0][i] = i + 1;
		data[1][i] = i + 1;
	}
	data[1][cnt - 1] = 0;

	address_now = cnt - 1;

	int interval;
	scanf("%d", &interval);

	printf("<");
	for (int i = 0; i < cnt; i++) {
		printf("%d", pop(interval));
		if (i != cnt - 1)
			printf(", ");
	}
	printf(">");

	return 0;
}


// Old solution



#include <stdio.h>

int main(void) {

	int N = 0;
	int K = 0;
	int num[5001] = { 0 };
	int room[5001] = { 0 };

	for (int i = 1; i < sizeof(num) / sizeof(int); i++) {
		num[i] = i;
	}

	scanf("%d %d", &N, &K);

	int cnt = K;
	int tmp = 1;
	int a = 1;

	while (1) {
		for (int i = 0; i < K; i++) {

			if (tmp > N) {
				tmp = 1;
			}

			if (num[tmp] == 0) {
				while (1) {
					if (tmp > N) {
						tmp = 1;
					}
					if (num[tmp] != 0) break;
					tmp++;
				}
			}

			if (i + 1 == cnt) {
				num[tmp] = 0;
				room[a] = tmp;
				a++;
			}
			tmp++;
		}
		if (a == N + 1) break;
	}

	printf("<");

	for (int i = 1; i <= N; i++) {
		printf("%d", room[i]);
		if (i == N) break;
		printf(",");
		printf(" ");
	}

	printf(">");

	return 0;
}
