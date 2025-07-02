#include <iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;

		int num = 0;
		if (n % h == 0) { num += 100 * h + n / h; }
		else { num += 100 * (n % h) + n / h + 1; }
		cout << num << endl;
	}
}
