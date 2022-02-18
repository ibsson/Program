
#include<stdio.h>
2
​
3
int main() {
4
​
5
    int a, b, c;
6
    int d;
7
​
8
    scanf("%d %d %d", &a, &b, &c);
9
​
10
    if (a == b && b == c) {
11
        printf("%d",10000+(a*1000));
12
    }
13
    if (a != b && b != c && c != a) {
14
        if (a > b && a > c) {
15
            printf("%d", a * 100);
16
        }
17
        if (b > a && b > c) {
18
            printf("%d", b * 100);
19
        }
20
        if (c > a && c > b) {
21
            printf("%d", c * 100);
22
        }
23
    }
24
    if (a == b && b != c) {
25
        printf("%d", 1000 + (a * 100));
26
    }
27
    if (b == c && c != a) {
28
        printf("%d", 1000 + (b * 100));
29
    }
30
    if (a == c && c != b) {
31
        printf("%d", 1000 + (a * 100));
32
    }
33
​
34
    return 0;
35
}
