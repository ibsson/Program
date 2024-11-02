#include <iostream>
using namespace std;

int main(void) {

	int T = 0;

	cin >> T;

	int change = 0;
	int Q = 0, D = 0, N = 0, P = 0;

	for (int i = 0; i < T; i++) {
		cin >> change;

		Q = change / 25;
		change %= 25;

		D = change / 10;
		change %= 10;

		N = change / 5;
		change %= 5;

		P = change / 1;
		change %= 1;

		cout << Q << " " << D << " " << N << " " << P << endl;

		Q = 0, D = 0, N = 0, P = 0;
	}

	return 0;
}
