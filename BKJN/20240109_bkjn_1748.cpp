//시간초과 fail

#include <stdio.h>

int main(void){
	
	int N = 0;
	int cnt = 1;
	int result = 0;
	
	scanf("%d", &N);
	
	while(cnt <= N){
		
		if(cnt < 10) result += 1;
		else if(cnt < 100) result += 2;
		else if(cnt < 1000) result += 3;
		else if(cnt < 10000) result += 4;
		else if(cnt < 100000) result += 5;
		else if(cnt < 1000000) result += 6;
		else if(cnt < 10000000) result += 7;
		else if(cnt < 100000000) result += 8;
		else result += 9;
		
		cnt++;
	}
	
	printf("%d\n", result);
	
	return 0;
}
