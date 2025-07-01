#include <stdio.h>

char board[51][51];
int max = -1;

void check_max(int N) {

	int cnt = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[i][j] == board[i][j + 1]) {
				cnt++;
				
				if (max < cnt) {
					max = cnt;
				}
			}
			else {
				if (max < cnt) {
					max = cnt;

					cnt = 1;
				}
				else cnt = 1;
			}
		}

		if (max == N) return;

		cnt = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[j][i] == board[j + 1][i]) {
				cnt++;

				if (max < cnt) {
					max = cnt;
				}
			}
			else {
				if (max < cnt) {
					max = cnt;

					cnt = 1;
				}
				else cnt = 1;
			}
		}

		if (max == N) return;

		cnt = 1;
	}
}

void change_horizontal(int N) {

	int tmp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[i][j] != board[i][j + 1]) {

				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;

				check_max(N);

				if (max == N) return;

				tmp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = tmp;
			}
		}
	}
}

void change_vertical(int N) {

	int tmp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (N - 1); j++) {

			if (board[j][i] != board[j + 1][i]) {

				tmp = board[j][i];
				board[j][i] = board[j + 1][i];
				board[j + 1][i] = tmp;

				check_max(N);

				if (max == N) return;

				tmp = board[j][i];
				board[j][i] = board[j + 1][i];
				board[j + 1][i] = tmp;
			}
		}
	}
}

int main(void) {

	int N = 0, a = 0, b = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", board[i], sizeof(board[i]));
	}

	change_horizontal(N);

	if (max == N) {
		printf("%d\n", max);
		return 0;
	}

	change_vertical(N);

	printf("%d\n", max);

	return 0;
}


/* 비주얼 스튜디오에서는 scanf_s를 써서 문자열을 입력할때 뒤에 사이즈를 명시해줘야 오류가 안나는 것을 알 수 있었다.
초기화의 중요성을 알 수 있었고, 무작정 만드는 것이 아니라 과정별로 파트를 나누어서 적어놓고 그 파트별로 함수를 만들어서 하면 가독성도 높아지고, 오류를 찾는것도 쉬웠다.
ex) 1.서로 바꾸기 - 가로          
		 - 세로            ] 두개 과정 반복
    2. 전체 다 확인해서 max 저장   
이렇게 과정별로 파트를 나누었다. 앞으로 코드를 만들 때 이렇게 정리해 놓고 시작하면 좋을 것 같다.
*/
