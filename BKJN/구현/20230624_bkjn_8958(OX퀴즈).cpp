#include <stdio.h>

char room[81];

int get_len(){
	
	int len = 0;
	
	for(int i = 0; i < 81; i++){
		if(room[i] == '\0'){
			break;
		}
		len++;
	}
	
	return len;
}

int main() {
	
	int T = 0;
	int score = 0;
	int plus = 1;
	int len = 0;
	
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		scanf("%s", room);
		
		plus = 1;
		score = 0;
		len = get_len();
		
		for(int k = 0; k < len; k++){
			if(room[k] == 'X'){
				plus = 1;
			}
			else if(room[k] == 'O'){
				score += plus;
				plus++;
			}
		}
		
		printf("%d\n", score);
		
		for(int i = 0; i < len; i++){
			room[i] = 0;
		}
	}
	
	return 0;
}
