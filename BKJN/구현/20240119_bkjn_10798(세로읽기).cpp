#include <stdio.h>

int main(void){
	
	char word[5][15] = { 0 }; //초기화를 해주면 문자열 끝에 null이 들어가도 null뒤에 0으로 초기화 되어있기 때문에 쓰레기값이 들어가 있지 않음
	
	for(int i = 0; i < 5; i++){
		scanf("%s", word[i]);
	}
	
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 5; j++){
			if(word[j][i] == NULL) continue;
			else printf("%c", word[j][i]);
		}
	}
	
	return 0;
}
