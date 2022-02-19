/*
#include <stdio.h>

int main() {

    int T;
    int A[1000], B[1000];
    int room = 0;


    scanf("%d\n", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A[i], &B[i]);
        
        for (int k = 1; k <= B[i]; k++) {
            if ((A[i] * k) % B[i] == 0) {
                printf("%d\n", A[i] * k);
                break;
            }
        }
    }
    return 0;
}
*/
    
#include<stdio.h>

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {

    int T;
    int A, B;

    scanf("%d\n", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);

        if (A < B) {
            swap(&A, &B);
        }

        for (int k = 1; k <= B; k++) {
            if ((A * k) % B == 0) {
                printf("%d\n", A * k);
                break;
            }
        }
    }
    return 0;
}
