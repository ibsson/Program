#include <iostream>
using namespace std;

int main(void) {

	int T = 0, A = 0, B = 0, C = 0;

	cin >> T;

	A = T / 300;
	T %= 300;

	B = T / 60;
	T %= 60;

	C = T / 10;
	T %= 10;

	if (T != 0) cout << "-1\n";
	else cout << A << " " << B << " " << C << "\n";

	return 0;
}
