#include <stdio.h>

int main(){

    int array[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int room1[2] = {0};
    int room2[3] = {0}; 

    for(int i = 0; i < 2; i++){
        for(int k = 0; k < 3; k++){
            room1[i] += array[i][k];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 2; k++){
            room2[i] += array[k][i];
        }
    }

    for(int i = 0; i < 2; i++){
        printf("%d행의 합계: %d\n", i, room1[i]); 
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%d열의 합계: %d\n", i, room2[i]);
    }

    return 0;
}
