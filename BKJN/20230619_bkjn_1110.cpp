#include <stdio.h>

int main() {
	
	int N = 0;
	int num = 0;
	int room1 = 0;
	int room2 = 0;
	int sum = 0;
	int cnt = 0;
	
	scanf("%d", &N);
	
	num = N;
	
	while(1){
		room1 = num / 10;
		room2 = num % 10;
		sum = room1 + room2;
		num = (room2 * 10) + (sum % 10);
		cnt++;
		if(num == N){
			break;
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
