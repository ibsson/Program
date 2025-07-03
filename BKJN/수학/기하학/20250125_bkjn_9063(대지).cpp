#include <iostream>
using namespace std; 

int main(void) {

	int N = 0;

	cin >> N;

	int x = 0, y = 0;
	int min_x = 10001, max_x = -10001, min_y = 10001, max_y = -10001;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		min_x = min(min_x, x);
		max_x = max(max_x, x);
		min_y = min(min_y, y);
		max_y = max(max_y, y);
	}

	cout << (max_x - min_x) * (max_y - min_y) << "\n";

	return 0;
}
