#include <stdio.h>

int main(){
	
	char num[101];
	int N = 0;
	int sum = 0;
	
	scanf("%d", &N);
	scanf("%s", num);
	
	for(int i = 0; i < N; i++){
		num[i] -= '0'; //문자열 숫자에서 진짜 숫자로 바꿈
		sum += num[i];
	}
	
	printf("%d\n", sum);
	
	return 0;
}
