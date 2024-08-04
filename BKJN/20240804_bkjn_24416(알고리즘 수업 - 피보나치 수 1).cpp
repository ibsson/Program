#include <stdio.h>
#include <stdlib.h>

int fibo[51] = { 0 };
int cnt_1 = 0;

int fib(int n) {

    if (n == 1 || n == 2) {
        cnt_1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int main(void) {

    int n = 0;
    int arr[2] = { 0 };

    scanf("%d", &n);

    int a = fib(n);

    printf("%d %d\n", cnt_1, (n - 2));

	return 0;
}

/*
이 문제는 문제에 나온 그대로 풀면 되는 문제였다.
*/
