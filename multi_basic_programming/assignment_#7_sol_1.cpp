#include <stdio.h>

#define NUM 3

double eval(double p[], double x, int n);
double add(double f[], double g[], double h[], int n);

int main(){

    int x = 0;
   
    double p[NUM];
    double q[NUM];
    double f[NUM];


    for(int i = 0; i < NUM; i++){
        scanf("%lf", &p[i]);                  //p a0 ~ an까지 입력
    }
    for(int i = 0; i < NUM; i++){
        scanf("%lf", &q[i]);                  //q a0 ~ an까지 입력
    }

    printf("x : ");
    scanf("%d", &x);                          //x값 입력

    printf("%lf\n", eval (p, x, NUM));        //p의 값

    printf("%lf\n", eval (q, x, NUM));        //q의 값

    printf("%lf\n", add (f, p, q, NUM));      //p와 q의 합
   
    return 0;
}

double eval(double p[], double x, int n){

    double room_1 = 0;

    double tmp_x = 1;

    for (int i = 0; i < n; i++) {

        p[i]= room_1 + (p[i] * tmp_x);
        room_1 = p[i];

        tmp_x *= x;
    }

    return p[n - 1];
}

double add(double f[], double g[], double h[], int n){

    for(int i = 0; i < n; i++){
        f[i] = g[i] + h[i];
    }

    return f[n - 1];
}
