#include <stdio.h>

char file[50][51] = { 0 }; //전역변수 배열은 0으로 초기화 되지만 초기화는 해주자
char result[50] = { 0 };

int get_len(void){
	
	int len = 0;
	
	for(int i = 0; i < 51; i++){
		if(file[0][i] == NULL) return len;
		
		len++;
	}
	
	return len;
}

void check(int N, int len){
	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < len; j++){
			if(file[0][j] != file[i][j]){
				result[j] = '?';
			}
		}
	}
}

int main(void){
	
	int N = 0;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%s", file[i]);
	}
	
	int len = get_len();
	
	for(int i = 0; i < len; i++){
		result[i] = file[0][i];
	}
	
	check(N, len);
	
	printf("%s", result);
	
	return 0;
}
