#include <stdio.h>

int main() {

	char cro[101];
	int count = 0;

	scanf_s("%s", cro, 101);

	for (int i = 0; i < 101; i++) {
		if (cro[i] == 0) {
			break;
		}
		count++;
	}

	int cnt = count;
	
	for (int i = count; i > 0; i--) {
		if (cro[i] == '=') {
			if (cro[i - 1] == 'c') count--;
			if (cro[i - 1] == 's') count--;
			if (cro[i - 1] == 'z') {
				count--;
				if (cro[i - 2] == 'd') {
					count--;
				}
			}
		}
		if (cro[i] == '-') {
			if (cro[i - 1] == 'd') count--;
			if (cro[i - 1] == 'c') count--;
		}
		if (cro[i] == 'j') {
			if (cro[i - 1] == 'l') count--;
			if (cro[i - 1] == 'n') count--;
		}
	}

	printf("%d\n", count);

	return 0;
}
