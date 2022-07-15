#include <stdio.h>

unsigned int position[300001] = { 0 }; //순서 저장 방
unsigned int num[2][300001] = { (0, 0) }; //둘째줄 저장 방

void move(int N, int T) {

	unsigned int room[300001] = { 0 }; //정렬 도움 방
	unsigned int sort[2][300001] = { (0,0) }; //둘째줄 (순서) 정렬 방
	int a = 0;
	int tmp = 0;
	int calculate = 0;
	int shel = 0;

	for (int i = 0; i < N; i++) {   //첫째줄
		scanf_s("%d", &(position[i]));
		num[0][i] = position[i];
	}

	for (int i = 0; i < N; i++) {  //둘째줄 정렬
		scanf_s("%d", &(num[1][i]));

		tmp = num[1][i] + 100000;

		room[tmp] ++;
	}

	for (int i = 0; i <= 200000; i++) {
		for (int k = 0; k < room[i]; k++) {
			sort[1][a] = i - 100000;
			for (int h = 0; h < N; h++) {
				if (sort[1][a] == num[1][h]) {
					sort[0][a] = num[0][h];
					num[1][h] = 0;
					break;
				}
			}
			a++;
		}
	}

	for (int i = 0; i < N; i++) {
		if (position[i] < sort[0][i]) {
			shel = position[i];
			position[i] = sort[0][i];
			sort[0][i] = shel;
		}
			calculate += (position[i] - sort[0][i]);
	}

	printf("Case #%d\n", T);
	printf("%d\n", calculate);
}

int main() {
	int T = 0;
	int N = 0;

	scanf_s("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf_s("%d", &N);
		move(N, t);
	}

	return 0;
}
