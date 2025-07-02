#include <stdio.h>

int main(void) {

    int N = 0, fac = 1;

    scanf("%d", &N);

    if (N == 0) {
        printf("1\n");
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        fac *= i;
    }

    printf("%d\n", fac);

    return 0;
}
