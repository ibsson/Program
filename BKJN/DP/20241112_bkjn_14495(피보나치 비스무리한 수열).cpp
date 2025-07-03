#include <iostream>
using namespace std;

int main(void) {

	int n = 0;

	cin >> n;

	long long int pibo[114] = { 0 };
	pibo[1] = 1, pibo[2] = 1, pibo[3] = 1;

	for (int i = 4; i <= n; i++) {
		pibo[i] = pibo[i - 1] + pibo[i - 3];
	}

	cout << pibo[n] << endl;

	return 0;
}
