#include <iostream>
using namespace std;

int main(void) {

	int A = 0, B = 0;

	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0) break;

		int tmp = 0;
		if (A > B) {
			if (A % B == 0) cout << "multiple" << endl;
			else cout << "neither" << endl;
		}
		else if (A < B) {
			if (B % A == 0) cout << "factor" << endl;
			else cout << "neither" << endl;
		}
	}

	return 0;
}
