#include<stdio.h>

int room[15][15] = {0};

int main(){
	
	int T, k, n = 0;
	
	scanf("%d", &T);
	
	for(int i = 0; i < 15; i++){
		room[i][0] += 1;
	}
	
	for(int i = 1 ; i < 15; i++){
		room[0][i] = (i + 1);
	}
	
	for(int i = 0; i < T; i++){
		
		scanf("%d", &k);
		scanf("%d", &n);
		
		for(int a = 1; a <= k; a++){
			for(int b = 1; b < n; b++){
				room[a][b] = room[a][b - 1] + room[a - 1][b];	
			}
		}
		
		printf("%d\n", room[k][n - 1]);
	}
	
	return 0;
}
