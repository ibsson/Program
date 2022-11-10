#include <stdio.h>

int main(){

    int room[9][9] = {0};
    int num1 = 0;
    int num2 = 0;

    for(int i = 0; i < 9; i++){
        for(int k = 0; k < 9; k++){
            scanf("%d", &room[i][k]);
        }
    }

    int shelter = room[0][0];

    for(int i = 0; i < 9; i++){
        for(int k = 0; k < 9; k++){
            if(shelter <= room[i][k]){
                shelter = room[i][k];
                num1 = i+1;
                num2 = k+1;
            }
        }
    }

    printf("%d\n", shelter);
    printf("%d %d", num1, num2);

    return 0;
}
