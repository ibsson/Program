#include <stdio.h>

int main() {
	
	int N = 0;
	int a = 2;
	
	scanf("%d", &N);
	
	int tmp = N;
	
	for(int i = 0; i < tmp; i++){
		if(N % a == 0){
			N /= a;
			printf("%d\n", a);
		}
		else {
			a++;
		}
		
		if(N == 1) break;
	}
	
	return 0;
}
