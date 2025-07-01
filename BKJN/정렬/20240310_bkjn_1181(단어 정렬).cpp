#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* x, const void* y)
{
	const char* a = *(const char(*)[51])x;
	const char* b = *(const char(*)[51])y;

	if (strlen(a) > strlen(b)) return 1;
	if (strlen(a) < strlen(b)) return -1;
	return strcmp(a, b);
}

char word[20001][51] = { 0 };

int main()
{
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", word[i], sizeof(*word));
	}

	qsort(word, N, sizeof(*word), compare);

	printf("%s\n", word[0]);
	for (int i = 1; i < N; i++)
	{
		if (strcmp(word[i], word[i - 1]) != 0)
		{
			printf("%s\n", word[i]);
		}
	}
	return 0;
}
