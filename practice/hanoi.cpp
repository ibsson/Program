#include <stdio.h>

void hanoi(int n, char from, char tmp, char to);


int main(void) {
	int n = 0;
	printf("원반의 개수를 입력하시오: ");
	scanf("%d", &n);
	
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void hanoi(int n, char from, char temp, char to) {
	if (n == 1) {
		printf(" 1번 원판을 %c축에서 %c축으로 옮긴다. \n", from, to);
	}
	else {
		hanoi(n - 1, from, to, temp);
		printf(" %d번 원판을 %c축에서 %c축으로 옮긴다. \n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}
