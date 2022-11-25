#include <stdio.h>

#define NUM 5

double eval(double p[], double x, int n);
double add(double f[], double g[], double h[], double x, int n);

int main() {

    int x = 0;

    double p[NUM];
    double q[NUM];
    double f[NUM];

    for (int i = 0; i < NUM; i++) {
        printf("input a-%d : ", i);
        scanf("%lf", &p[i]);                  //p a0 ~ an까지 입력
        if (p[i] > 100000 || p[i] < -100000) { // 입력 받은 수가 -100000 보다 작거나, 100000 보다 크면 다시 입력 받음
            printf("re-input : \n");
            i--;
        }
    }

    for (int i = 0; i < NUM; i++) {
        printf("input b-%d : ", i);
        scanf("%lf", &q[i]);                  //q a0 ~ an까지 입력
        if (q[i] > 100000 || q[i] < -100000) { // 입력 받은 수가 -100000 보다 작거나, 100000 보다 크면 다시 입력 받음
            printf("re-input : \n");
            i--;
        }
    }

    printf("input x : ");
    scanf("%d", &x);                         //x값 입력

    printf("%lf\n", eval(p, x, NUM));        //p의 값

    printf("%lf\n", eval(q, x, NUM));        //q의 값

    printf("%lf\n", add(f, p, q, x, NUM));   //p와 q의 합

    return 0;
}

double eval(double p[], double x, int n) {

    double room_1 = 0;

    double tmp_x = 1;

    for (int i = 0; i < n; i++) {

        room_1 += (p[i] * tmp_x);

        tmp_x *= x;
    }

    return room_1;
}

double add(double f[], double g[], double h[], double x, int n) {

    double tmp = 0;

    for (int i = 0; i < n; i++) {
        f[i] = eval(g, x, i + 1) + eval(h, x, i + 1);
    }

    return f[n - 1];
}
