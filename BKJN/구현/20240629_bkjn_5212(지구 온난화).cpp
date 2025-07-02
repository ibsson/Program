#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int R = 0, C = 0;
    char map[20][20] = { 0 };
    char new_map[20][20] = { 0 };

    scanf("%d %d", &R, &C);
    getchar();

    for (int i = 0; i < R; i++) {
        fgets(map[i], C + 2, stdin);
        map[i][C]= '\0';
    }

    memcpy(new_map, map, sizeof(map));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'X') {
                int cnt = 0;
                if (i == 0 || map[i - 1][j] == '.') cnt++;
                if (i == R - 1 || map[i + 1][j] == '.') cnt++;
                if (j == 0 || map[i][j - 1] == '.') cnt++;
                if (j == C - 1 || map[i][j + 1] == '.') cnt++;

                if (cnt >= 3) {
                    new_map[i][j] = '.';
                }
            }
        }
    }

    int min_C = C, max_C = -1, min_R = R, max_R = -1;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (new_map[i][j] == 'X') {
                if (min_R > i) min_R = i;
                if (max_R < i) max_R = i;
                if (min_C > j) min_C = j;
                if (max_C < j) max_C = j;
            }
        }
    }

    if (min_C == C && max_C == -1 && min_R == R && max_R == -1) {
        printf("X\n");
    } else {
        for (int i = min_R; i <= max_R; i++) {
            for (int j = min_C; j <= max_C; j++) {
                printf("%c", new_map[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
