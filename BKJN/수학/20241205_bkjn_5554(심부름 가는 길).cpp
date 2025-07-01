#include <stdio.h>

int main(void) {
    int time = 0;
    for (int i=0; i<4; i++) {
        int a;
        scanf("%d", &a);
        time += a;
    }
    printf("%d\n", time/60);
    printf("%d", time%60);
}
