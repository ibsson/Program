#include <stdio.h>

int main() {

    int X = 0;
    int N = 0;
    int a = 0;
    int b = 0;
    int room = 0;

    scanf("%d", &X);
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        room = room + (a * b);
    }

    if (room == X) printf("Yes\n");
    if (room != X) printf("No\n");

    return 0;
}
