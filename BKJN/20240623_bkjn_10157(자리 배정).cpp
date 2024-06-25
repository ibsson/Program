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

    for (int i = 0; i < R; i++) {
        free(seat[i]);
    }
    free(seat);

    return 0;
}

/*
접근은 이렇게 하려고 했다.

1. 2차원 배열에 시계방향으로 숫자를 넣는다 (방향별로 루프 설정)
2. 다 넣은 후 K값을 찾으면 값을 출력한다

이렇게 하려고 했는데 표를 뒤집어서 반시계 방향으로 하면 더 직관적으로 보인다는 것을 알게 되어서 반시계 방향으로 위에서 부터 넣는 방법을 이용했다.
그리고 표에 다 넣고 K값을 찾으려고 했는데 그냥 넣은 직후 K값과 같으면 출력하면 더 빠른 코드가 될거라고 생각해서 넣은 직후 K값과 비교해서 출력했다.

처음에는 시계방향으로 문제에 주어진 표 그대로 하려 해서 좀 많이 헷갈렸다. 하지만 이 문제에서 조금 바꿔서 풀었더니 헷갈리지 않고 더 쉽게 풀렸다.
무조건 문제에 주어진 그대로가 아닌, 다른 방법으로 조금 바꿔서 푸는 방법이 더 쉬울수도 있다는 것을 느낄수 있었다.
*/
