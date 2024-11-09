#include <iostream>
using namespace std;

int main(void) {

	int N = 0;

	cin >> N;

	int k = 2, tmp = 1;

	for (int i = 1; i <= N; i++) {
		k += tmp;
		tmp += tmp;
	}

	cout << k * k << endl;

	return 0;
}
