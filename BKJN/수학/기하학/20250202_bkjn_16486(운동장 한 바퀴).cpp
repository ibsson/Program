#include <iostream>
using namespace std;

#define PI 3.141592

int main() {

	double d1 = 0.0, d2 = 0.0;
	
	cin >> d1;
	cin >> d2;

	double result = (2 * d1) + (PI * 2 * d2);

	cout << fixed;
	cout.precision(6);
	cout << result << "\n";

	return 0;
}
