#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Get_Result(char** DNA, int N, int M, char** tmp) {

    int max = -1, cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (DNA[i][j] != DNA[k][j]) {
                    cnt++;
                }
            }
        }

        if (max < cnt) {
            max = cnt;
            strcpy_s((*tmp), M, DNA[i]);
        }
    }

    return max;
}

int main(void) {

	int N = 0, M = 0;

	scanf_s("%d %d", &N, &M);

	char** DNA = (char**)malloc(sizeof(char*) * N);

	for (int i = 0; i < N; i++) {
		DNA[i] = (char*)malloc(sizeof(sizeof(char) * M));
	}

    for (int i = 0; i < N; i++) {
        scanf_s("%s", DNA[i], M);
    }

    char* tmp = (char*)malloc(sizeof(char) * M);
    char* result_DNA = (char*)malloc(sizeof(char) * M);

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (strcmp(DNA[i], DNA[j]) < 0)
            {
                strcpy_s(tmp, M, DNA[i]);
                strcpy_s(DNA[i], M, DNA[j]);
                strcpy_s(DNA[j], M, tmp);
            }
        }
    }

    int result = Get_Result(DNA, N, M, &result_DNA);

    printf("%s\n", result_DNA);
    printf("%d\n", result);

	return 0;
}
