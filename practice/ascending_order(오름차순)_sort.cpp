#include <stdio.h>

int main(){

    int num[5] = {0};
    int room = 0;

    for(int i = 0; i < 5; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < 5; i++){
        for(int k =i; k < 5; k++){
            if(num[i] < num[k]){
                room = num[i];
                num[i] = num[k];
                num[k] = room;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", num[i]);
    }

    return 0;
}
