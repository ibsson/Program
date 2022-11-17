#include <stdio.h>

int main(){
    
    int num = 0;
    
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
        if(i == 0){
            printf("int a;\n");
            printf("int *ptr = &a;\n");
        }
        if(i > 0){
            printf("int ");
            for(int k = 0; k <= i; k++){
                printf("*");
                if(k == i){
                    if(k == 1){
                        printf("ptr%d = &ptr;\n", k+1);
                    }
                    else{
                        printf("ptr%d = &ptr%d;\n", k+1, k);
                    }
                }
            }
        }
        
    }
   
    return 0;
}
