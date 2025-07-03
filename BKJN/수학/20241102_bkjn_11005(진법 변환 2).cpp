#include <iostream>
using namespace std;

int main(void) {

	int N = 0, B = 0;

	cin >> N >> B;
	
	char str[30] = { 0 };
	int i = 0;

	while (N != 0) {
		if (N % B < 10) {
			str[i] = (N % B) + '0';
		}
		else if ((N % B) >= 10) {
			str[i] = (N % B) - 10 + 'A';
		}

		N /= B;
		i++;
	}

	for (int j = (i - 1); j >= 0; j--) {
		cout << str[j];
	}
	cout << endl;

	return 0;
}
