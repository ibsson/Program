#include <stdio.h>

int main(void){
	
	int x = 0;
	int y = 0;
	int tmp = 0;
	
	scanf("%d %d", &x, &y);
	
	switch(x){
		case 1:
			tmp = y;
			break;
		case 2:
			tmp = 31 + y;
			break;
		case 3:
			tmp = 31 + 28 + y;
			break;
		case 4:
			tmp = 31 + 28 + 31 + y;
			break;
		case 5:
			tmp = 31 + 28 + 31 + 30 + y;
			break;
		case 6:
			tmp = 31 + 28 + 31 + 30 + 31 + y;
			break;
		case 7:
			tmp = 31 + 28 + 31 + 30 + 31 + 30 + y;
			break;
		case 8:
			tmp = 31 + 28 + 31 + 30 + 31 + 30 + 31 + y;
			break;
		case 9:
			tmp = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + y;
			break;
		case 10:
			tmp = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + y;
			break;
		case 11:
			tmp = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + y;
			break;
		case 12:
			tmp = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + y;
			break;
	}
	
	tmp %= 7;
	
	switch(tmp){
		case 0:
			printf("SUN");
			break;
		case 1:
			printf("MON");
			break;
		case 2:
			printf("TUE");
			break;
		case 3:
			printf("WED");
			break;
		case 4:
			printf("THU");
			break;
		case 5:
			printf("FRI");
			break;
		case 6:
			printf("SAT");
			break;
	}
	
	return 0;
}
