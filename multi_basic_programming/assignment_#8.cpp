#include <stdio.h>

void swap1(int a, int b);
void swap2(int* a, int* b);
void swap3(int* a, int* b);

int main(void){

    int p = 0;
    int q = 0;

    printf("p = ");
    scanf("%d", &p);

    printf("q = ");
    scanf("%d", &q);

    swap1(p, q);
    printf("p = %d q = %d\n", p, q);

    swap2(&p, &q);
    printf("p = %d q = %d\n", p, q);
    
    swap3(&p, &q);
    printf("p = %d q = %d\n", p, q);

    return 0;
}

void swap1(int a, int b){

    int temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int* b){

    int* temp = a;
    a = b;
    b = temp;
}

void swap3(int* a, int* b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
}
