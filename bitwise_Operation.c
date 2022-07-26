#include <stdio.h>

char arr[10000001] = { 0, };

void print_bin(char value)
{
	int i = 0;

	printf("10진수 %d, 2진수 ", value);
	for (i = 7; i >= 0; i--) {
		printf("%d", (value >> i) & 1);
	}
	printf("\n");
}

int get_bin(int position) {
	int quotient;
	int remainder;
	int tmp = 128;

	quotient = (int)(position / 8);
	remainder = (int)(position % 8);

	printf("%d 째 블럭, %d 칸\n", quotient, remainder);

	tmp = tmp >> remainder;

	if ((arr[quotient] & tmp) > 0)
		return 1;

	return 0;
}

int set_bin_0(int position) {

	int quotient;
	int remainder;
	int tmp = 128;

	quotient = (int)(position / 8);
	remainder = (int)(position % 8);

	printf("%d 째 블럭, %d 칸\n", quotient, remainder);

	tmp = tmp >> remainder;

	arr[quotient] &= ~tmp;

	return arr[quotient];
}

int set_bin_1(int position) {
	int quotient;
	int remainder;
	int tmp = 128;

	quotient = (int)(position / 8);
	remainder = (int)(position % 8);

	printf("%d 째 블럭, %d 칸\n", quotient, remainder);

	tmp = tmp >> remainder;

	arr[quotient] |= tmp;

	return arr[quotient];
}

int set_bin_xor(int position) {
	int quotient;
	int remainder;
	int tmp = 128;

	quotient = (int)(position / 8);
	remainder = (int)(position % 8);

	printf("%d 째 블럭, %d 칸\n", quotient, remainder);

	tmp = tmp >> remainder;

	arr[quotient] ^= tmp;

	return arr[quotient];
}

int main() {

	int position;
	int select;

	for (int i = 0; i <= 1000000; i++) {
		arr[i] = i;
	}

	for (;;) {
		printf("선택할 bit 자리 번호 입력 : ");
		scanf_s("%d", &position);

		if (position < 0 || 1000000 < position) {
			break;	//입력 종료
		}

		printf("%d 째 블럭 %d 칸, 원래 숫자 : ", (int)(position / 8), (int)(position % 8));
		print_bin(arr[(int)(position / 8)]);

		printf("\n선택하세요.\n비트값을 0 으로 바꾸기 : 0\n비트값을 1 로 바꾸기 : 1\n비트값을 0 -> 1, 1 -> 0 바꾸기(xor) : 2\n비트값 찾기 : 3\n");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			printf("%d 자리의 비트값을 0로 바꿉니다.\n", position);
			print_bin(set_bin_0(position));
			break;

		case 1:
			printf("%d 자리의 비트값을 1로 바꿉니다.\n", position);
			print_bin(set_bin_1(position));
			break;

		case 2:
			printf("%d 자리의 비트값 : 0 -> 1, 1 -> 0 으로 바꿉니다(xor).\n", position);
			print_bin(set_bin_xor(position));
			break;

		case 3:
			printf("%d 자리에 2진수 : %d\n", position, get_bin(position));
			break;

		default:
			break;
		}

		printf("\n");
	}


	return 0;
}
