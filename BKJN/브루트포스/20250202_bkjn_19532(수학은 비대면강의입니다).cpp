#include <iostream>
using namespace std;

int a, b, c, d, e, f;

int main(void) {

	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if ((a * x) + (b * y) == c && (d * x) + (e * y) == f) {
				cout << x << " " << y << "\n";
				return 0;
			}
		}
	}
}
