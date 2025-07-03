#include <iostream>
using namespace std;

int main(void) {

	long long int X = 0, Y = 0;

	cin >> X >> Y;

	int i = 0;
	int ori = Y * 100 / X;

	if (ori >= 99) {
		cout << "-1\n";
		return 0;
	}

	int left = 0, right = 1000000000, mid = 0, result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long int tmp = ((Y + mid) * 100) / (X + mid);

		if (tmp > ori) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << result << endl;

	return 0;
}
