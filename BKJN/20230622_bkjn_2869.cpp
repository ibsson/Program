#include <stdio.h>

int main(){
    
    int A = 0;
    int B = 0;
    int V = 0;
    int cnt = 0;
    
    scanf("%d %d %d", &A, &B, &V);
    
    if((V - B) % (A - B) == 0){  //높이를 딱 맞춰서 올라갈때  V = day*(A-B)+B
        cnt = (V - B) / (A - B);
    }
    else if((V - B) % (A - B) != 0){  //높이를 넘어갈때
        cnt = (V - B) / (A - B) + 1;
    } 
    
    printf("%d\n", cnt);
    
    return 0;   
}
