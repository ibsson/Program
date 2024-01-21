#include <stdio.h>

int main(void){
	
	int A = 0;
	int B = 0;
	int tmp = 1;
	int cnt = 1;
	int num = 0;
	
	scanf("%d %d", &A, &B);
	
	while(1){
		for(int i = 1; i <= tmp; i++){
			
			if(cnt >= A && cnt <= B){
				num += tmp;
			}
			
			if(cnt == B){
				printf("%d\n", num);
				
				return 0;
			}
			
			cnt++;
		}
		tmp++;
	}
	
	return 0;
}
