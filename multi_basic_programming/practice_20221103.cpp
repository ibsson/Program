#include <stdio.h>

int main(){

    int num[8] = {0};
    int room[10] = {0};

    for(int i = 0; i < 8; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 1; i <= 10; i++){
        for(int k = 0; k < 8; k++){
            if(num[k] == i){
                room[i-1]++;
                break;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        if(room[i] == 0){
            printf("%d ", (i+1));
        }
    }
            

    return 0;
}
