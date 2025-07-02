#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info {
	int age;
	char name[101];
	int sequence;
}Info;

int Compare(const void* a, const void* b) {

	Info* num1 = (Info*)a;
	Info* num2 = (Info*)b;

	if (num1->age > num2->age) return 1;
	else if(num1->age < num2->age) return -1;
	else {
		if (num1->sequence > num2->sequence) return 1;
		else return -1;
	}
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	Info* A = (Info*)malloc(sizeof(Info) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i].age);
		scanf("%s", A[i].name, 101);
		A[i].sequence = i;
	}

	qsort(A, N, sizeof(Info), Compare);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", A[i].age, A[i].name);
	}

	return 0;
}

/*
qsort를 써서 풀었다. 일단 먼저 나이순으로 정렬을 하고 등록 순서를 sequence 변수에다가 넣어놔서 만약 나이가 같다면 등록 순서대로 정렬을 시켰다.
한번에 풀어내서 기분이 좋았다!
*/
