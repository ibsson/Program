#include <stdio.h>

int main(){

    int num_1[100][100] = {0};
    int num_2[100][100] = {0};
    int result[100][100] = {0};
    int choice[2] ={0};

    for(int i = 0; i < 2; i++){
        scanf("%d", &choice[i]);
    }

    for(int i = 0; i < choice[0]; i++){
        for(int k = 0; k < choice[1]; k++){
            scanf("%d", &num_1[i][k]);
        }
    }

    for(int i = 0; i < choice[0]; i++){
        for(int k = 0; k < choice[1]; k++){
            scanf("%d", &num_2[i][k]);
        }
    }

    for(int i = 0; i < choice[0]; i++){
        for(int k = 0; k < choice[1]; k++){
            result[i][k] = num_1[i][k] + num_2[i][k];
        }
    }

    for(int i = 0; i < choice[0]; i++){
        for(int k = 0; k < choice[1]; k++){
            printf("%d ", result[i][k]);
        }
        printf("\n");
    }

    return 0;
}
