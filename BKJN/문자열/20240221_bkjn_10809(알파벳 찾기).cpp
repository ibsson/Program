#include <stdio.h>
#include <string.h>

int main(void) {

	char S[101] = { 0 };
	int a = 0;

	scanf("%s", S, 101);

	a = strlen(S);

	for (int i = 97; i <= 122; i++) {
		for (int j = 0; j < a; j++) {
			if (S[j] == i) {
				printf("%d", j);
				break;
			}
			
			if (j == a - 1) {
				printf("-1");
			}
		}
		
		if (i == 122) printf("\n");

		printf(" ");
	}
	

	return 0;
}
