/*
#include<stdio.h>

int main() {
 
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    if (b + c < 60) {
        printf("%d %d\n", a, b + c);
    }
    else if (b + c >= 60) {
        int d = b + c;
        if (a + (d / 60) < 24) {
            printf("%d %d\n", a + d / 60, d % 60);
        }
        else if (a + (d / 60) >= 24) {
            printf("%d %d\n", a + d / 60 - 24, d % 60);
        }
    }
    return 0;
}
*/

#include <stdio.h>

int main() {

	int now_hour, now_minute;
	int cooking_time;

	int tmp;

	scanf("%d %d %d", &now_hour, &now_minute, &cooking_time);

	tmp = now_hour * 60 + now_minute + cooking_time;

	now_hour = ( (int)(tmp / 60) ) % 24;
	now_minute = tmp % 60;

	printf("%d %d\n", now_hour, now_minute);

	return 0;
}
