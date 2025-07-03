#include <iostream>
using namespace std;

#define PI 3.1415926535897932

int main(void) {
	double r = 0.0;

	cin >> r;

	cout << fixed;
	cout.precision(6);

	cout << r * r * PI << "\n";
	cout << 2 * r * r << "\n";

	return 0;
}
