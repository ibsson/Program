#include <stdio.h>

int main(){
    int burger[3], drink[2], price = 0;
    scanf("%d %d %d", &burger[0], &burger[1], &burger[2]);
    scanf("%d %d", &drink[0], &drink[1]);
    
    if(burger[0]<=burger[1] && burger[0]<=burger[2]){
        price += burger[0];
    }
    else if(burger[1]<=burger[2] && burger[1]<=burger[0]){
        price += burger[1];
    }
    else{
        price += burger[2];
    }
    
    if(drink[0]<=drink[1]){
        price += drink[0]; 
    }
    else{
        price += drink[1];
    }
    
    printf("%d", price-50);
    return 0;
}
