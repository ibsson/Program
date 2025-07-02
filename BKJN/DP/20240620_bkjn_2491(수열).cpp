#include <stdio.h>

int Get_Ascending_Order(int num[], int N) {

	int max = 1, tmp = 1;

	for (int i = 0; i < (N - 1); i++) {
		if (num[i] > num[i + 1]) {
			if(max < tmp) max = tmp;

			tmp = 1;
		}
		else {
			tmp++;
		}
	}

	if (max < tmp) max = tmp;

	return max;
}

int Get_Descending_Order(int num[], int N) {

	int max = 1, tmp = 1;

	for (int i = 0; i < (N -1); i++) {
		if (num[i] < num[i + 1]) {
			if (max < tmp) max = tmp;

			tmp = 1;
		}
		else {
			tmp++;
		}
	}

	if (max < tmp) max = tmp;

	return max;
}

int main(void) {

	int N = 0;
	int num[100001] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	int result_1 = Get_Ascending_Order(num, N);

	int result_2 = Get_Descending_Order(num, N);

	int result = (result_1 > result_2) ? result_1 : result_2;

	printf("%d\n", result);

	return 0;
}

/*
접근을 이렇게 하려고 했다.

1. 오름차순을 검사
2. 내림차순을 검사
3. 둘 중에 더 큰거 출력

이렇게 했는데 그대로 구현해냈다. 78%에서 계속 틀렸다고 해서 생각을 해 봤더니 if (tmp == N) max = tmp; 이 코드를 잘못 생각했었다.
중간에서 다시 세는 경우에 마지막 인덱스까지 검사하는 경우가 있으므로 if (max < tmp) max = tmp; 로 코드를 고쳤더니 정답이 되었다.
조건문을 쓸때는 이 조건이 맞는지 한번 더 생각해보고 써야겠다고 느꼈다.
*/
