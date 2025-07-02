#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Get_Result(char** DNA, int N, int M, char* tmp) {

    int result = 0;

    for (int i = 0; i < M; i++) {
        int cnt_A = 0, cnt_C = 0, cnt_G = 0, cnt_T = 0;

        for (int j = 0; j < N; j++) {
            if (DNA[j][i] != 'A') cnt_A++;
            if (DNA[j][i] != 'C') cnt_C++;
            if (DNA[j][i] != 'G') cnt_G++;
            if (DNA[j][i] != 'T') cnt_T++;
        }

        int min = cnt_A;
        tmp[i] = 'A';

        if (cnt_C < min) {
            min = cnt_C;
            tmp[i] = 'C';
        }
        if (cnt_G < min) {
            min = cnt_G;
            tmp[i] = 'G';
        }
        if (cnt_T < min) {
            min = cnt_T;
            tmp[i] = 'T';
        }

        result += min;
    }

    tmp[M] = '\0';

    return result;
}

int main(void) {

    int N = 0, M = 0;

    scanf("%d %d", &N, &M);

    char** DNA = (char**)malloc(sizeof(char*) * N);

    for (int i = 0; i < N; i++) {
        DNA[i] = (char*)malloc(sizeof(char) * (M + 1));  
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", DNA[i], M + 1);  
    }

    char* result_DNA = (char*)malloc(sizeof(char) * (M + 1));

    int result = Get_Result(DNA, N, M, result_DNA);

    printf("%s\n", result_DNA);
    printf("%d\n", result);

    for (int i = 0; i < N; i++) {
        free(DNA[i]);
    }
    free(DNA);
    free(result_DNA);

    return 0;
}

/*
처음에는 문제를 잘못 이해해서 조금 오래 걸렸다.

1. A,C,G,T 순서로 열 기준으로 비교한다
2. 가장 작은 수의 알파벳을 tmp 배열에 넣는다.
3. 모두 끝나면 tmp배열과 최솟값의 합을 출력한다.

이렇게 풀려고 했는데 잘 된것 같다.
하지만 38번줄에 tmp[M] ='\0'; 때문에 조금 시간이 걸렸다. 
평소에는 scanf가 자동으로 NULL을 문자열 마지막에 넣어주니까 잊고 있었다.
입력하는 것이 아닌 그냥 대입한 문자열에는 문자열 끝에 NULL을 넣어주는 것을 잊지 말아야 겠다.
*/
