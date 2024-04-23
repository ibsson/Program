#include <stdio.h>

int ground[501][501];

int Get_Highest(int N, int M) {

	int max = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (max < ground[i][j]) {
				max = ground[i][j];
			}
		}
	}

	return max;
}

int Get_Lowest(int N, int M) {

	int min = 500;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (min > ground[i][j]) {
				min = ground[i][j];
			}
		}
	}

	return min;
}

int Get_Time(int N, int M, int highest, long long B) {

	int tmp = 0, time = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp = ground[i][j];

			if (tmp < highest) {
				while (tmp != highest) {
					tmp++;
					time++;
					B--;
				}
			}
			else if (tmp > highest) {
				while (tmp != highest) {
					tmp--;
					time += 2;
					B++;
				}
			}
		}
	}

	if (B < 0) return 100000000;

	return time;
}

int main(void) {

	int N = 0, M = 0, highest = 0, lowest = 0, tmp = 0, min_time = 100000000, height = 0;
	long long int B = 0;

	scanf("%d %d %lld", &N, &M, &B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &ground[i][j]);
		}
	}

	highest = Get_Highest(N, M);
	lowest = Get_Lowest(N, M);

	if (highest == lowest) {
		printf("0 %d\n", highest);
		return 0;
	}

	for (int i = highest; i >= 0; i--) {
		tmp = Get_Time(N, M, i, B);
		if (tmp < min_time) {
			min_time = tmp;
			height = i;
		}
	}

	printf("%d %d\n", min_time, height);

	return 0;
}

/* 과정은
1. 최고높이부터 0까지 검사를 한다
2. 최소 시간을 갱신해 출력한다
로 생각하고 풀었다. 그래도 처음에 생각한 과정대로 코드를 짠 것 같아서 기쁘다.
항상 브루트포스 문제는 반례 찾기가 정말 어렵다. 처음에 짠 대로 돌려보니 계속 틀렸다고 나와서 질문 게시판의 반례를 모두 돌려봤더니 B가 0보다 작아질때를 루프 안에서
판별해, 차례대로 검사할때 뒤에 나오는 수에서 제거를 해서 인벤토리에 넣어 B가 0보다 커질 수 있다는 사실을 간과했다는 것을 알아냈다. 이런 문제 풀때는 항상 여러번 생각을
해 보고 코드를 짜야겠다.
*/
