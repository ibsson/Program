#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int len = 0;
	char* A = (char*)malloc(sizeof(char) * 101);

	scanf("%s", A, sizeof(A));

	len = strlen(A);

	printf("%d\n", len);

	return 0;
}
