#include <stdio.h>

int num[100000] = { 0 };

int main() {

	int K = 0;
	int sum = 0;
	int j = 0;
	int i = 0;

	scanf_s("%d", &K);

	while (j < K)
	{
		scanf_s("%d", &num[i]);

		if (num[i] == 0)
		{
			num[i - 1] = 0;
			i--;
		}
		else
			i++;

		j++;
	}

	for (int j = 0; j < i; j++) {
		sum += num[j];
	}

	printf("%d\n", sum);

	return 0;
}
