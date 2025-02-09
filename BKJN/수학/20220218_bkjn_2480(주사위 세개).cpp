/*
#include<stdio.h>

int main() {

    int a, b, c;
    int d;

    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        printf("%d",10000+(a*1000));
    }

    if (a != b && b != c && c != a) {
        if (a > b && a > c) {
            printf("%d", a * 100);
        }
        if (b > a && b > c) {
            printf("%d", b * 100);
        }
        if (c > a && c > b) {
            printf("%d", c * 100);
        }
    }

    if (a == b && b != c) {
        printf("%d", 1000 + (a * 100));
    }

    if (b == c && c != a) {
        printf("%d", 1000 + (b * 100));
    }

    if (a == c && c != b) {
        printf("%d", 1000 + (a * 100));
    }

    return 0;
}
*/


#include <stdio.h>

int get_max(int arr[], int arr_cnt) {

    int max = -2147483648;

    for (int i = 0; i < arr_cnt; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {

    int num[3];
    int choice_num;
    int cnt = 0;

    for (int i = 0; i < 3; i++) {
        scanf("%d", num + i);
    }

    for (int i = 0; i < 2; i++) {
        for (int k = i + 1; k < 3; k++) {
            if (num[i] == num[k]) {
                cnt++;
                choice_num = num[i];
            }
        }
    }

    switch (cnt) {
    case 0:
        choice_num = get_max(num, sizeof(num) / sizeof(int));
        printf("%d\n", choice_num * 100);
        break;
    case 1:
        printf("%d\n", 1000 + (choice_num * 100));
        break;
    case 3:
        printf("%d\n", 10000 + (choice_num * 1000));
        break;
    default:
        break;
    }

    return 0;
}
