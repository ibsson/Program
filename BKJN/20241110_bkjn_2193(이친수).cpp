#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	long long int pibo[91] = { 0 };

	cin >> N;

	pibo[0] = 1, pibo[1] = 1;

	for (int i = 2; i < N; i++) {
		pibo[i] = pibo[i - 1] + pibo[i - 2];
	}

	cout << pibo[N - 1] << "\n";

	return 0;
}
