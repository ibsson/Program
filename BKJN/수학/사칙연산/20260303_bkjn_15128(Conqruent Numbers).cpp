#include <iostream>
using namespace std;

int main(void) {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	long long num1 = a * c;
	long long num2 = 2 * b * d;

	if (!(num1 % num2)) cout << "1\n";
	else cout << "0\n";

	return 0;
}
