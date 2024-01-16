#include <stdio.h>

int get_len(int num){
	
	int len = 0;
	
	while(1){
		if(num == 0) break;
		
		num /= 10;
		
		len++;
	}
	
	return len;
}

int main(void){
	
	int num = 0;
	int room = 0;
	int len = 0;
	int tmp = 0;
	int cnt = 0;
	int result = 0;
	
	while(1){
		scanf("%d", &num);
		
		room = num;
		
		if(num == 0) return 0;
		
		len = get_len(num);
		cnt = len;
		
		
		for(int i = 0; i < len; i++){
			tmp = room % 10;
			
			for(int i = cnt; i > 1; i--){
				tmp *= 10;
			}
			result += tmp;
			
			room /= 10;
			
			cnt--;
		}
		
		if(result == num) printf("yes\n");
		else if(result != num) printf("no\n");
		
		result = 0;
	}
	
	
	return 0;
}
