#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {

	int a[3] = { 0 };

	while (1) {
		cin >> a[0] >> a[1] >> a[2];

		if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;

		sort(a, a + 3, compare);

		if (a[0] >= a[1] + a[2]) cout << "Invalid\n";
		else if (a[0] == a[1] && a[1] == a[2]) cout << "Equilateral\n";
		else if (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) cout << "Scalene\n";
		else cout << "Isosceles\n";
	}

	return 0;
}
