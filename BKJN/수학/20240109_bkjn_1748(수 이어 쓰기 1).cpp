#include <stdio.h>
#include <math.h>

int countDigits(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    int result = 0;
    int digits = countDigits(N);

    for (int i = 1; i < digits; i++) {
        result += i * (9 * pow(10, i - 1));
    }

    result += digits * (N - pow(10, digits - 1) + 1);

    printf("%d\n", result);

    return 0;
}

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
