#include <stdio.h>

int N;
int T[16], P[16];
int max_profit = 0;

void backtrack(int day, int current_profit) {
    if (day == N + 1) {
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
        return;
    }

    backtrack(day + 1, current_profit);

    if (day + T[day] - 1 <= N) {
        backtrack(day + T[day], current_profit + P[day]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    backtrack(1, 0);

    printf("%d\n", max_profit);
    return 0;
}

/*
이 문제는 백트래킹으로 풀었다.
오랜만에 백트래킹 문제를 푸니 어떻게 만들지는 구상이 되는데 실제로 재귀함수로 코드로 만드는데 살짝 버벅거렸다.
계속 쉽게 만들 수 있도록 복습을 해야겠다는 생각이 들었다.
*/
