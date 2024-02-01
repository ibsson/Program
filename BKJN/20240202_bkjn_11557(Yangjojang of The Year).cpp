#include <stdio.h>
#include <stdlib.h>

typedef struct school {

	char name[21];
	int L;

}School;

School univ[101];

int alchol(int n) {

	int max = -1;
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		if (max < univ[i].L) {
			max = univ[i].L;
			tmp = i;
		}
	}
	
	return tmp;
}

int main(void) {

	int T = 0;
	int N = 0;
	int result = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		
		for (int j = 0; j < N; j++) {
			scanf("%s", univ[j].name, 101);
			scanf("%d", &univ[j].L);
		}

		result = alchol(N);

		printf("%s\n", univ[result].name);
	}

	return 0;
}
