#include <stdio.h>

int main(void){
	
	int n = 0;
	int sum = 0;
	int tmp = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(n == -1) return 0;
		
		for(int i = 1; i < n; i++){
			if(n % i == 0){
				sum += i;
				tmp = i;
			}
		}
		
		if(sum == n){
			printf("%d = ", n);
			
			for(int i = 1; i < n; i++){
				if(n % i == 0){
					printf("%d", i);
					if(i == tmp){
						printf("\n");
						break;
					}
					printf(" ");
					printf("+ ");
				}
			}
		}
		else{
			printf("%d is NOT perfect.\n", n);
		}
		
		sum = 0;
	}
	
	
	
	
	return 0;
}
