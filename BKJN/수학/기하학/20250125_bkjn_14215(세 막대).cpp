#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {

	int a[3] = { 0 };

	cin >> a[0] >> a[1] >> a[2];

	sort(a, a + 3, compare);

	while (1) {
		if (a[0] >= a[1] + a[2]) {
			a[0]--;
		}
		else {
			cout << a[0] + a[1] + a[2] << "\n";
			break;
		}
	}

	return 0;
}
