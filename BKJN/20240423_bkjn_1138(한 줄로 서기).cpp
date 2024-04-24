#include <stdio.h>

typedef struct people {
	int height;
	int info;
}People;

int row[11];
People people[11];

void Get_Row(int N, int index) {

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (cnt == people[index].info) {
			for (int j = i; j < N; j++) {
				if (row[j] == 0) {
					row[j] = people[index].height;
					return;
				}
			}
		}
		if(row[i] == 0) cnt++;
	}
}

int main(void) {

	int N = 0;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &people[i].info);
		people[i].height = (i + 1);
	}

	for (int i = 0; i < N; i++) {
		Get_Row(N, i);
	}

	for (int i = 0; i < N; i++) {
		printf("%d", row[i]);
		if ((i + 1) == N) printf("\n");
		else printf(" ");
	}

	return 0;
}

/*이 코드는 처음에 링크드 리스트를 이용해서 풀려고 했으나 녹록치 않아서 다른방법을 생각해 보았다.
앞으로는 과정을 번호를 매겨서 생각하는 것이 아닌 '접근방법'을 적어놓고 코드 짜는것을 진행해야 겠다.

#접근 방법
작은 수 부터 왼쪽에 자신보다 큰 사람이 몇 명 있어야 하는지 적혀있는 값 만큼 비워놓고 채운다
빈자리를 카운트 하며 해당 자리만큼 비우고 그 자리가 채워져 있지 않으면(0이면) 자리를 채우고, 채워져 있다면 1씩 늘려가며 빈자리가 나오면 거기에 채운다

이 방법으로 풀어냈다. 쉽지 않았지만 그래도 내 힘으로 풀어냈다는 것에 의의를 두고 싶다!
*/

//복습 코드

#include <stdio.h>

typedef struct people {
	int height;
	int info;
}People;

int row[11];
People people[11];

void Get_Location(int N, int index) {

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (cnt == people[index].info) {
			for (int j = i; j < N; j++) {
				if (row[j] == 0) {
					row[j] = people[index].height;
					return;
				}
			}
		}
		if(row[i] == 0) cnt++;
	}
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &people[i].info);
		people[i].height = (i + 1);
	}

	for (int i = 0; i < N; i++) {
		Get_Location(N, i);
	}

	for (int i = 0; i < N; i++) {
		printf("%d", row[i]);
		if (i + 1 == N) printf("\n");
		else printf(" ");
	}

	return 0;
}
