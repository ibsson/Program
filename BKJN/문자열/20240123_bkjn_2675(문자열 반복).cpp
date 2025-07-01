#include <stdio.h>

char S[21];

int get_len(){
	
	int cnt = 0;
	
	for(int i = 0; i < 21; i++){
		
		if(S[i] == NULL) return cnt;
		
		cnt++;
	}
}

int main(void){
	
	int T = 0;
	int R = 0;
	
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		
		scanf("%d %s", &R, S);
		
		int len = get_len();
		
		for(int j = 0; j < len; j++){
			for(int k = 0; k < R; k++){
				printf("%c", S[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
