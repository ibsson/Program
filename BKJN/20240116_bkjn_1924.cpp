//배열 사용

#include <stdio.h>

int main(void){
	
	int x = 0;
	int y = 0;
	int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int tmp = 0;
	
	scanf("%d %d", &x, &y);
	
	for(int i = 0; i < (x - 1); i++){
		tmp += day[i];
	}
	
	tmp += y;
	
	tmp %= 7;
	
	switch(tmp){
		case 0:
			printf("SUN\n");
			break;
		case 1:
			printf("MON\n");
			break;
		case 2:
			printf("TUE\n");
			break;
		case 3:
			printf("WED\n");
			break;
		case 4:
			printf("THU\n");
			break;
		case 5:
			printf("FRI\n");
			break;
		case 6:
			printf("SAT\n");
			break;
	}
	
	return 0;
}

//첫번째로 만든 코드

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
