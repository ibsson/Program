#include <stdio.h>
#include <stdlib.h>

void Get_Result(int** seat, int C, int R, int K) {

    if (K > C * R) {
        printf("0\n");
        return;
    }

    int direction = 1, i = 0, num = 1, Row = R;
    int tmp = C * R;

    while (1) {
        if (direction == 1) {
            for (int j = i; j < R; j++) {
                seat[i][j] = num;

                if (num == K) {
                    printf("%d %d\n", i + 1, j + 1);
                    return;
                }
                num++;
            }
            direction = 2;
        }
        else if (direction == 2) {
            for (int j = i + 1; j < C; j++) {
                seat[j][R - 1] = num;

                if (num == K) {
                    printf("%d %d\n", j + 1, R);
                    return;
                }
                num++;
            }
            direction = 3;
        }
        else if (direction == 3) {
            for (int j = R - 2; j >= i; j--) {
                seat[C - 1][j] = num;

                if (num == K) {
                    printf("%d %d\n", C, j + 1);
                    return;
                }
                num++;
            }
            direction = 4;
        }
        else if (direction == 4) {
            for (int j = C - 2; j > i; j--) {
                seat[j][i] = num;

                if (num == K) {
                    printf("%d %d\n", j + 1, i + 1);
                    return;
                }
                num++;
            }
            i++;
            C--;
            R--;
            direction = 1;
        }
    }
}

int main(void) {
    int C = 0, R = 0, K = 0;

    scanf("%d %d", &C, &R);
    scanf("%d", &K);

    int** seat = (int**)malloc(sizeof(int*) * C);
    for (int i = 0; i < C; i++) {
        seat[i] = (int*)malloc(sizeof(int) * R);
    }

    Get_Result(seat, C, R, K);

    for (int i = 0; i < C; i++) {
        free(seat[i]);
    }
    free(seat);

    return 0;
}
