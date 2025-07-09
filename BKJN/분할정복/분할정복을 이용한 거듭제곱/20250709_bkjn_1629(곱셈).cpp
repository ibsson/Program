#include <iostream>
using namespace std;

int cal(long long int A, int B, int C) {
	long long int res = 1;

	while (B > 0) {
		if (B % 2 == 1) {
			res *= (A % C);
			res %= C;
		}
		A *= (A % C);
		A %= C;
		B = B / 2;
	}

	return res;
}

int main() {
	long long int A;
	int B, C;
	cin >> A >> B >> C;

	cout << cal(A, B, C) << '\n';

	return 0;
}
