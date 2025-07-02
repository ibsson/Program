#include <stdio.h>

int main(void) {

    int average = 0;
    int score[5] = { 0 };

    for (int i = 0; i < 5; i++) {
        scanf("%d", &score[i]);

        if (score[i] < 40) score[i] = 40;

        average += score[i];
    }

    average /= 5;

    printf("%d\n", average);

    return 0;
}
