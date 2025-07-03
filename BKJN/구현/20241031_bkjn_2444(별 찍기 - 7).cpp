#include <iostream>
using namespace std;

int main(void) {

	int N = 0, a = 1,  tmp = 1;

	cin >> N;

	for (int i = 0; i < (N * 2) - 1; i++) {
		for (int j = 0; j < (N - a); j++) {
			cout << " ";
		}

		for (int j = 0; j < tmp; j++) {
			cout << "*";
		}
		cout << endl;

		if (i < (N - 1)) {
			tmp += 2;
			a++;
		}
		else {
			tmp -= 2;
			a--;
		}
	}

	return 0;
}
