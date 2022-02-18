#include<stdio.h>

int main() {
 
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    if (b + c < 60) {
        printf("%d %d\n", a, b + c);
    }
    else if (b + c >= 60) {
        int d = b + c;
        if (a + (d / 60) < 24) {
            printf("%d %d\n", a + d / 60, d % 60);
        }
        else if (a + (d / 60) >= 24) {
            printf("%d %d\n", a + d / 60 - 24, d % 60);
        }
    }
    return 0;
}
