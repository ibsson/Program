#include <stdio.h>

int main() {
	
	int X = 0;
	int k = 1;
	
	scanf("%d", &X);
	
	while(1){
		if((k-1)*(k)/2 < X && (k)*(k+1)/2 >= X){
			break;
		}
		k++;
	}
	
	if(k % 2 == 0){
		int a = k*(k+1)/2;
		printf("%d/", k - (a - X));
		printf("%d", a - X + 1);
	}
	else{
		int a = k*(k+1)/2;
		printf("%d/", a - X + 1);
		printf("%d", k - (a - X));
	}
	
	return 0;
}
