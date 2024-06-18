#include <stdio.h>

void PrintStr(int N, int index) {

	for (int i = 0; i < (index * 4); i++) {
		printf("_");
	}
	printf("\"재귀함수가 뭔가요?\"\n");

	if (index == N) {
		for (int i = 0; i < (index * 4); i++) {
			printf("_");
		}
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");

		for (int i = 0; i < (index * 4); i++) {
			printf("_");
		}
		printf("라고 답변하였지.\n");
		return;
	}

	for (int i = 0; i < (index * 4); i++) {
		printf("_");
	}
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");

	for (int i = 0; i < (index * 4); i++) {
		printf("_");
	}
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");

	for (int i = 0; i < (index * 4); i++) {
		printf("_");
	}
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");

	index++;

	PrintStr(N, index);

	index--;

	for (int i = 0; i < (index * 4); i++) {
		printf("_");
	}
	printf("라고 답변하였지.\n");
}

int main(void) {

	int N = 0, i = 0;

	scanf("%d", &N);

	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");

	PrintStr(N, i);

	return 0;
}

/*
제목 그대로 재귀함수를 이용해서 푸는 문제였다.
자료구조를 계속 공부하면서 전에는 잘 이해가 안됐던 재귀함수를 이해한 덕분에 굉장히 쉽게 풀렸던 문제다.
재귀함수를 이해할때 함수를 하나 더 복사해서 복사한 함수가 끝나면 호출한 곳으로 돌아온다. 라고 이해하면 굉장히 쉬웠다.
앞으로 재귀함수를 이용할때 두려워하지 않고 사용할 수 있을 것 같다.
*/
