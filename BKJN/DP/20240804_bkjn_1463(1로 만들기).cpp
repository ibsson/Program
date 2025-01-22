#include <stdio.h>
#include <stdlib.h>

int dp[1001] = { 0 };

int main() {
    int N = 0;
    
    scanf_s("%d", &N);

    int* dp = (int*)malloc(sizeof(int) * (N + 1));

    dp[1] = 0;

    for (int x = 2; x <= N; x++) {
        int tmp = dp[x - 1] + 1;
        if (x % 2 == 0) {
            if (tmp > dp[x / 2] + 1) {
                tmp = dp[x / 2] + 1;
            }
        }

        if (x % 3 == 0) {
            if (tmp > dp[x / 3] + 1) {
                tmp = dp[x / 3] + 1;
            }
        }
        dp[x] = tmp;
    }

    printf("%d\n", dp[N]);

    return 0;
}
