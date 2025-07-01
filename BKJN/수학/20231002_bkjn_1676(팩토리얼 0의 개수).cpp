#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int N = 0;
	int cnt_5 = 0;
	int cnt_25 = 0;
	int cnt_125 = 0;
	int *num;
	
	scanf("%d", &N);
	
	num = (int *)malloc((N + 1) * sizeof(int));
	
	for(int i = 1; i <= N; i++){
		num[i] = i;
	}
	
	for(int i = 1; i <= N; i++){
		
		if(num[i] % 5 == 0){
			cnt_5++;
		}
	}
	
	for(int i = 1; i <= N; i++){
		
		if(num[i] % 25 == 0){
			cnt_25++;
		}
	}
	
	for(int i = 1; i <= N; i++){
		
		if(num[i] % 125 == 0){
			cnt_125++;
		}
	}
	
	printf("%d\n", cnt_5 + cnt_25 + cnt_125);
	
	free(num);
	
	return 0;
}
